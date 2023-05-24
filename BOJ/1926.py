"""
09:15-09:44
그래프탐색은 똑같다
"""
import sys
from collections import deque
input = sys.stdin.readline
queue = deque()

# 1. input
N, M = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(N)]

# 3. search
visited = []
for n in range(N):
    visited.append([0]*M)
count = 0
max_area = 0

def BFS():
    lcount=0
    dir = [[0, 1, 0, -1],
           [1, 0, -1, 0]]
    while queue:
        cx, cy = queue.popleft()
        for d in range(4):
            nx, ny = cx+dir[0][d], cy+dir[1][d]
            
            if 0<=nx<N and 0<=ny<M and grid[nx][ny] == 1 and not visited[nx][ny]:
                lcount += 1
                visited[nx][ny] = 1
                queue.append((nx, ny))
    return lcount

for n in range(N):
    for m in range(M):
        if grid[n][m] == 1 and not visited[n][m]:
            queue.append((n, m))
            visited[n][m] = 1
            lcount = BFS()
            max_area = max(max_area, lcount+1)
            count += 1
# 4. count
print(count)
print(max_area)