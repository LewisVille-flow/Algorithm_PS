"""
    09:15-09:47
    1차원 축에 대해 왼/오 점프하는 문제와 동일
    가능 여부 판단이 핵심 -> 모든 탐색 종료 시에도 도달 x이면 불가능 출력 ...?
"""
import sys
from collections import deque
input = sys.stdin.readline
# 1. input
F, S, G, U, D = map(int, input().split())
visited = [0] * (F+1)

# 2. 탐색
def BFS():
    queue = deque()
    queue.append(S)
    # visited[S] = 1 -> visited로 이동거리를 함께 기록하려면 1로 업데이트해줘야함.
    while queue:
        now = queue.popleft()
        if now == G:
            print(visited[now])
            return
        
        for next in (now+U, now-D):
            if 0 < next <= F and visited[next] == 0 and next != now:
                visited[next] = visited[now] + 1
                queue.append(next)
    
    print("use the stairs")
        
BFS()