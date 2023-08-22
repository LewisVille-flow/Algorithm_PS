import sys
input = sys.stdin.readline

# 0.
def solve():
    dp_array[0] = 1
    
    for i in range(N):
        for j in range(coins[i], M+1):
            dp_array[j] += dp_array[j-coins[i]]
    return dp_array[M]

# 1.
T = int(input())
for t in range(T):
    N = int(input())
    coins = list(map(int, input().split()))
    M = int(input())
    
    dp_array = [0] * (M+1)
    coins = sorted(coins)
    print(solve())