"""
    10:09-10:24, 15m
    10:30-
"""
import sys
input = sys.stdin.readline

max_value = 10001
answer_list = [0]*max_value

# def recursion(num_now):
#     num_now_str = str(num_now)

#     for s in num_now_str:
#         num_now += int(s)
#     num_next = num_now

#     if num_next > max_value-1:
#         return
    
#     answer_list[num_next] += 1
    
#     return recursion(num_next)

# for i in range(1, 101):
#     recursion(i)
    
#     if answer_list[i] == 0:
#         print(i)
answer_set = set(range(1, max_value))
not_self_number_set = set()

for i in range(1, max_value):
    not_self = i
    for j in str(i):
        not_self += int(j)

    not_self_number_set.add(not_self)

answer_set = sorted(answer_set - not_self_number_set)

print("\n".join(map(str, answer_set)))