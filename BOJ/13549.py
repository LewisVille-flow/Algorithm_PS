"""
    그래프 탐색 문제 복습
    
"""
import sys
from collections import deque
input = sys.stdin.readline

# 1.
N, K = map(int, input().split())
queue = deque()
visited = [0 for _ in range(100001)]

def BFS():
    queue.append((0, N))

    while queue:
        time_now, pos_now = queue.popleft()
        
        if pos_now == K:
            print(time_now)
            break
        
        if pos_now*2 < 100001 and visited[pos_now*2] == 0:
            visited[pos_now*2] = 1
            queue.appendleft((time_now, pos_now*2))
        
        if pos_now-1 >= 0 and visited[pos_now-1] == 0:
            visited[pos_now-1] = 1
            queue.append((time_now+1, pos_now-1))
        
        if pos_now+1 < 100001 and visited[pos_now+1] == 0:
            visited[pos_now+1] = 1
            queue.append((time_now+1, pos_now+1))
    return

# main
BFS()
