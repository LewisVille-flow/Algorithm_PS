
import sys
input = sys.stdin.readline

N, K = map(int, input().split())
NS = []
for i in range(N):
    NS.append(int(input().strip()))

##
answer = 0
for i in range(N-1, -1, -1):
    
    if NS[i] <= K:
        answer += K//NS[i]
        K = K%NS[i]
        
    if K == 0:
        break
print(answer)