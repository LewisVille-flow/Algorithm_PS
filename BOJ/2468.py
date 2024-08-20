"""
    09:31~09:56
    1. 입력 -> 최솟값, 최댓값 저장
    2. 최솟값~최댓값을 기준으로 잠기는 영역 체크
    3. 안 잠긴 영역 BFS, 영역 개수 카운트, 갱신
    4. 출력
"""
import sys
from collections import deque
input = sys.stdin.readline

def InRange(x, y):
    return 0<=x<N and 0<=y<N

def BFS(graph):
    dir = [[0, 1, 0, -1],
           [1, 0, -1, 0]]
    # queue = deque()
    count = 0
    visited = set()
    
    for i in range(N):
        for j in range(N):
            queue = deque()
            
            if graph[i][j] is False and (i, j) not in visited:
                
                count += 1
                visited.add((i, j))
                queue.append((i, j))
                
            while queue:
                cx, cy = queue.popleft()
                
                for x, y in zip(*dir):
                    nx, ny = cx+x, cy+y
                    
                    if InRange(nx, ny) and graph[nx][ny] is False and (nx, ny) not in visited:
                        visited.add((nx, ny))
                        queue.append((nx, ny))
                        
    return count   


def Solve():
    global N
    
    # input
    N = int(input())
    graph = [list(map(int, input().split())) for _ in range(N)]
    # under = [list(False for _ in range(N)) for _ in range(N)]
    
    # min max
    _max, _min = -1, 101
    for i in range(N):
        mv, nv = max(graph[i]), min(graph[i])
        if mv > _max:
            _max = mv
        if nv < _min:
            _min = nv
        
    # _min = min(min(graph[i] for i in range(N)))
    # _max = max(max(graph[i] for i in range(N)))
    
    # rain
    max_area = 1
    for rain in range(_min, _max):
        under = [list(False for _ in range(N)) for _ in range(N)]
        
        for i in range(N):
            for j in range(N):
                if graph[i][j] <= rain:
                    under[i][j] = True
        count = BFS(under)
        max_area = max(max_area, count) 

    print(max_area)

Solve()