"""
    그래프 복습
    09:59-
"""
import sys
from collections import deque
input = sys.stdin.readline

# 1.
M, N = map(int, input().split()) # col, row
grid = [[0]*M for _ in range(N)]
dir_x = [0, 1, 0, -1]   # row
dir_y = [1, 0, -1, 0]

# 2.
for row in range(N):
    grid[row] = list(map(int, input().split()))
    
# 3. 
def BFS():
    while queue:
        x, y = queue.popleft()
        day = grid[x][y]
        
        for dir in range(4):
            nx, ny = x + dir_x[dir], y + dir_y[dir]
            
            if (nx>=0 and nx<N and ny>=0 and ny<M) and grid[nx][ny]==0:
                grid[nx][ny] = day+1
                queue.append((nx, ny))
    return

# 4.
queue = deque()
for i in range(N):
    for j in range(M):
        if grid[i][j] == 1:
            queue.append((i, j))
BFS()

# 5. 예외처리
def find():
    max_value = -1
    for i in range(N):
        max_value = max(max_value, max(grid[i]))
        for j in range(M):
            if grid[i][j] == 0:
                return -1
    return max_value-1

max_value = find()
print(max_value)