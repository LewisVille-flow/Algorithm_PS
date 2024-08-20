"""
    배열에서 가장 큰 값 출력하기
    13m
"""

import sys
import heapq
input = sys.stdin.readline
max_heap = []

N = int(input().strip())

for n in range(N):
    V = int(input().strip())

    if V == 0:  # 비어있는 경우 판단?
        if max_heap:
            print(heapq.heappop(max_heap)[1])
        else:
            print(0)
    else:
        heapq.heappush(max_heap, (-V, V))

        
