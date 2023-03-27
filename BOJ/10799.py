"""
    10:10-
    3+3+1 + 3+1
    ) 으로 닫힐 때마다, 레이저가 아닌 (으로 된 쇠막대기 개수만큼 + 를 해준다.
"""
import sys
input = sys.stdin.readline

input_list = str(input())
stick_stack = []
answer = 0

for i in range(len(input_list)):
    
    if input_list[i] == '(':
        stick_stack.append(input_list[i])
        
    
    elif input_list[i] == ')':
        # razor
        if input_list[i-1] == '(':
            stick_stack.pop()
            answer += len(stick_stack)
        # stick
        else:
            stick_stack.pop()
            answer += 1
print(answer)