"""
    T 초 후 개미의 순서
    아이디어 1. 
        - 리스트에서 각 원소는 방향, 알파벳을 보유
        - 1~T 횟수만큼 전체 완전탐색, 현재 위치와 현재위치 +1 인 개미가 방향이 다르면 change
        - 마지막에는 알파벳 성분만 출력
"""
import sys
input = sys.stdin.readline

## main
N1, N2 = map(int, input().split())
N1_list = list(input().strip())
N2_list = list(input().strip())
T = int(input())
#print(N1_list, N2_list, T, N1, N2)
N1_list = N1_list[::-1]

# # ## function
# N11_list = N1_list.copy()
# N11_list.extend(N2_list)
# ant_list = N11_list

# for t in range(T):
#     for idx in range(len(ant_list)-1):
#         if ant_list[idx] in N1_list and ant_list[idx+1] in N2_list:
#             ant_list[idx], ant_list[idx+1] = ant_list[idx+1], ant_list[idx]
            
#             if ant_list[idx+1] == N1_list[-1]:
#                 break
            
# print("".join(ant_list))


## 이 방식으로는... 방향만 다르면 무조건 바꾸기 때문에 틀림. 한 그룹은 한 방향으로만 이동해야함.
# ## function
ant_now = [(1, al) for al in N1_list]
ant_now_2 = [(-1, al) for al in N2_list]
ant_now.extend(ant_now_2)
#print(ant_now)

for t in range(T):
    #idx = 0
    #while idx < len(ant_now)-1:
    for idx in range(len(ant_now)-1):
        cdir, cname = ant_now[idx]
        ndir, nname = ant_now[idx+1]
        #print(t, idx, cdir, cname)
        #if cdir != ndir:            # 이렇게 하는게 아니라,     cdir == 1 and ndir == -1 이렇게.
        if cdir == 1 and ndir == -1:    
            ant_now[idx], ant_now[idx+1] = ant_now[idx+1], ant_now[idx]
            if ant_now[idx+1][1] == N1_list[-1]:
                break
        

    #print(f"in t: {t}", "".join(name for _, name in ant_now))

## print
print("".join(name for _, name in ant_now))
