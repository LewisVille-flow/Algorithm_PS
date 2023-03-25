"""
    1. 생각나는 알고리즘
        south, east 방향으로 인접한 것이 다른지 탐색 -> 다르면 바꿔보고 -> 해당 방향 최대 개수 카운트, 업데이트
        교환은 한 번만 이루어진다고 한다.
        
    2. 마지막 행 생각 못했다.

"""
import sys
input = sys.stdin.readline

### def
def Count(_array: list):
    global answer, N
    ### row count
    for i in range(N):
        cnt = 1
        for j in range(N-1):
            if _array[i][j] == _array[i][j+1]:
                cnt +=1
            else:
                cnt = 1
            if cnt > answer:
                answer = cnt
    
    ### col count
    for j in range(N):
        cnt = 1
        for i in range(N-1):
            if _array[i][j] == _array[i+1][j]:
                cnt +=1
            else:
                cnt = 1
            if cnt > answer:
                answer = cnt
    return


def ChangeEast(row, col, _array: list):
    ## east
    if _array[row][col] != _array[row][col+1]:
        _array[row][col], _array[row][col+1] = _array[row][col+1], _array[row][col]
        Count(_array)
        _array[row][col], _array[row][col+1] = _array[row][col+1], _array[row][col]
    return

def ChangeSouth(row, col, _array: list):
    ## south
    if _array[row][col] != _array[row+1][col]:
        _array[row][col], _array[row+1][col] = _array[row+1][col], _array[row][col]
        Count(_array)
        _array[row][col], _array[row+1][col] = _array[row+1][col], _array[row][col]
    return

def Solution(_array: list):
    for i in range(N-1):
        for j in range(N-1):
            ChangeEast(i, j, _array)
            ChangeSouth(i, j, _array)
            
    for j in range(N-1):
        ChangeEast(N-1, j, _array)
    return


### main
N = int(input())
arr=[list(input().strip()) for _ in range(N)]
#arr = [input().strip() for _ in range(N)]
answer = -1

Solution(arr)
print(answer)