import sys
input = sys.stdin.readline

# 0.
def solve():
    for n in range(N):
        # max_length = n. 0과 n은 직전 층 1개밖에 참조 못함
        
        if n == 0:
            dp_array[n] = [triangle[0][0]]
            continue
        
        dp_element = [-1]*(n+1)
        for i in range(0, n+1):
            if i == 0:      dp_element[i] = triangle[n][i] + dp_array[n-1][i]
            elif i == n:  dp_element[i] = triangle[n][i] + dp_array[n-1][i-1]
            else:
                dp_element[i] = max(triangle[n][i]+dp_array[n-1][i-1], triangle[n][i]+dp_array[n-1][i])
        dp_array.append(dp_element)

    print(max(dp_array[N-1]))
    return

# 1. input
N = int(input())
triangle = []
for n in range(N):
    triangle.append(list(map(int, input().split())))
dp_array = [-1]
solve()
print(triangle, dp_array)