"""
    파이썬 2차원 배열...

"""
import sys
input = sys.stdin.readline
## main
H, W = map(int, input().split())
answer_list = [[-1]*W for _ in range(H)]

for h in range(H):
    _input = str(input().strip())
    for idx, w in enumerate(_input):
        if w == 'c':
            answer_list[h][idx] = 0
            
            row_iter = idx+1
            while row_iter < W:
                answer_list[h][row_iter] = answer_list[h][row_iter-1] +1
                row_iter += 1

for h in range(H):
    print(" ".join(map(str, answer_list[h])))
            


## function