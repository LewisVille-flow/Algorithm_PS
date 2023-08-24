import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

# 0.
dir_x = [0, 1, 0 , -1]
dir_y = [1, 0, -1, 0]

def Search(cx, cy):
    if dp_array[cx][cy] == 0:
        dp_array[cx][cy] = 1
        
    for dir in range(4):
        nx, ny = cx+dir_x[dir], cy+dir_y[dir]
        
        if 0<=nx<N and 0<=ny<N and grid[nx][ny] > grid[cx][cy]:
            if dp_array[nx][ny]!=0:
                dp_array[cx][cy] = max(dp_array[cx][cy], dp_array[nx][ny] + 1)
                
            else:
                dp_array[cx][cy] = max(dp_array[cx][cy], Search(nx, ny) + 1)
            
    return dp_array[cx][cy]

# input.
N = int(input())
grid = []
for n in range(N):
    grid.append(list(map(int, input().split())))

dp_array = [[0 for _ in range(N)] for _ in range(N)]
answer = 0

for i in range(N):
    for j in range(N):
        answer = max(answer, Search(i, j))
        
print(answer)