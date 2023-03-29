"""
    1. 입력 리스트, 높이 값 비교 필요
    2. 가장 가까운 낮은 값 비교?
    3. 50만개에 대해 하나씩 비교 -> 시간초과
        -> 낮아지는 지점 기억 필요? 
        이전에서의 최대값 인덱스 &  i++하면서 해당 값보다 작으면 해당 인덱스저장, 아니면 갱신, 0
"""

import sys
input = sys.stdin.readline

# input
N = int(input())
building_height = list(map(int, input().split()))
answer = []
_stack = []

# function
max_height = building_height[0]
max_idx = 0

# for idx, height in enumerate(building_height):
#     while _stack:
#         if height > _stack[-1][1]:
#             _stack.pop()
#         else:
#             answer.append(_stack[-1][0])
#             break
#     else:
#         answer.append(0)
#     _stack.append([idx+1, height])
        
# print(" ".join(map(str, answer)))

# 2차 개선 : stack에 idx만 저장해보자
for idx in range(len(building_height)):
    # 현재가 더 높을 때
    while _stack and building_height[_stack[-1]] < building_height[idx]:
        _stack.pop()
        
    if _stack:
        answer.append(_stack[-1] + 1)
    else:
        answer.append(0)
    _stack.append(idx)

print(" ".join(map(str, answer)))

"""
    1. input 보다 높은 값이 나올 때까지 stack pop
    2. index = len(stack)
    3. 매번 스택을 복사하는 방법 말고는 없나 아 이게 전수조사지않나?
    으응 맞네, 높은 값이 있을 때만 저장해두고 뽑아 쓰면 된다.
"""