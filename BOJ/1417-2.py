"""
    11m
    
    같은 값이 없는 상태에서 max idx == 0 인경우 종료?
    계속 정렬하면서 1등인 사람을 1명씩 +- 하면 되겠다.
    다솜 값 vs 나머지 리스트, 나머지 리스트를 내림차순으로 정렬, 1등 값이 다솜 값보다 크거나 같을 경우 -1, 정렬 반복
"""

import sys
input = sys.stdin.readline
N = int(input().strip())
dasom = 0

grid = []
for n in range(N):
    if n == 0:
        dasom = int(input().strip())
    else:
        grid.append(int(input().strip()))

answer = 0
grid = sorted(grid, reverse=True)
while N>1 and dasom <= grid[0]:
    answer += 1
    dasom += 1
    grid[0] = grid[0] - 1
    grid = sorted(grid, reverse=True)
print(answer)