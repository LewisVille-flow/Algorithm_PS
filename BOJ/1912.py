"""

"""
import sys
input = sys.stdin.readline

# 0.
def solve(input_array):
    max_sum = 0
    for i in range(0, len(input_array)):
        max_sum = max(max_sum+input_array[i], input_array[i])
        dp_array[i] = max_sum
    print(max(dp_array))
    print(dp_array)

# 1.
N = int(input())
input_array = list(map(int, input().split()))
dp_array = [0] * N
solve(input_array)