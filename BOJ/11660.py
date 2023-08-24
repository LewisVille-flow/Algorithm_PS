import sys
input = sys.stdin.readline

# 0.
def solve():
    for row in range(1, N+1):
        for col in range(1, N+1):
            dp_array[row][col] = (grid[row-1][col-1] + dp_array[row][col-1] + dp_array[row-1][col] - dp_array[row-1][col-1])

# input
N, M = map(int, input().split())
grid = []
for n in range(N):
    grid.append(list(map(int, input().split())))

dp_array = [[0 for _ in range(N+1)] for _ in range(N+1)]
solve()

for m in range(M):
    x1,y1,x2,y2 = map(int, input().split())

    print(dp_array[x2][y2] - dp_array[x1-1][y2] - dp_array[x2][y1-1] + dp_array[x1-1][y1-1])