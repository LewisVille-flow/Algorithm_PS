"""
    10:46-
    1. 브루트포스로 계속 큐 돌려가면서?
    2. 위치는 알 수 있는데 이걸 갖고 바로 어떻게하지
        숫자 search - 앞 뒤 짧은 쪽 구분 - 떼어내고 reverse, 앞 혹은 뒤로 붙이기 - 개수 세기?
        처음 idx == 값이다
"""

# 리스트로 구현해보기
## main
"""import sys
input = sys.stdin.readline

N, M = map(int, input().split())
target_idx = list(map(int, input().split()))
queue = [i for i in range(1, N+1)]
answer = 0

## function
for m in range(M):
    while True:
        if queue[0] == target_idx[m]:
            queue.pop(0)
            break
        else:
            answer += 1
            if queue.index(target_idx[m]) < len(queue)/2:
                queue.append(queue[0])
                queue.pop(0)
            else:
                queue.insert(0, queue.pop())

print(answer)"""

# deque로 해보기
from collections import deque
import sys
input = sys.stdin.readline

N, M = map(int, input().split())
target_idx = list(map(int, input().split()))
dq = deque([i for i in range(1, N+1)])
answer = 0

for tar in target_idx:
    while True:
        if dq[0] == tar:
            dq.popleft()
            break
        else:
            answer += 1
            if dq.index(tar) < len(dq)/2:
                dq.append(dq.popleft())
            else:
                dq.appendleft(dq.pop())
print(answer)