"""
    13m
    뭔가 가장 작은 수 부터 둘이 더하는 게 나아 보인다.
    뭘 놓치고 있는가?
"""

import sys
import heapq
input = sys.stdin.readline

N = int(input().strip())
min_heap = []
for n in range(N):
    v = int(input().strip())
    heapq.heappush(min_heap, (v, v))

answer = 0
while len(min_heap) > 1:
    # print(min_heap)
    fv = heapq.heappop(min_heap)[1]
    sv = heapq.heappop(min_heap)[1]
    
    nv = fv+sv
    answer += nv
    heapq.heappush(min_heap, (nv, nv))
# answer += heapq.heappop(min_heap)[1]
print(answer)