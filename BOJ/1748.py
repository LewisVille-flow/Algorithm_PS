"""
    1. c++이면 자리 수 센다고 나머지 연산했을텐데.
    2. 자리수 = len(N), N-1까지는 반복연산
"""

N = int(input())
n_len = len(str(N))
answer = 0

for n in range(0, n_len-1):
    # print(answer)
    answer += 9*(10**n) * (n+1)             # 이전 자리수에 대한 길이 값 덧셈(항상 해당 자리수는 9*(10**n) 개 만큼 존재)

answer += (N - 10**(n_len-1) + 1) * n_len   # 해당 자리수에서 나머지 값 덧셈 이어서 진행

print(answer)