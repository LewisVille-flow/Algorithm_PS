"""
    60m
    
    지금까지의 탐색 경로 중 벽을 부술 기회 1, 0 기록
    맵 = (지금까지의 이동한 횟수/벽 부쉈었는지 여부)
    벽을 부순경우, 부수지 않은 경우 두 경우가 같이 기록되어야 할듯?
    move_grid[0][0] = (부수지 않은 경우 이동 횟수, 부순 경우 이동 횟수)
    
    # 방문여부 - 벽을 뚫은 경우 뚫지 않은 경우 둘로 나눠서
    
    if # 종료조건 - 마지막 인덱스라면 그냥 continue
    if inRange(nx, ny):
        if isWall(nx, ny) and not crushed:  # 벽인데 아직 기회 남은 경우
            crushed = True
            move_grid[nx][ny] = (move_grid[nx][ny], move_grid[cx][cy]+1)
            queue.append(((nx, ny), crushed))
            
        if not isWall(nx, ny)               # 벽아니고 기회 남거나말거나 한 경우
            queue.append(nx, ny, crushed)
            if crushed:
                move_grid[nx][ny] = (move_grid[nx][ny], move_grid[cx][cy]+1)
            else:
                move_grid[nx][ny] = (move_grid[cx][cy]+1, move_grid[nx][ny])
    
    결과 출력: 
        move_grid 돌면서, 두 원소 중 가장 작은 값 저장
        불가능한 경우 -1
"""

import sys
from collections import deque
input = sys.stdin.readline

N, M = map(int, input().split())
grid = []

# visited = [[[0]*M for _ in range(N)] for _ in range(2)]    # [x][y][crushed]
visited = [[[0 for _ in range(2)] for _ in range(M)] for _ in range(N)]
# list comprehension 이라, 가장 바깥에 있는 반복문부터 차례로 행 -> 열 -> depth

dir_x = [0, 1, 0, -1]
dir_y = [1, 0, -1, 0]

for r in range(N):
    _row = list(map(int, str(input().strip())))
    grid.append(_row)

def inRange(x, y) -> bool:
    return x>=0 and x<N and y>=0 and y<M

def BFS():
    start_x, start_y = 0, 0
    answer = -1
    end_x, end_y = N-1, M-1
    
    queue = deque()
    visited[start_x][start_y][0] = 1
    visited[start_x][start_y][1] = 1
    queue.append(((start_x, start_y), 0))
    
    while queue:
        (cx, cy), crushed = queue.popleft()
        
        if cx == end_x and cy == end_y:
            answer = visited[cx][cy][crushed]
            break
        
        for move in range(4):
            nx, ny = cx+dir_x[move], cy+dir_y[move]
            
            # 벽을 뚫지 않은 경우에 벽을 만나면 무조건 뚫어서 나가본다.
            # 벽이 아닌 걸 만나면 방문하지 않은 경우에만 나간다, 이전에 뚫었든 안 뚫었든.
            if inRange(nx, ny):
                if crushed==0 and grid[nx][ny] == 1:
                    visited[nx][ny][crushed+1] = visited[cx][cy][crushed] + 1
                    queue.append(((nx, ny), crushed+1))
                
                elif grid[nx][ny] == 0 and visited[nx][ny][crushed] == 0:
                    visited[nx][ny][crushed] = visited[cx][cy][crushed] + 1
                    queue.append(((nx, ny), crushed))
                    
    return answer
# main
print(BFS())
