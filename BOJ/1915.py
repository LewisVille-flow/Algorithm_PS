import sys, math
input = sys.stdin.readline

# function
def solve():
    answer = 0
    for i in range(0, N):
        for j in range(0, M):
            if i==0 or j==0:
                dp_array[i][j] = grid[i][j]
            elif grid[i][j] == 1:
                min_area = min(grid[i-1][j], grid[i][j-1], grid[i-1][j-1])
                dp_array[i][j] = min_area+1
            answer = max(answer, dp_array[i][j])
            
    return answer**2

# input
N, M = map(int, input().split())
grid = []
for n in range(N):
    grid.append(list(map(int, list(str(input().strip())))))

dp_array = grid.copy()
print(solve())