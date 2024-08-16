"""
    40m
    격자에서 이동, 사다리와 뱀이라는 변칙이 있지만 결국 end 까지의 최소 경로 탐색. BFS
    탐색 기준
        - 사다리 / 뱀을 만나면 해당 위치의 visited True 설정. 해당 위치에서 탐색 시작.
    visited: 해당 index까지 최소로 이동한 횟수
    
    인덱싱을 0 부터가 아닌 1부터 하는 것에 유의 -> 맵을 +1 사이즈로 제작, 0 인덱스 무시
"""
import sys
input = sys.stdin.readline

U, D = map(int, input().split())
grid = [i for i in range(0, 101)]
visited = [0] * 101

for move in range(U+D):
    st, en = map(int, input().split())
    grid[st] = en

def inRange(idx:int) -> bool:
    return idx>0 and idx<101

def BFS():
    start_idx, end_idx = 1, 100     # 1 부터 시작
    queue = []
    # visited[start_idx] = 0
    queue.append(start_idx)
    
    while queue:
        cidx = queue.pop(0)
        ccount = visited[cidx]
        
        if cidx == end_idx:
            return ccount
        
        for move in range(1, 7):
            nidx = cidx+move
            if inRange(nidx) and visited[grid[nidx]] == 0:
                # if grid[nidx] != nidx:      # 사다리 혹은 뱀 -> 이거 visited 중복 업데이트 오류 만드나..?
                #     visited[nidx] = ccount + 1
                #     nidx = grid[nidx]
                visited[grid[nidx]] = ccount + 1
                queue.append(grid[nidx])
print(BFS())