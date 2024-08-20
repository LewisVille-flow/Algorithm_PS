"""
    15m
    태그를 제외한 단어를 스페이스 기준으로 분리하고 역순으로 만들기
    
    단어의 개수는 모른다.
    태그가 아닌 영역의 경우 스택에 넣고, 스페이스바를 만나면 출력
    
    
"""
import sys
from collections import deque

input = sys.stdin.readline
_stack = deque()

input_string = str(input().strip())
answer = ""

flag = False
for s in input_string:
    if s == '<':
        flag = True
        if _stack:
            for _ in range(len(_stack)):
                n = _stack.pop()
                answer += n
        answer += s
        continue
    if s == '>':
        flag = False
        answer += s
        continue
    if flag:
        answer += s
        continue
    
    if s != ' ':
        _stack.append(s)
    if s == ' ' and _stack:
        for _ in range(len(_stack)):
            n = _stack.pop()
            answer += n
        answer += ' '
    elif s == ' ':
        answer += s
if _stack:
    for _ in range(len(_stack)):
        n = _stack.pop()
        answer += n

print(answer)
    