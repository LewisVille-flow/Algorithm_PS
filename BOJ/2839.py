"""

"""
import sys
input = sys.stdin.readline

N = int(input().strip())
dp = [-1]*(5000+1)
dp[3] = 1
dp[5] = 1

if N <=5:
    answer = dp[N]
    
else:
    for i in range(6, N+1):
        if dp[i-3] != -1 and dp[i-5] != -1:
            dp[i] = min(dp[i-3]+1, dp[i-5]+1)
        
        elif dp[i-3] != -1:
            dp[i] = dp[i-3]+1
        elif dp[i-5] != -1:
            dp[i] = dp[i-5]+1
    
    answer = dp[N]
# print(' '.join(map(str, dp)))
print(answer)