"""
    20m
    열린 / 닫힌 괄호 개수를 세면 될까?
    레이저는 개수에 포함하지 않아야 하므로, 직전 값이 반대괄호면 더하지 않는다.
    
"""
from collections import deque
S = str(input().strip())
_stack = deque()

answer = 0
_stack.append(S[0])

for i in range(1, len(S)):
    n = S[i]
    if n == ')':
        _stack.pop()
        # bn = _stack[-1]
        if S[i-1] == '(':
            
            answer += len(_stack)
        else:
            # _stack.pop()
            answer += 1
    else:
        _stack.append(n)
    # print(n, _stack, answer)
print(answer)