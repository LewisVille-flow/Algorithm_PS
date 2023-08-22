import sys
input = sys.stdin.readline

# 0.
def solve():
    dp_array[0] = 1
    for i in range(N):
        for j in range(coins[i], K+1):
            dp_array[j] += dp_array[j-coins[i]]
    return dp_array[K]

# 1.
N, K = map(int, input().split())
coins = []
for i in range(N):
    coins.append(int(input()))

dp_array = [0] * (K+1)
coins = sorted(coins, reverse=False)
print(solve())