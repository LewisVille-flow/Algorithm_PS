"""
    딕셔너리?
    파이썬에서는 자동 타입 설정되니까 걱정안해도 되려나.
"""
import sys
input = sys.stdin.readline

## main
N = int(input())
answer_dict = {}

for n in range(N):
    _in = int(input())
    if _in in answer_dict:
        answer_dict[_in] += 1
    else:
        answer_dict[_in] = 1

#answer_dict = sorted(answer_dict.items(), key=lambda item:item[1], reverse=True)
answer_list = sorted(answer_dict.items(), key=lambda item:(-item[1], item[0]))
# 먼저 개수 순으로 내림차순 정렬, 만약 개수가 같다면 item[0], 즉 키 값이 작은 순서대로 오름차순.

# print(answer_dict)
print(answer_list[0][0])
