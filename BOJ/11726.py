import sys

input = sys.stdin.readline

N = int(input().strip())
array = [0] * (1001)
array[1] = 1
array[2] = 2

for i in range(3, N+1):
    array[i] = array[i-1]+array[i-2]
print(array[N]%10007)
