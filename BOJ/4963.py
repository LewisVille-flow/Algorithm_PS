"""
    1. 2차원 배열 입력
    2. bfs를 통한 탐색(deque)
"""

import sys
from collections import deque
input = sys.stdin.readline

def InRange(x, y):
    # return False if x > H-1 or x < 0 or y > W-1 or y < 0 else True
    return 0 <= x < H and 0 <= y < W
    
def BFS(start, graph, visited):
    dir = [[0, 1, 0, -1, -1, 1, 1, -1],
           [1, 0, -1, 0, 1, 1, -1, -1]]
    answer = 1
    queue = deque()
    queue.append(start)
    visited.add(start)
    
    while queue:
        cx, cy = queue.popleft()
        for x, y in zip(*dir):
            nx, ny = cx + x, cy + y
            
            if InRange(nx, ny) and (nx, ny) not in visited and graph[nx][ny] == 1:
                visited.add((nx, ny))
                queue.append((nx, ny))
    
    return answer

def Solve():
    global W, H

    while True:
        # input
        W, H = map(int, input().split())
        if W == 0 and H == 0:   break
        
        visited = set()
        graph = [list(map(int, input().split())) for _ in range(H)]
        
        # bfs
        answer = sum(BFS((h, w), graph, visited) for h in range(H) for w in range(W) if graph[h][w] == 1 and (h,w) not in visited)
        print(answer)
        
        # output
        del graph, visited

if __name__ == "__main__":
    Solve()