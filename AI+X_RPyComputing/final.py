import pandas as pd
from bs4 import BeautifulSoup
from pandas.core.reshape.merge import merge
import requests
from sklearn.linear_model import LinearRegression
import seaborn as sns
import matplotlib as plt
import statsmodels.api as sm
from statsmodels.stats.outliers_influence import variance_inflation_factor

# 웹크롤링 시작
url = "https://fbref.com/en/comps/9/Premier-League-Stats"
page = requests.get(url = url)
soup = BeautifulSoup(page.text, 'html.parser')

# main table 생성 -> 순위에 관한 기본 정보
main_table = soup.find("table", {"id" : "results107281_overall"})

for i in main_table.find_all('thead') :
    title = i.find_all('th')
    row_title = [th.text for th in title]

main_df = pd.DataFrame(columns = row_title)

for j in main_table.find_all('tr')[1:] :
    rank = j.find_all('th')
    data = j.find_all('td')
    row_rank = [th.text for th in rank]
    row_data = [tr.text for tr in data]
    row = row_rank + row_data
    new_row = []
    for a in row :
        a = a.strip()
        new_row.append(a)
    length = len(main_df)
    main_df.loc[length] = new_row

# print(main_df)
# main_df.to_csv("main_df.csv")

# pos table 생성 -> 점유율에 관한 세부적인 수치
pos_table = soup.find("table", {"id" : "stats_squads_possession_for"})

for i in pos_table.find_all('thead') :
    title = i.find_all('th')
    row_title = [th.text for th in title]
    
row_title = row_title[6:]

pos_df = pd.DataFrame(columns = row_title)

for j in pos_table.find_all('tr')[2:] :
    rank = j.find_all('th')
    data = j.find_all('td')
    row_rank = [th.text for th in rank]
    row_data = [tr.text for tr in data]
    row = row_rank + row_data
    length = len(pos_df)
    pos_df.loc[length] = row

# print(pos_df)
# pos_df.to_csv("pos_df.csv")

# 2개의 데이터프레임 합치기 / 기준열 = Squad(팀명)
total_df = pd.merge(main_df, pos_df, left_on="Squad", right_on="Squad", how="inner")

# print(total_df)
# total_df.to_csv("total_df.csv")

# 승률 열을 추가 (백분율 단위) -> 모든 모형의 종속변수로 활용
# 데이터 타입을 전부 숫자형으로 변경, 문자형 데이터는 팀이름, 선수명, 메모 등으로 분석에 있어서 필요하지 않을 것으로 판단하여 결측치 처리
total_df = total_df.apply(pd.to_numeric, errors="coerce").fillna("NaN")
wins = total_df["W"].tolist()

win_rate = []
for i in range(len(wins)) :
    x = round(wins[i] / 38 * 100, 1)
    win_rate.append(x)
total_df['Win Rate'] = win_rate

# print(total_df)

# 각 요소 간 상관관계 파악 -> 피어슨 상관계수 값으로 비교
corr = total_df.corr(method = "pearson")[["Win Rate"]]

# 절대값이 0.7이상인 요소만 강한 상관관계를 가지고 있다고 판단
strong_corr = abs(corr["Win Rate"]) >= 0.7
subset_df = corr[strong_corr]

# # 승률과 강한 상관관계를 가지고 있는 21개의 요소 추출 / 이 중 당연한 요소인 등수, 승, 패, 승점과 자기 자신인 승률은 제외 후 16개의 요소를 가지고 단순회귀분석을 진행
# # 16개의 요소를 1) 골 관련 지표, 2) 점유 관련 지표으로 나누어서 다중회귀분석 진행

# 첫번째 모델 - 골 관련 지표
Z = total_df[['GF','GA','GD','xG','xGD','xGD/90']]
Y = total_df['Win Rate']
model1 = sm.OLS(Y, Z)
res1 = model1.fit()
# print(res1.summary())

# 유의수준 5%에서 GA, xG가 통계적으로 유의미하지 않음을 확인
# 다중공선성을 확인하기 위해 VIF를 계산
vif1 = pd.DataFrame({'factor': column, 'VIF': variance_inflation_factor(model1.exog, i)} 
             for i, column in enumerate(model1.exog_names)
             if column != 'Intercept')

# print(vif1)

# 다중공선성을 위해 VIF를 계산하니 GF,GA,GD는 무한대값이 나오며, xG, xGD, xGD/90은 VIF가 낮게 측정되었으나, xG는 p-value에 의해 유의하지 않은 것으로 판단
# 따라서 통계적으로 유의미하며 다중공선성이 존재하지 않는 xGD와 xGD/90를 활용하여 모델을 다시 설정
# xGD/90은 90분당 xGD를 의미하므로 사실상 같은 변수라고 판단하여 xGD/90만을 독립변수로 설정하여 단순회귀분석을 진행
lm = LinearRegression()
X = total_df[["xGD/90"]]
Y = total_df["Win Rate"]
lm.fit(X, Y)
Yhat = lm.predict(X)

a = (lm.intercept_) # y절편
b = (lm.coef_) # 기울기
r_squared = (lm.score(X,Y)) # 결정계수
# print(a, b, r_squared)

# 첫번째 모델 regression plot 그리기
sns.regplot(X, Y)
plt.pyplot.ylim(0,)
plt.pyplot.title("Residual Plot : xGD per 90min and Winning Rate")
plt.pyplot.show()

# 두번째 모델 - 점유 관련 10개의 지표 중 상관계수 값이 제일 높은 2가지만 선택하여 진행
# Z = total_df[['Touches','Mid 3rd','Live','Carries','TotDist','PrgDist','Prog','CPA','Targ','Rec']]
Z = total_df[['Targ', 'Rec']]
Y = total_df['Win Rate']
model2 = sm.OLS(Y, Z)
res2 = model2.fit()
# print(res2.summary())

# 유의수준 5%에서 모든 변수가 통계적으로 유의미하지 않음을 확인
# 다중공선성을 확인하기 위해 VIF를 계산
vif2 = pd.DataFrame({'factor': column, 'VIF': variance_inflation_factor(model2.exog, i)} 
             for i, column in enumerate(model2.exog_names)
             if column != 'Intercept')

# print(vif2)

# 다중공선성을 위해 VIF를 계산하니 값이 너무 높게 측정되어서 해당 모델을 사용하지 않기로 결정

# 초기 가설에 대한 추가 모델을 설정
# 점유율 - 승률 간의 단순회귀분석 실행
lm = LinearRegression()
X = total_df[["Poss"]]
Y = total_df["Win Rate"]

lm.fit(X, Y)
Yhat = lm.predict(X)

a = (lm.intercept_) # y절편
b = (lm.coef_) # 기울기
r_squared = (lm.score(X,Y)) # 결정계수
# print(a, b, r_squared)

sns.regplot(X, Y)
plt.pyplot.ylim(0,)
plt.pyplot.title("Residual Plot : Possession and Winning Rate")
plt.pyplot.show()
