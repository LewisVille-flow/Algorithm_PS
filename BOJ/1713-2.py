import sys
input = sys.stdin.readline

N = int(input())
T = int(input())
students = list(map(int, input().split()))

board_st = []
board_rec = []


for idx, st in enumerate(students):
    if st in board_st:
        st_idx = board_st.index(st)
        board_rec[st_idx] += 1
        
    else:
        if len(board_st) == N:
            min_idx = board_rec.index(min(board_rec))
            del(board_st[min_idx])
            del(board_rec[min_idx])
        
        board_st.append(st)
        board_rec.append(1)

board_st = sorted(board_st)
print(" ".join(map(str, board_st)))