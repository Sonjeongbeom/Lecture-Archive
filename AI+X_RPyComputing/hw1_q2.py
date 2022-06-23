# Part2

from numpy.core.fromnumeric import mean
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns

# Q5
missing_values = ["na", "NaN"]
df = pd.read_csv('boston_csv.csv', na_values = missing_values)
df.dropna(inplace = True)

# Q6
from scipy import stats
df.describe() # 변수별 요약통계량
df.corr() # 상관관계 파악
ax = sns.heatmap(df) # heatmap 구현
plt.title("Heatmap")
plt.show()

# Q7
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error

lm = LinearRegression()
X = df[["LSTAT"]]
Y = df["MEDV"]
X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size=0.25)

lm.fit(X_train, Y_train)
Yhat = lm.predict(X_train)

lm.intercept_ # y절편
lm.coef_ # 기울기
lm.score(X_train, Y_train) # 결정계수
mean_squared_error(Y_train, Yhat) # mean squared error

Yhat_test = lm.predict(X_test)
mean_squared_error(Y_test, Yhat_test)

# Q8
lm = LinearRegression()
Z = df[["LSTAT", "TAX"]]
Y = df["MEDV"]
Z_train, Z_test, Y_train, Y_test = train_test_split(Z, Y, test_size=0.25)

lm.fit(Z_train, Y_train)
Yhat = lm.predict(Z_train)

lm.intercept_ # y절편
lm.coef_ # 기울기
lm.score(Z_train, Y_train) # 결정계수
mean_squared_error(Y_train, Yhat) # mean squared error

Yhat_test = lm.predict(Z_test)
mean_squared_error(Y_test, Yhat_test)