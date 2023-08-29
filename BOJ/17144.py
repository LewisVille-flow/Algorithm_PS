import sys
input = sys.stdin.readline

# function
def solve(grid):
    dir_x = [0, 1, 0, -1]
    dir_y = [1, 0, -1, 0]
    
    for t in range(T):
        next_grid = [[0 for _ in range(C)] for _ in range(R)]
        for i in range(R):
            if grid[i][0] == -1:
                ux, lx = i, i+1
                uy, ly = 0, 0
                break
        upper_start, lower_start = (ux, uy), (lx, ly)
        next_grid[ux][0], next_grid[lx][0] = -1, -1
        
        # diffuse
        for i in range(R):
            for j in range(C):
                if grid[i][j] != 0 and grid[i][j] != -1:
                    count = 0
                    diffused_amount = grid[i][j]//5
                    
                    for dir in range(4):
                        nx, ny = i+dir_x[dir], j+dir_y[dir]
                        
                        if 0<=nx<R and 0<=ny<C and grid[nx][ny] != -1:
                            count += 1
                            next_grid[nx][ny] += diffused_amount
                    rest_amount = grid[i][j] - diffused_amount*count
                    next_grid[i][j] += rest_amount                    

        # rotate
        
        # upper part
        dir_x = [0, -1, 0, 1]
        dir_y = [1, 0, -1, 0]
        dir = 0
        cx, cy = ux, uy
        before = 0
        while True:
            nx, ny = cx+dir_x[dir], cy+dir_y[dir]
            
            if (nx, ny) == upper_start:
                break
            if nx<0 or nx>R-1 or ny<0 or ny>C-1:
                dir = (dir+1)%4
                continue
            next_grid[nx][ny], before = before, next_grid[nx][ny]
            cx, cy = nx, ny

        
        # lower part
        dir_x = [0, 1, 0, -1]
        dir_y = [1, 0, -1, 0]
        dir = 0
        cx, cy = lx, ly
        before = 0
        while True:
            nx, ny = cx+dir_x[dir], cy+dir_y[dir]
            
            if (nx, ny) == lower_start:
                break
            if nx<0 or nx>R-1 or ny<0 or ny>C-1:
                dir = (dir+1)%4
                continue
            next_grid[nx][ny], before = before, next_grid[nx][ny]
            cx, cy = nx, ny
        
        grid = next_grid.copy()

    return grid

# input
R, C, T = map(int, input().split())
grid = []
for r in range(R):
    grid.append(list(map(int, input().split())))
    
grid = solve(grid)

count = 0
for i in range(R):
    for j in range(C):
        if grid[i][j] != -1:
            count += grid[i][j]

print(count)