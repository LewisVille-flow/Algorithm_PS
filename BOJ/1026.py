import sys
input = sys.stdin.readline

N = int(input())
array_a = list(map(int, input().split()))
array_b = list(map(int, input().split()))

array_a = sorted(array_a)
array_b = sorted(array_b, reverse=True)

answer = 0
for n in range(N):
    answer += array_a[n] * array_b[n]
print(answer)