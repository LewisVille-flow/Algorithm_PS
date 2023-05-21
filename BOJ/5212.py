"""
09:41-09:50, 00:20-00:50
아, 이전 값 변화에 영향을 받으면 안 되니까 copy를 쓰는군.
"""
import sys, copy
input = sys.stdin.readline

def OutRange(x, y):
    return x<0 or x>row-1 or y<0 or y>col-1

# 1. input, 섬 위치 기억
row, col = map(int, input().split())
grid = []
for r in range(row):
    grid.append(list(input().strip()))
grid_after = copy.deepcopy(grid)

# 2. 섬 위치 주변 탐색 - 잠기는지 확인. 상하좌우
dir = [[0, 1, 0, -1],
       [1, 0, -1, 0]]

not_be_sea = []

# 3. 잠기는 구역 제거
for r in range(row):
    for c in range(col):
        cur = grid[r][c]
        sea_count = 0
        if cur == 'X':
                
            for d in range(4):
                nx, ny = r + dir[0][d], c + dir[1][d]
                
                # 파이썬도 or 이고 앞에거가 true 면 뒤에 조건 안 보나?
                if OutRange(nx, ny) or grid[nx][ny] == '.':
                    sea_count +=1
            
            if sea_count >= 3:
                grid_after[r][c] = '.'
            else:
                not_be_sea.append((r, c))


# 4. 가장 작은 직사각형 표시 - min max x, y
# not_be_sea = sorted(not_be_sea, key=lambda x:x[0])
min_row, max_row = not_be_sea[0][0], not_be_sea[-1][0]
not_be_sea = sorted(not_be_sea, key=lambda x:x[1])
min_col, max_col = not_be_sea[0][1], not_be_sea[-1][1]

# 출력 부분이 귀찮고 어려운듯.
# min row, max row, min col, max col 좌표를 안다면
for c in range(min_row, max_row+1):
    print(''.join(grid_after[c][min_col:max_col+1]))
