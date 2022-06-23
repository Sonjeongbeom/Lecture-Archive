# part1
import numpy as np
from sklearn.neighbors import KNeighborsClassifier
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
import pandas as pd

#1
wine = pd.read_csv('C:/Users/user/Desktop/대학교/21-1학기/AI+X/중간과제2/part1/wine_data.csv')
# print(wine)

#2
wine.describe()
# print(wine.describe())

#3
lm = LinearRegression()
X = wine[wine.columns.difference(["Class"])]
Y = wine["Class"]
X_train, X_test, y_train, y_test = train_test_split(X, Y, test_size=0.3, random_state=19)

#4
knn = KNeighborsClassifier()

#5
knn = KNeighborsClassifier(n_neighbors=5, p=2)
knn.fit(X_train, y_train) 
y_pred_train = knn.predict(X_train)
print(((np.mean(y_pred_train == y_train))*100))

#6
y_pred_test = knn.predict(X_test)
print(((np.mean(y_pred_test == y_test))*100))

#7
knn = KNeighborsClassifier(n_neighbors=3, p=2)
knn.fit(X_train, y_train) 
y_pred_train = knn.predict(X_train)
print(((np.mean(y_pred_train == y_train))*100))
y_pred_test = knn.predict(X_test)
print(((np.mean(y_pred_test == y_test))*100))

#8
lm = LinearRegression()
X = wine[["Alcohol", "Malic acid", "Ash", "Alcalinity of ash"]]
Y = wine["Class"]
X_train, X_test, y_train, y_test = train_test_split(X, Y, test_size=0.3, random_state=19)
knn = KNeighborsClassifier(n_neighbors=5, p=2)
knn.fit(X_train, y_train) 
y_pred_train = knn.predict(X_train)
print(((np.mean(y_pred_train == y_train))*100))
y_pred_test = knn.predict(X_test)
print(((np.mean(y_pred_test == y_test))*100))