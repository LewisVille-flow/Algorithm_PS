"""
    1. 완전탐색 ? -> 최대 20C1 + 20C2 + ... 20C21
"""
import sys
input = sys.stdin.readline
"""
## function
def Solve(idx: int, _list: list):
    global answer
    if idx >= N:
        return
    
    _list.append(_input[idx])
    if sum(_list) == S:
        answer += 1
    
    Solve(idx+1, _list)
    _list.pop()
    Solve(idx+1, _list)
        
    return

N, S = map(int, input().split())
_input = list(map(int, input().split()))
answer = 0

output = []
Solve(0, output)

print(answer)"""

### second solution using combination
from itertools import combinations

N, S = map(int, input().split())
_input = list(map(int, input().split()))
answer = 0

for i in range(1, N+1):
    comb = combinations(_input, i)
    
    for each_comb in comb:
        if sum(each_comb) == S:
            answer += 1
            
print(answer)