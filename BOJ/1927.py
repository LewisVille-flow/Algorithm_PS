"""
    최소 힙 - c++에서는 priority queue를 이용했다.
    자연수-> 추가, 0이면 가장 작은값 출력 삭제.

    파이썬: 힙큐라는 라이브러리 사용
    heappush, heappop, heapify
    heapush는 ("key", "item") 으로 우선순위를 지정해줄 수 있다.
"""

import sys
import heapq
input = sys.stdin.readline

min_heap = []

N = int(input())
for i in range(N):
    ith_number = int(input())
    
    if ith_number > 0:
        heapq.heappush(min_heap, ith_number)
        continue
    if ith_number == 0:
        if min_heap:
            out = heapq.heappop(min_heap)
        else:
            out = 0
        print(out)