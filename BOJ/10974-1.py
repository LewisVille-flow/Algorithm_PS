"""
    순열을 사전순으로 -> 재귀
"""

import sys
input = sys.stdin.readline

N = int(input().strip())
numbers = []
included = set()

def Recursion(now, total):
    if total == N:
        print(" ".join(map(str, numbers)))
        return
    
    for i in range(1, N+1):
        if i not in included:
            included.add(i)
            numbers.append(i)
            Recursion(i, total+1)
            included.remove(i)
            numbers.pop()

Recursion(0, 0)
