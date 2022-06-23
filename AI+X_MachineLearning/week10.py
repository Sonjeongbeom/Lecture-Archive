# 1번
import random
import numpy as np

data_names = np.random.randn(5, 4)

# 1행 20열
data_names = data_names.reshape(1, 20)
print(data_names.shape)

# 2행 10열
data_names = data_names.reshape(2, 10)
print(data_names.shape)

# 5행 4열
data_names = data_names.reshape(5, 4)
print(data_names.shape)

# 4행 5열
data_names = data_names.reshape(4, 5)
print(data_names.shape)

# 2번
import random
import numpy as np

data_names = np.random.randn(3, 6)

print("3행 6열")
print(data_names)

print("4행 5열")
print(data_names.reshape(4, 5)) # this will cause error

