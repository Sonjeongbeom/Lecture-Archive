# 1번
import random

lotto = []
while len(lotto) < 6 :
    num = random.randint(1, 45)
    if num in lotto :
        pass

    lotto.append(num)

print(lotto)