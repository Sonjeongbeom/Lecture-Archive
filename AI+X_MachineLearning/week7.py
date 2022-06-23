# # 1번
# def printNum(*args) :
#     for i in args :
#         print(i, end = " ")
#     print()
#     return 0

# printNum(1, 2, 3, 4, 5)
# printNum(6, 7, 8)
# printNum(9, 10)

# 2번
def times_table(num) :
    for i in range(1, 10) :
        print(num, "*", i, "=", (num * i))
    return 0

times_table(3)
times_table(9)