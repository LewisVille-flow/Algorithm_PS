import sys
input = sys.stdin.readline

N = int(input())
numbers = list(map(int, input().split()))
dp_grid = [0]*N         # value = 해당 위치의 원소를 포함한 최대수열의 최댓값

dp_grid[0] = numbers[0]

for i in range(1, N):
    max_values = numbers[i]             # 무조건 초기값은 자기자신만은 포함해야 함.
    for j in range(0, i):
        if numbers[j] < numbers[i]:     # 증가하는 경우에만
            max_values = max(max_values, dp_grid[j]+numbers[i])
    dp_grid[i] = max_values

print(max(dp_grid))