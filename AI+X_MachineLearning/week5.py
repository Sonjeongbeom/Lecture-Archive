# 1번

import pandas as pd
from datetime import date

col_names = ["A", "B", "C", "D"]

DF = pd.DataFrame({
    "A" : [0.370435, -0.148293, 0.599241, -0.021049, 0.327969, -0.851687],
    "B" : [-1.050255, 0.029794, 0.600079, -0.2809797, -2.415262, 0.927910],
    "C" : [-1.288945, 0.026026, -1.314375, -2.692448, 3.889575, 0.516239],
    "D" : [1.020208, -0.795184, 2.101309, -0.316646, 0.584920, 0.175822]
})

dates = [date(2013,1,1), date(2013,1,2), date(2013,1,3), date(2013,1,4), date(2013,1,5), date(2013,1,6)]
DF.index = dates

print(DF.loc[dates[1:],["C", "D"]])

# 2번

import pandas as pd
from datetime import date

col_names = ["A", "B", "C", "D"]

DF = pd.DataFrame({
    "A" : [0.370435, -0.148293, 0.599241, -0.021049, 0.327969, -0.851687],
    "B" : [-1.050255, 0.029794, 0.600079, -0.2809797, -2.415262, 0.927910],
    "C" : [-1.288945, 0.026026, -1.314375, -2.692448, 3.889575, 0.516239],
    "D" : [1.020208, -0.795184, 2.101309, -0.316646, 0.584920, 0.175822]
})

dates = [date(2013,1,1), date(2013,1,2), date(2013,1,3), date(2013,1,4), date(2013,1,5), date(2013,1,6)]
DF.index = dates

print(DF[DF['C'] > -1])

# 3번

import matplotlib.pyplot as plt

t = [0, 1, 2, 3, 4, 5, 6]
y = [1, 4, 5, 8, 9, 5, 3]

plt.figure(figsize=(10,6))
plt.xlim(-1, 8)
plt.ylim(0, 10)
plt.plot(t, y, lw=6, color='green', linestyle='dashed', marker='s', markerfacecolor='red', markersize=15)
plt.show()




