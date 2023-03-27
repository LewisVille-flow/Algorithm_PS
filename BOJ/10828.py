"""
    스택 구현문제.
    push, 
    pop, size, empty, top

"""
import sys
input = sys.stdin.readline

N = int(input())
answer_stack = []

for i in range(N):
    command = input().split()
    if command[0] == "push":
        push_number = command[1]

        # push
        answer_stack.append(push_number)
        continue
        
    if command[0] == "pop":
        if not len(answer_stack) == 0:
            # pop
            out = answer_stack.pop()
        else:
            out = -1
    
    if command[0] == "top":
        if not len(answer_stack) == 0:
            # pop
            out = answer_stack[-1]
        else:
            out = -1
    
    if command[0] == "size":
        # size
        out = len(answer_stack)
    
    if command[0] == "empty":
        # empty
        if len(answer_stack) == 0:
            out = 1
        else:
            out = 0
        
    print(out)