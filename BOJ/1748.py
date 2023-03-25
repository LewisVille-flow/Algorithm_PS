"""
    1. c++이면 자리 수 센다고 나머지 연산했을텐데.
    2. 자리수 = len(N), N-1까지는 반복연산
"""

N = int(input())
n_len = len(str(N))
answer = 0

for n in range(0, n_len-1):
    answer += 9*(10**n) * (n+1)

answer += (N - 10**(n_len-1) + 1) * n_len

print(answer)