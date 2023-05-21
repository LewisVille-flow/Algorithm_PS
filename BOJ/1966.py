"""
    11:40-
    특정 문서가 몇 번째에 인쇄되는지 확인하기
    내가 알고싶은 위치가 max가 아니면 다시 맨 뒤로 간다 -> idx 초기화
    idx 초기화 방식은 겉으로 보기에 이해하기 어렵다.
"""
import sys
from collections import deque
input = sys.stdin.readline

# 1. input
T = int(input())
for t in range(T):
    N, M = map(int, input().split())
    queue = list(map(int, input().split()))
    printer = [(idx, imp) for idx, imp in enumerate(queue)]
    queue = sorted(queue, reverse=True)
    count = 0
    
    while queue:
        most_imp = queue.pop(0)
        while printer[0][1] != most_imp:
            printer.append(printer.pop(0))
        now = printer.pop(0)
        count += 1
        if now[0] == M:
            print(count)
            break

            

    