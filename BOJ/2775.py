import sys
input = sys.stdin.readline

# 0.
def solve():
    for k in range(1, K+1):
        for n in range(0, N):
            dp_array[k][n] = dp_array[k-1][n]
            for j in range(0, n):
                dp_array[k][n] += dp_array[k-1][j]
    return dp_array[K][N-1]

T = int(input())
for t in range(T):
    K, N = int(input()), int(input())
    dp_array = [[0 for _ in range(0, N)] for _ in range(0, K+1)]
    dp_array[0] = [i for i in range(1, N+1)]
    print(solve())
    