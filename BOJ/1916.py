"""
    그래프 탐색 복습 - 다익스트라
"""
import sys
import heapq
input = sys.stdin.readline
queue = []

## main
N = int(input())
M = int(input())
graph = [[] for _ in range(N)]
distance = [999999999 for _ in range(N)]

for m in range(M):
    s, e, w = map(int, input().split())
    graph[s].append((w, e))

S, E = map(int, input().split())

## def
def Search(start, end):
    heapq.heappush(queue, (0, start))       # wage, node
    
    while queue:
        wage, now = heapq.heappop(queue)
        
        # end 지점에 대한 탐색이 이뤄지는 때라면 distance가 다 채워지지 않았더라도 최소비용이 계산되어있을 것이다.
        if now == end:
            minimum_wage = distance[now]
            return minimum_wage
        
        for nnode in graph[now]:
            nwage = wage + nnode[0]
            next = nnode[1]
            
            if distance[next] > nwage:
                distance[next] = nwage
                heapq.heappush(queue, (nwage, next))
    
    return distance


minimum_wage = Search(S, E)
print(minimum_wage)