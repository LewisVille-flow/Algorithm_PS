import sys
input = sys.stdin.readline


# 1. input
answer_list = []
while True:
    in_number = input().strip()
    if in_number == '0':
        break
    
    if str(in_number) == str(in_number)[::-1]:
        answer_list.append("yes")
    else:
        answer_list.append("no")
    
print("\n".join(map(str, answer_list)))