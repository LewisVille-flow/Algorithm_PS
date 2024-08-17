"""
    60m
    격자, 며칠 -> 그래프 탐색
    인구가 이동한다 = 특정 영역의 인구 합을 평균내서 값을 덮어쓴다
        특정 영역 = 인접한 구역과 차이가 L<= <=R 일 경우
        완탐 + 그래프 탐색으로 해당 시간에 인구이동 완료하기
            완탐: visited x & 조건 해당
"""
import sys
from collections import deque
input = sys.stdin.readline

N, L, R = map(int, input().split())
grid = []
for n in range(N):
    grid.append(list(map(int, input().split())))

dir = [[0, 1, 0, -1], [1, 0, -1, 0]]

def in_range(nx, ny):
    return nx>=0 and nx<N and ny>=0 and ny<N

def is_true(cp, np):
    return L<=abs(cp - np)<=R

def BFS(start_x, start_y):
    queue = deque()
    indexes = [(start_x, start_y)]
    
    visited[start_x][start_y] = 1
    queue.append((start_x, start_y))
    
    total_population = grid[start_x][start_y]
    
    while queue:
        cx, cy = queue.popleft()
        cp = grid[cx][cy]
        
        # print(f"\n>> cx: {cx}, cy: {cy}, cp: {cp}")       
        
        for move in range(4):
            nx, ny = cx+dir[0][move], cy+dir[1][move]
            
            if in_range(nx, ny) and is_true(cp, grid[nx][ny]) and visited[nx][ny] == 0:
                visited[nx][ny] = 1
                total_population += grid[nx][ny]
                queue.append((nx, ny))
                indexes.append((nx, ny))
    
    if len(indexes) > 1:
        next_population = total_population // len(indexes)
        for (x, y) in indexes:
            grid[x][y] = next_population
        return True
    
    # print(f">> grid:\n{grid}")
    return False
    
# main
answer = 0
while True:
    visited = [[0]* N for _ in range(N)]            # BFS 에서 사용하는 visited
    is_moved = False
    
    for row in range(N):
        for col in range(N):
            if visited[row][col] == 0:
                if BFS(row, col):
                    is_moved = True
    
    if not is_moved:
        break
    
    answer += 1
print(answer)