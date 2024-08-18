"""
    30m
    - 증가수열(정순으로 계산) / 감소수열(역순으로 계산) 해서 각 인덱스값을 저장 후 -1 하면?
    - row: 증가 / 감소, col: 아이템 index, value: 해당 수를 포함한 증가/감소 최대 길이
"""

N = int(input())
numbers = list(map(int, input().split()))
dp_grid = [[0]*N for _ in range(2)]         # (2, N)

for i in range(0, N):
    ascend_idx, descend_idx = i, N-1-i      # 
    ascend_max_value, descend_max_value = 1, 1      # 자기자신은 무조건 시작지점이므로 길이 1
    
    for j in range(0, ascend_idx):                   # 증가수열
        if numbers[j] < numbers[ascend_idx]:
            ascend_max_value = max(ascend_max_value, dp_grid[0][j]+1)
    
    for j in range(N-1, descend_idx, -1):           # 감소 수열
        if numbers[j] < numbers[descend_idx]:
            descend_max_value = max(descend_max_value, dp_grid[1][j]+1)
    
    dp_grid[0][ascend_idx] = ascend_max_value
    dp_grid[1][descend_idx] = descend_max_value

# print(dp_grid)
total = [0]*N
for t in range(N):
    total[t] = dp_grid[0][t] + dp_grid[1][t] - 1
print(max(total))