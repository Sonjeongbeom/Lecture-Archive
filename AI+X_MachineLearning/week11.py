# 1번
A = ['t', 'e', 'a', 'm']
A[1:] = ['i', 'm', 'e']
print(A)

# 2번
A = {1, 4, 6, 8, 23, 45}
print(len(A)) # 길이
print(min(A)) # 최소값
print(max(A)) # 최대값

# 3번
A = {1, 2, 5, 6}
B = {5, 6, 8, 9}

print(A & B) # 교집합
print(A | B) # 합집합
print(A - B) # 차집합 (A - B)
print(B - A) # 차집합 (B - A)