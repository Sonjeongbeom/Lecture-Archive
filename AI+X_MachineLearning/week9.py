# 1번
import numpy as np

data_names = np.random.randn(5, 4)
data_condition = (data_names <= -0.3) | (data_names >= 0.6)
data_names[data_condition] = 100
print(data_names)

# 2번
import numpy as np

data_names = np.random.randn(5, 4)
new_data = np.array([(data_names[0] + data_names[2]) * data_names[4]])
print(new_data)
