"""
    dp_array : 현재 원소를 포함할 때 증가하는 부분 수열 길이
"""
import sys
input = sys.stdin.readline

# 0.
def solve(input_array):
    for i in range(1, len(input_array)):
        max_value = 0
        for j in range(0, i):
            if input_array[j] < input_array[i]:
                max_value = max(dp_array[j], max_value)
        dp_array[i] = max_value + 1
    print(max(dp_array))

# 1.
N = int(input())
input_array = list(map(int, input().split()))
dp_array = [1] * N

# 2.
solve(input_array)