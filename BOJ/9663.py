"""
    13-
    완전탐색, 모든 경우의 수 확인 필요
    for loop or backtracking
    -
    - backtracking:
        퀸 개수가 N 일 때 += 1
        dir 조건: 범위 내 & 퀸 x & 이전 퀸 가로세로대각선x
            퀸 범위: grid에 저장되어있을 거고, nx ny 에서 가로세로 대각선방향 for 해서 1이 아닌경우에만 추가하고 재귀
        
    시간초과 -> 개선 요구사항:
        - 1차원 배열을 통해 queens 위치 저장: queen[i] = j 는 i 행 j 열에 퀸이 있다고 할 수 있음.
        - 대각서치는 북서 / 북동 방향만 진행하면 됨. 아래에는 어차피 퀸이 없으니.
            북서 방향에 있다: i-x == j-y 
            북동 방향에 있다: i-x == -(j-y)
        - 퀸 위치를 기억하는 리스트, 개수를 함께 백트래킹하면 된다.
"""
N = int(input().strip())

dir_norm = [[0, 1, 0, -1], [1, 0, -1, 0]]
dir_diag = [[-1, 1, 1, -1], [1, 1, -1, -1]]

grid = [[0 for _ in range(N)] for _ in range(N)]
# visited를 만들면 시간을 절약할 수 있으려나?

answer = 0


def recursive(cnt: int, queens: list):
    global answer
    print(queens)
    if cnt == N:
        answer += 1
        return
    
    cx = queens[-1][0]
    for nx in range(cx, N):
        for ny in range(N):
            # for m in range(4):
            # nx, ny = cx+dir_norm[0][m], cy+dir_norm[1][m]
            
            if grid[nx][ny] != 1:
                # 퀸 범위 확인
                is_queen = False
                for (x, y) in queens:
                    if nx == x:     is_queen = True
                    if ny == y:     is_queen = True
                if is_queen:
                    continue
                
                for diag in range(4):
                    nnx, nny = nx+dir_diag[0][diag], ny+dir_diag[1][diag]
                    
                    while (nnx>=0 and nnx<N and nny>=0 and nny<N):
                        if grid[nnx][nny] == 1:
                            is_queen = True
                            break
                        nnx, nny = nnx+dir_diag[0][diag], nny+dir_diag[1][diag]
                        
                if not is_queen:
                    grid[nx][ny] = 1
                    queens.append((nx, ny))
                    recursive(cnt+1, queens)
                    grid[nx][ny] = 0
                    queens.pop()
                

recursive(0, [(0, 0)])
print(answer)