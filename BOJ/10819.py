## c++ 알고리즘 생각
"""
    1. 정렬?
    2. 그냥 냅다 하기. N<=8
"""
import sys
from itertools import permutations
input = sys.stdin.readline

## def
def Solution(_per: permutations):
    answer = -1
    for per in _per:
        sum = 0
        for i in range(len(per)-1):
            sum += abs(per[i] - per[i-1])
        if sum > answer:
            answer = sum
    
    print(answer)
    return

## main
N = map(int, input().split())
input_A = list(map(int, input().split()))

per = permutations(input_A)
Solution(per)