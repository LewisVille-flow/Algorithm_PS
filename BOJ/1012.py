"""
    간단한 그래프, 복습
    09:37-09:56
"""
import sys
input = sys.stdin.readline

# 1.
T = int(input())
dir_x = [0, 1, 0, -1]   # 행
dir_y = [1, 0, -1, 0]

# 2.
def BFS(start_x, start_y):
    queue = []
    queue.append((start_x, start_y))

    while queue:
        x, y = queue.pop(0)
        
        for dir in range(4):
            nx, ny = x + dir_x[dir], y + dir_y[dir]
            
            if (nx >= 0 and nx < N and ny >=0 and ny <M) and grid[nx][ny] == 1:
                grid[nx][ny] = 0
                queue.append((nx, ny))    
    return

# 3.
total_area = [0]*T
for t in range(T):
    M, N, K = map(int, input().split())
    grid = [[0]*M for _ in range(N)]
    
    for k in range(K):
        y, x = map(int, input().split())
        grid[x][y] = 1

    for i in range(N):
        for j in range(M):
            if grid[i][j] == 1:
                BFS(i, j)
                total_area[t] += 1
                
# 4.
print("\n".join(map(str, total_area)))