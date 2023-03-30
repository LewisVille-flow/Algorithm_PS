"""
    우선순위 큐 - 가장 큰 수에서 하나씩 빼면서 비교하기
    1. 우선순위 큐에 2~N 득표수 넣기
    2. 가장 앞에있는 큰 수 빼고 본인 득표수 올리기
    3. 카운트
    4. 작업반복 2~3, 가장 큰 수가 본인보다 작을 때까지
    
    heappush, heappop, (key, value) 기본적으로 Min heap이다.
"""
import sys
import heapq
input = sys.stdin.readline
max_heap =[]

## main
N = int(input())
votes = []
for n in range(N):
    votes.append(int(input()))
dasom = votes.pop(0)
answer = 0

for v in votes:
    heapq.heappush(max_heap, (-v, v))

## function

while True and N != 1:
    if dasom > max_heap[0][1]:
        break
    else:
        out = heapq.heappop(max_heap)[1]
        out = out-1
        dasom += 1
        heapq.heappush(max_heap, (-out, out))
        answer += 1

print(answer)