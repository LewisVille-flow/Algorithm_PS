"""
    효율성을 따지지 않고, 그냥 완전 탐색하면...
    
"""

import sys
input = sys.stdin.readline

N = int(input().strip())
grid = [list(map(int, input().split())) for i in range(N)]

visited = set()
total_fee = 9999999

def Recursion(start, now, cur_fee, num_visited):
    global total_fee
    if num_visited == N-1:
        if grid[now][start]:
            cur_fee += grid[now][start]
            total_fee = min(cur_fee, total_fee)
        return
    
    if cur_fee > total_fee:
        return
    
    for next in range(N):
        next_fee = grid[now][next]

        if next_fee != 0 and next not in visited:
            visited.add(next)
            Recursion(start, next, cur_fee+next_fee, num_visited+1)
            visited.remove(next)

for i in range(N):
    visited.add(i)
    Recursion(i, i, 0, 0)
    visited.remove(i)
print(total_fee)
            