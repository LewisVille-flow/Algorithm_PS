"""
    24m
    - 문자열로 1, 2, 3 append, 출력은 "+".join
    - 문자열 append 시 순서를 지키기 위해 왼쪽으로 append, 그리고 1, 2, 3 순서로 append
    - 이건 변칙적인 풀이 같긴 하다.
"""
N, K = map(int, input().split())

dp_grid = [[] for _ in range(11)]  # 1~n indexing

dp_grid[1] = ["1"]
dp_grid[2] = ["11", "2"]
dp_grid[3] = ["111", "12", "21", "3"]

for k in range(4, N+1):
    first   = ["1" + ele for ele in dp_grid[k-1]]
    second  = ["2" + ele for ele in dp_grid[k-2]]
    third   = ["3" + ele for ele in dp_grid[k-3]]
    
    dp_grid[k] = first + second + third

if K <= len(dp_grid[N]):
    print(len(dp_grid[N]))
    print("+".join(dp_grid[N][K-1]))
else:
    print("-1")
