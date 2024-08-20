"""
    25m
    현재 가장 앞 수가 최소가 아니라면 다시 뒤로 빠꾸
    최소 == sorted의 해당 인덱스 값
    왼 / 오 판단 기준: 1~N의 큐를 가지고 같이 비교, 왼/오 가까운 액션 while
"""
import sys
from collections import deque
input = sys.stdin.readline

N, M = map(int, input().split())
grid = list(map(int, input().split()))
# sorted_grid = sorted(grid, reverse=False)
queue = deque([i for i in range(1, N+1)])

answer = 0
for idx, value in enumerate(grid):
    # print(queue, grid)
    while True:
        if value == queue[0]:                    # 뽑고자 하는 수가 맞을 경우
            queue.popleft()
            break
        else:
            answer += 1
            # 뽑고자 하는 수가 현재 위치로부터 왼 / 오 가까운 쪽 비교, deque는 리스트처럼 인덱싱이 가능
            if queue.index(value) > int(len(queue)/2):  # 오른쪽으로 이동
                queue.appendleft(queue.pop())
            else:
                queue.append(queue.popleft())
                
print(answer)