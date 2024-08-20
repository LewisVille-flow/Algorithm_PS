"""
    20m
    - 안전지역의 최대 개수. 100*100*100 3차원에 대해서 탐색...10^6 이니까 1초 이내.
    - 최대 높이 값부터 -1 하면서 안전지역 개수 max 값 업데이트
"""
import sys
from collections import deque

input = sys.stdin.readline

N = int(input().strip())
grid = []
max_value, min_value = -1, 101

for i in range(N):
    _row = list(map(int, input().split()))
    mv, nv = max(_row), min(_row)
    if mv > max_value:
        max_value = mv
    if nv < min_value:
        min_value = nv
    grid.append(_row)

global answer
answer = 1
dir = [[0, 1, 0, -1], [1, 0, -1, 0]]

def BFS(sx_list, min_height):   # min_height 포함 x에 주의
    global answer
    visited = [[0]*N for _ in range(N)]
    # grid_copy = copy.deepcopy(grid)
    
    num_area = 0
    for (sx, sy) in sx_list:
        queue = deque()
        
        if visited[sx][sy] == 0 and grid[sx][sy] > min_height:
            visited[sx][sy] = 1
            queue.append((sx, sy))
            num_area += 1
    
        while queue:
            cx, cy = queue.popleft()
            
            for m in range(4):
                nx, ny = cx+dir[0][m], cy+dir[1][m]
                
                if (nx>=0 and nx<N and ny>=0 and ny<N) and visited[nx][ny] == 0 and grid[nx][ny] > min_height:
                    visited[nx][ny] = 1
                    queue.append((nx, ny))
                    
    if num_area > answer:
        answer = num_area
        
for rain in range(min_value, max_value):    # max_value 포함 시 영역 = 0
    start_idx = []
    for i in range(N):
        for j in range(N):
            if grid[i][j] > rain:
                start_idx.append((i, j))
    # print(f">> Rain: {rain}, s: {start_idx}")
    BFS(start_idx, rain)
print(answer)