"""
    120m
    - 격자, 최소 경로 = BFS 알고리즘
    - 벽을 부술 수 있다 - visited 이동 값 & 벽을 몇 번 부쉈는지에 대한 값
        최대 공간복잡도 10^7
    - 단순히 visited를 3차원으로 만들고 마지막 차원을 k로 설정하면 문제가 없는가?
    solve:
        - 0,0 에서 탐색 시작, 벽을 만나면 벽을 뚫고 탐색 계속, 벽이 아니라면 이전 값으로 계속, 마지막 인덱스만나면 무조건 최소경로이므로 출력후 종료
        - str 에 주의
        - 벽 사이를 계속 부수고 있을 경우 대비 -> 벽이고 이미 이전 벽을 부순 idx에서 방문한 경험이 있는지 확인
        
        1. 벽을 만난 경우
            - 해당 벽을 부수기 전에 방문한 적이 있는 경우 건너뛰어야 함. 즉, 다시 벽을 뚫고 탐색하는 경우가 없어야 함.
                -> 내가 생각하기에는 무조건, all([x == 0 for x in visited[nx][ny]]) True 여야 하거든?
                웹서치해서 나오는 상위 글들 보면 무조건 벽 만나면 다시 탐색하는 잘못된 로직 짬.
                근데 이 내 로직은 왜 틀렸다고 나오는지 이해가 안감....
        
        2. 벽이 아닌 경우
            - 지금 벽 카운트 상태에서 방문한 적이 없고 & 벽 카운트 이전에도 방문한 적 없어야 함
        # 
        #
"""
                

import sys
from collections import deque
input = sys.stdin.readline


N, M, K = map(int, input().split())
grid = []
for n in range(N):
    grid.append(list(map(int, input().strip())))
print(grid)
visited = [[[0 for _ in range(K+1)] for _ in range(M)] for _ in range(N)]

dir = [[0, 1, 0, -1], [1, 0, -1, 0]]

def in_range(x, y):
    return x>=0 and x<N and y>=0 and y<M

def BFS():
    answer = -1
    sx, sy = 0, 0
    ex, ey = N-1, M-1
    
    queue = deque()
    visited[sx][sy][0] = 1
    queue.append(((sx, sy), 0))
    
    while queue:
        (cx, cy), now_crushed = queue.popleft()
        now_counted = visited[cx][cy][now_crushed]
        
        print(f">> cx: {cx}, cy: {cy}, cru: {now_crushed}, now_c: {now_counted}")
        if cx == ex and cy == ey:
            return now_counted
        
        for m in range(4):
            nx, ny = cx+dir[0][m], cy+dir[1][m]
            
            if in_range(nx, ny):
                
                if grid[nx][ny] == 1 and now_crushed < K and visited[nx][ny][now_crushed+1]==0:
                # visited[nx][ny][now_crushed+1]==0: # 이렇게 하면 재방문하는데, 왜 맞지?
                    # if now_crushed == 0 or visited[nx][ny][now_crushed-1] == 0:
                    # all([x == 0 for x in visited[nx][ny]])    # 내 생각엔 이 로직이 맞단 말이지... 이게 왜 틀리지? 재방문해서 최단경로 안나오는데.
                    visited[nx][ny][now_crushed+1] = now_counted + 1
                    queue.append(((nx, ny), now_crushed+1))
                    
                elif grid[nx][ny] == 0 and visited[nx][ny][now_crushed] == 0:
                    # and visited[nx][ny][now_crushed] == 0:  
                    
                    # if any([x != 0 for x in visited[cx][cy]])     # 지금 처음 방문하는 거여야 함. 중복 방지.
                    visited[nx][ny][now_crushed] = now_counted + 1
                    queue.append(((nx, ny), now_crushed))
    return answer

answer =  BFS()
print(answer)


