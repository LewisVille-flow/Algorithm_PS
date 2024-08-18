import sys
input = sys.stdin.readline

N, K = map(int, input().split())
weight, values = [0], [0]
for n in range(N):
    w, v = map(int, input().split())
    weight.append(w)
    values.append(v)
dp_grid = [[0]*(K+1) for _ in range(N+1)]

def backpack():
    # 초기 값을 아래와 같이 지정해주거나, 0번째 idx에 대해 weight, value를 0으로 초기화해주거나가 필요함.
    # for w in range(weight[0], K+1):
    #     dp_grid[0][w] = values[0]
    
    for item_idx in range(1, N+1):               # idx 0~N-1
        for weight_idx in range(1, K+1):    # idx 1~K
            now_weight = weight[item_idx]
            now_value = values[item_idx]
            
            if weight_idx >= now_weight:
                dp_grid[item_idx][weight_idx] = max(dp_grid[item_idx-1][weight_idx], dp_grid[item_idx-1][weight_idx-now_weight]+now_value)
            else:
                dp_grid[item_idx][weight_idx] = dp_grid[item_idx-1][weight_idx]

    # print(weight, values)
    # print(dp_grid)

backpack()
print(dp_grid[N][K])