# 1. variable settings
grid = []
grid_copy = []

virus = []
max_result = 0

# 2. functions setting
def Spread_Virus_DFS(x, y):
    dx = [0, 0, -1, 1]
    dy = [-1, 1, 0, 0]

    for i in range(4):
        new_x = x + dx[i]
        new_y = y + dy[i]

        if 0 <= new_x and 0 <= new_y and new_x < N and new_y < M and grid_copy[new_x][new_y] != 1 and grid_copy[new_x][new_y] != 2:
            grid_copy[new_x][new_y] = 2
            Spread_Virus_DFS(new_x, new_y)

## 2.1 Function Spread Virus
def Spread_Virus():
    global max_result

    result = 0
    
    # spread virus - BFS
    for i in range(len(virus)):
        x, y = virus[i][0], virus[i][1]
        
        Spread_Virus_DFS(x, y)

    # count safety area
    for i in grid_copy:
        for j in i:
            if j == 0:
                result += 1
              
    #print('result: ', result)
    max_result = max(max_result, result)

## 2.1 Function Make Walls
def Create_Wall(cnt):
    if cnt == 3:
        global grid_copy
        grid_copy = [[0] * M for i in range(N)]

        for i in range(N):
            for j in range(M):
                grid_copy[i][j] = grid[i][j]

        Spread_Virus()
        return

    # brute force
    for i in range(N):
        for j in range(M):
            if grid[i][j] == 0:
                # backtracking
                grid[i][j] = 1
                Create_Wall(cnt + 1)    # recursion
                grid[i][j] = 0


# 3. Main
## 3.1 input init                
N, M = map(int, input().split())

for i in range(N):
    grid.append(list(map(int, input().split())))

for i in range(N):
    for j in range(M):
        if grid[i][j] == 2:
            virus.append([i, j])

## 3.2 function start
Create_Wall(0)
print(max_result)