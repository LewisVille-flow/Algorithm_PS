"""
    시작 지점이 어디? -> 정해지지 않았다. 어디서든지 단순히 남쪽을 보고 있음.
    음... 왜 어렵지?
    1. 먼저 홍준이가 있을 위치 값을 시작점 0 기준 +- 값으로 표시
    2. 최대-최소 절대값으로 최소의 미로 변 크기 계산
    3. 최소점 기준으로 그림 생성
    
    - 좌표: 시작점 기준으로 배열 상 북쪽으로 위치.
    + 좌표: 시작점 기준으로 배열 상 남쪽으로 위치.
"""
import sys
input = sys.stdin.readline

## main
N = int(input())
move_history = input()
dir = [[1, 0, -1, 0],
       [0, -1, 0, 1]]       # S W N E
#print(move_history)

## function
cdir = 0
xpos_list = [0]
ypos_list = [0]
for _input in move_history:
    #_input = move_history[n]
    #print("input: ", _input)
    if _input == 'L':
        cdir = (cdir - 1) % 4
        #print(cdir)
    elif _input == 'R':
        cdir = (cdir + 1) % 4 
    elif _input == 'F':
        #print(dir[0][cdir])
        #print(xpos_list[-1], ypos_list[-1])
        nx, ny = xpos_list[-1] + dir[0][cdir], ypos_list[-1] + dir[1][cdir]
        xpos_list.append(nx)
        ypos_list.append(ny)
        #print(f"xpos: {nx}, ypos: {ny}")

max_x, max_y = max(xpos_list), max(ypos_list)
min_x, min_y = min(xpos_list), min(ypos_list)
row_size, col_size = abs(max_x - min_x + 1), abs(max_y - min_y + 1)
#print(row_size, col_size)
maze = [['#']*col_size for _ in range(row_size)]

start_x, start_y = abs(min_x), abs(min_y)       # 최솟값을 기준 점으로 지정해야, 저장된 pos를 더해서 인덱싱 가능

for xp, yp in zip(xpos_list, ypos_list):
    #print(f"xp: {xp}, yp: {yp}")
    maze[start_x + xp][start_y + yp] = '.'

#print(maze)
# "".join(map(str, row)) for row in maze) -> generator
sys.stdout.write("\n".join("".join(map(str, row)) for row in maze))