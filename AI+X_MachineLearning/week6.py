# 1번
a = [1, 3, 5, 7, 9]
for i in range(len(a)) :
    a[i] += 2
print(a)


# 2번
sum = 0
num = 1
while num <= 15 :
    if num % 2 == 0 :
        sum += num
    num += 1
print(sum)


# 3번
num_list = [1, 2, 3, 4, 5, 6]
for i in range(len(num_list)-1) :
    for j in range(i+1) :
        print(num_list[j], end="")
    print("")
