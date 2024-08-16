"""
    00:15-01:11, 60m
    BFS를 일반적으로 진행, 큐가 빌 때 까지, 값이 0이면서, 방문x, inrange
    출력 전 grid를 전체 훑어보면서, 최대 visited 값 탐색, 0 인 토마토가 있으면 그 즉시 -1 출력
    visited == 해당 칸이 익게 된 시간
    grid == 토마토 상태
    
    탐색 시작 지점: 입력 받다가 값이 1일 경우 모두 시작 큐에 있어야 함. 0으로 시작.
"""

import sys
from collections import deque

input = sys.stdin.readline

C, R = map(int, input().split())
dir_x = [0, 1, 0, -1]
dir_y = [1, 0, -1, 0]

queue = deque()
grid = []
for r in range(R):
    _row = list(map(int, input().split()))
    grid.append(_row)
    
for r in range(R):
    for c in range(C):
        if grid[r][c] == 1:
            queue.append((r, c))
    
def inRange(x, y):
    return x>=0 and x<R and y>=0 and y<C

def BFS():    
    while queue:
        cx, cy = queue.popleft()
        
        for move in range(4):
            nx, ny = cx+dir_x[move], cy+dir_y[move]
            
            if inRange(nx, ny) and grid[nx][ny] == 0:
                grid[nx][ny] = grid[cx][cy]+1
                queue.append((nx, ny))

def check_all_tomato():
    max_count = 1
    for r in range(R):
        for c in range(C):
            if grid[r][c] == 0:
                return -1
            if grid[r][c] != -1:
                max_count = max(max_count, grid[r][c])
    if max_count == 1:
        return 0
    return max_count-1

# main
BFS()
print(check_all_tomato())