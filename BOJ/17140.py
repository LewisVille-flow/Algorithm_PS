from collections import defaultdict
import sys
input = sys.stdin.readline

# function
def row_calculate(grid):
    max_length = 3
    rdict = []
    
    for i in range(len(grid)):
        ddict = defaultdict(int)
        for j in range(len(grid[0])):
            if grid[i][j] != 0:
                ddict[grid[i][j]] += 1
            max_length = max(max_length, len(ddict)*2)
        ddict = sorted(ddict.items(), key=lambda x:(x[1],x[0]))
        rdict.append(ddict)
    # new_grid = [[0 for _ in range(max_length)] for _ in range(len(grid))]
    new_grid = []
    
    for i in range(len(rdict)):
        each_row = []
        for j in rdict[i]:
            each_row.extend([j[0], j[1]])
        if len(each_row) < max_length:
            each_row.extend([0 for _ in range(max_length-len(each_row))])
        
        new_grid.append(each_row[:100])
    
    return new_grid


def col_calculate(grid):
    max_length = 3
    rdict = []
    
    for j in range(len(grid[0])):
        ddict = defaultdict(int)
        for i in range(len(grid)):
            if grid[i][j] != 0:
                ddict[grid[i][j]] += 1
                
            max_length = max(max_length, len(ddict)*2)
        ddict = sorted(ddict.items(), key=lambda x:(x[1],x[0]))
        rdict.append(ddict)
    # new_grid = [[0 for _ in range(max_length)] for _ in range(len(grid))]
    new_grid = []
    
    for i in range(len(rdict)):
        each_col = []
        for j in rdict[i]:
            each_col.extend([j[0], j[1]])
        if len(each_col) < max_length:
            each_col.extend([0 for _ in range(max_length-len(each_col))])

        new_grid.append(each_col[:100])
        
    ##
    new_grid = list(zip(*new_grid))

    return new_grid


def solve(grid, R, C, K):
    answer = 0
    
    while True:
        if len(grid)>=R and len(grid[0])>=C and grid[R-1][C-1] == K:
            return answer
        
        if answer == 100:
            return "-1"    

        answer += 1
        if len(grid) >= len(grid[0]):
            grid = row_calculate(grid)
        else:
            grid = col_calculate(grid)
            
# input
R, C, K = map(int, input().split())
grid = []

for r in range(3):
    grid.append(list(map(int, input().split())))

answer = solve(grid, R, C, K)
print(answer)