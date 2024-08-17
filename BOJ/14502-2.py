"""
    14:30-
    목표: 벽을 3개 세워서 최대의 0 영역을 만들기 - 최대를 보장하려면?
    현재 2의 위치에서 탐색할 수 있는 영역 개수 == 필요한 벽의 개수. 그 개수의 합이 3이 되는 시점이어야 함. 근데 각 바이러스는 시간을 같게 해서 비교불가 & 퍼져 나가는 방향이 출구라는 보장 없음.
    
    랜덤으로 벽을 세워보고 최대의 영역 개수를 계속 비교해야하나? -> 최대 63C3 = 63*62*61/3*2 = 10^5
    64개의 칸 행 열 반복 -> 첫 벽을 세워두고, 두 세 번째 벽은 이것 보다 뒤로 설정, 1과 2가 아닌 경우에만 -> BFS 수행
        순차적으로 3개의 벽을 어떻게 세우지? 64*63*62 = 10^5 니까 ..?
        1. grid에 1부터 64까지의 값 대입, n-1번째 벽의 값보다 큰 idx에서부터 새 벽을 세워보기
        2. 완전탐색 - backtracking 으로 벽을 세우기
            벽 개수가 3개가 되면 그때서야 BFS
            벽 개수가 3개가 아니라면
            
    결론 -> 결국 0 이라는 빈 공간 튜플에서 중복없이 3개의 벽을 선택하는, M개에서 N개를 선택하는 문제와 같다.
"""
import sys
import copy

from collections import deque
# from itertools import combinations

input = sys.stdin.readline

N, M = map(int, input().split())
grid = []
for n in range(N):
    grid.append(list(map(int, input().split())))

dir = [[0, 1, 0 , -1], [1, 0, -1, 0]]
global max_num_safe
max_num_safe = -1

virus, empty = [], []
for i in range(N):
    for j in range(M):
        if grid[i][j] == 2:
            virus.append((i, j))
        if grid[i][j] == 0:
            empty.append((i, j))
            
def count_safe(grid):
    count = 0
    for i in range(N):
        for j in range(M):
            if grid[i][j] == 0:
                count += 1
    return count

def BFS():  # bfs 를 반복해야 하므로, 원본 grid를 복사해야 한다.
    # copy_grid = [[0]*M for _ in range(N)]
    visited = [[0]*M for _ in range(N)]
    
    # 바이러스 시작점
    queue = deque()
    for v in virus:
        queue.append(v)

    copy_grid = copy.deepcopy(grid)
    
    # 바이러스 전파 시작
    while queue:
        cx, cy = queue.popleft()
        
        for d in range(4):
            nx, ny = cx+dir[0][d], cy+dir[1][d]
            
            if (nx>=0 and nx<N and ny>=0 and ny<M) and visited[nx][ny] == 0 and copy_grid[nx][ny] == 0:
                visited[nx][ny] = 1
                copy_grid[nx][ny] = 2
                queue.append((nx, ny))
                
    num_safe = count_safe(copy_grid)
    return num_safe
    

def recursively_make_walls(now_idx: int, now_num_walls: int):
    if now_num_walls == 3:
        global max_num_safe
        num_safe = BFS()
        max_num_safe = max(max_num_safe, num_safe)
        return
    
    if now_idx >= len(empty):
        return
    
    grid[empty[now_idx][0]][empty[now_idx][1]] = 1
    recursively_make_walls(now_idx+1, now_num_walls+1)
    grid[empty[now_idx][0]][empty[now_idx][1]] = 0
    
    recursively_make_walls(now_idx+1, now_num_walls)
    
    # 아래와 같이 수행하면 최대 (63*62*61) * 각 경우 BFS -> 시간초과
    # for row in range(N):
    #     for col in range(M):
    #         if grid[row][col] == 0:
    #             grid[row][col] = 1
    #             recursively_make_walls(now_num_walls+1)
    #             grid[row][col] = 0

# main
recursively_make_walls(0, 0)
print(max_num_safe)