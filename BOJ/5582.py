"""
    40m
    - LCS 응용
    - 값이 같을 때, 이전에도 같았다면 대각 성분에 값이 있을 것. 연속해야 하므로, 이전에도 값이 같은 경우에 +1이 필요.
    - 이전에는 값이 같지 않다면 1 기본 값
    - 최댓값 항상 저장
"""
import sys
input = sys.stdin.readline

string_a = str(input().strip())
string_b = str(input().strip())

dp_array = [[0 for _ in range(len(string_b)+1)] for _ in range(len(string_a)+1)]        # (string_a, string_b)
answer = 0

for i in range(1, len(string_a)+1):
    for j in range(1, len(string_b)+1):
        value = 0                                       # 문자열이 같지 않다면 0을 저장
        if string_a[i-1] == string_b[j-1]:
            value = max(dp_array[i-1][j-1]+1, 1)        # 이전까지 같았다면 그 전값 +1, 아니라면 그냥 1을 저장
            answer = max(answer, value)
        dp_array[i][j] = value
print(answer)
                