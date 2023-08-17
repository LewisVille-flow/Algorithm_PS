import sys
input = sys.stdin.readline

N = int(input().strip())
weights = []
for n in range(N):
    weights.append(int(input().strip()))
    
weights = sorted(weights)

##
available = []
for i in weights:
    available.append(i*N)
    N -= 1

print(max(available))

"""
4
1
1
1
3
## 4이어야 하나, 3을 출력한다.
"""