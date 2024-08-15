import sys
input = sys.stdin.readline

subin, sis = map(int, input().split())
max_idx = 100001

queue = []
visited = [0]*max_idx

def inRange(index: int) -> bool:
    return index>=0 and index<max_idx

def BFS():
    start_idx, end_idx = subin, sis
    queue.append(start_idx)
    
    while queue:
        cidx = queue.pop(0)

        if cidx == end_idx:
            return visited[cidx]
        
        for nidx in (cidx+1, cidx-1, cidx*2):
            if inRange(nidx) and visited[nidx] == 0:
                visited[nidx] = visited[cidx] + 1
                queue.append(nidx)

print(BFS())