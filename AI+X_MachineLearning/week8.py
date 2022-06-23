# 1번
import matplotlib.pyplot as plt
import seaborn as sns

tips = sns.load_dataset("tips")
sns.boxplot(x="day", y="tip", hue="time", data=tips)
plt.show()

# 2번
import matplotlib.pyplot as plt
import seaborn as sns

sns.set_style("darkgrid")
tips = sns.load_dataset("tips")
sns.boxplot(x="size", y="total_bill", hue="day", data=tips)
plt.show()