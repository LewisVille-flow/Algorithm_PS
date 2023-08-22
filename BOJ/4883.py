import sys
input = sys.stdin.readline

# 0.
def solve():
    dp_array[0] = tree[0]
    dp_array[0][2] = tree[0][1]+tree[0][2]
    dp_array[1][0] = dp_array[0][1]+tree[1][0]

    dp_array[1][1] = min(dp_array[0][1]+tree[1][1], dp_array[0][2]+tree[1][1], dp_array[1][0]+tree[1][1])
    dp_array[1][2] = min(dp_array[0][1]+tree[1][2], dp_array[0][2]+tree[1][2], dp_array[1][1]+tree[1][2])

    for i in range(2, N):
        
        dp_array[i][0] = min(dp_array[i-1][0]+tree[i][0], dp_array[i-1][1]+tree[i][0])
        dp_array[i][1] = min(dp_array[i-1][0]+tree[i][1], dp_array[i-1][1]+tree[i][1], dp_array[i-1][2]+tree[i][1], dp_array[i][0]+tree[i][1])
        dp_array[i][2] = min(dp_array[i-1][1]+tree[i][2], dp_array[i-1][2]+tree[i][2], dp_array[i][1]+tree[i][2])
        
    return dp_array[N-1][1]

# 1.
i = 1
while True:
    N = int(input())
    if not N:
        break
    tree = []
    for n in range(N):
        tree.append(list(map(int, input().split())))

    dp_array = [[0 for _ in range(3)] for _ in range(N)]
    print("%d. %d" %(i, solve()))
    i += 1