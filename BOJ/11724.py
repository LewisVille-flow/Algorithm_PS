from collections import defaultdict
import sys
input = sys.stdin.readline

def Solve(N, edges):
    # init graph
    graph = defaultdict(list)
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)
        
    # DFS or BFS
    visited = set()
    def DFS(node):
        stack = []
        stack.append(node)
        
        while stack:
            cnode = stack.pop()
            for nnode in graph[cnode]:
                if nnode not in visited:
                    visited.add(nnode)
                    stack.append(nnode)
        
    
    answer = 0
    for i in range(1, N+1):
        if i not in visited:
            DFS(i)
            answer += 1
        
    # output
    
    return answer


N, M = map(int, input().split())
edges = [tuple(map(int, input().split())) for _ in range(M)]
answer = Solve(N, edges)

print(answer)