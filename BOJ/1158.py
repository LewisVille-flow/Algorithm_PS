"""
    0908~0935
"""

import sys
from collections import deque
input = sys.stdin.readline

# 1. 큐
answer = []

n, k = map(int, input().split())
line = deque(range(1, n+1))
# line = [i for i in range(1, n+1)]
# 2. 3번째 원소 탐색
idx = k-1
# while line:
#     if idx > len(line)-1:
#         idx = idx % len(line)
#     answer.append(line[idx])
#     line.pop(idx)
#     idx += k-1

while line:
    for i in range(k-1):
        line.append(line.popleft())
    answer.append(line.popleft())    

print(str(answer).replace('[' , '<').replace(']', '>'))
# 3. 출력