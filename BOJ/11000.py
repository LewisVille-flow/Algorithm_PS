"""
    50m
    
    필요한 최소 강의실의 개수?
    정렬(끝나는 시간이 빠른 순) - 맨 첫 원소(s, e) 에서 s 가 기록된 e 가 
        같거나 큰 경우 - 리스트 idx에다가 끝나는 시간 기록
        작은 경우 - 리스트 추가
    
    답 = 리스트 길이 -> 리스트 길이로 하면 계속 조회하는 데 O(3N)을 사용하므로 시간 초과 -> 우선순위 큐를 사용하며 pop, append
    
    개선) 현재 시점에서 진행 중인 수업들만 우선순위 큐에 넣는다.
    끝나는 시점이 빠른 수업이 우선순위인 건 여전.
    새로운 수업의 시작시간이 가장 빨리 끝나는 수업의 e 보다 늦으면 새로 추가. 
    답은 그냥 정수
    
    + 수업시간은 게속 정렬해줄 필요가 없으므로 그냥 1회 정렬.
"""

import sys
import heapq
input = sys.stdin.readline

N = int(input().strip())
cmin_heap, nmin_heap = [], []
# num_classrooms = []     # e 값 저장
answer = 1

for n in range(N):
    s, e = map(int, input().split())
    heapq.heappush(cmin_heap, (s, e))        # e, s 에 주의(순서)

# 초기값
(ns, ne) = heapq.heappop(cmin_heap)
heapq.heappush(nmin_heap, (ne, ns))

while cmin_heap:
    (ns, ne) = heapq.heappop(cmin_heap)
    
    if ns >= nmin_heap[0][0]:        # 새 수업시간이 이전 수업 종료시간과 같거나 크다면
        heapq.heappop(nmin_heap)
    else:
        answer += 1
    heapq.heappush(nmin_heap, (ne, ns))
    
    

# while min_heap:                             # 힙정렬 O(log N) 을 N회 수행
#     # print(min_heap, "\t", num_classrooms)
#     (e, s) = heapq.heappop(min_heap)
    
#     if all([s<i for i in num_classrooms]):  # O(N)
#         num_classrooms.append(e)
#     elif any([s==i for i in num_classrooms]):
#         num_classrooms[num_classrooms.index(s)] = e
#     else:
#         for i in range(len(num_classrooms)):
#             if i < s:
#                 num_classrooms[i] = e

print(answer)