# Part1

# Q1

# Q2
from pandas.io.stata import precision_loss_doc
import requests
from bs4 import BeautifulSoup
import pandas as pd

url = 'https://www.skysports.com/premier-league-table/2019'
page = requests.get(url)
soup = BeautifulSoup(page.text, 'html.parser')
table = soup.find('table', {"class" : 'standing-table__table callfn'})

headers= []
for i in table.find_all('th') :
    title = i.text.strip()
    headers.append(title)

df = pd.DataFrame(columns = headers)


for j in table.find_all('tr')[1:] :
    row_data = j.find_all('td')
    row = [tr.text for tr in row_data]
    new_row = []
    for a in row :
        a = a.strip('\n')
        new_row.append(a)
    length = len(df)
    df.loc[length] = new_row

# Q3
df = df.astype({'GD':'int', 'Pl':'int', 'W':'int'})
pl = df.Pl.tolist()
w = df.W.tolist()

win_prob = []
for i in range(len(pl)) :
    x = w[i] / pl[i]
    win_prob.append(x)
df['win_prob'] = win_prob

from sklearn.linear_model import LinearRegression
import numpy as np
from  sklearn.metrics import mean_squared_error

lm = LinearRegression()
X = df[["GD"]]
Y = df["win_prob"]
lm.fit(X, Y)
Yhat = lm.predict(X)

a = (lm.intercept_) # y절편
b = (lm.coef_) # 기울기
r_squared = (lm.score(X,Y)) # 결정계수

# Q4
import statsmodels.api as sm
X2 = sm.add_constant(X)
est = sm.OLS(Y, X2)
est2 = est.fit()
print(est2.summary())


