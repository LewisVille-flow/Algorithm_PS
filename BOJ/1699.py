"""
    19:11-
    dp 점화식을 세우기는 애매한데, 규칙은
        - 2, 3, 4, ... 의 제곱에 해당하는 수들은 1 로 저장
        - 초기값 1, 2, 3은 1, 2, 3
        - 4~N for 문 돌면서, 0인 경우(빈칸):
            - min(-1칸값+1, -2칸값+2, -3칸값+3, -N^2값 칸+1)
            - 이거 최적화가 가능한가? 무조건 -4칸 안에는 값이 있다는 게 어떻게 보장되지?
            - 한 칸씩 채우며 나아갈 거라 걱정 ㄴ
    -> 틀렸는데, 어디서 틀렸나면, 어떤 수 j의 제곱을 뺀 Idx 가 가지고 있는 값+1을 계속 j를 증가시키면서 비교해야 함.
    또한, 제곱수만큼 -indexing 할 때 최적화하려면, 확인하는 인덱싱 횟수가 최소여야 한다. 
"""
import math
N = int(input())
max_number = N+1

dp_array = [n for n in range(max_number+1)]    # 1~N까지 인덱싱, 초기값은 1로만 해당 idx 값을 만들었을 때.

for i in range(1, N+1):
    # j = 2
    # while (i-j*j) >= 0:        # 해당 위치에서 제곱수만큼 전으로 갔을 때의 표현 + 1이 계속 최소인지 반복해야 함.
    #     if dp_array[i] > dp_array[i-j*j]+1:
    #         dp_array[i] = dp_array[i-j*j]+1
    #     j+=1
    # while 조건절에서 j*j 를 계속 계산하는 것은 수가 커질 수록 계산량 증가로 시간 초과발생.
    for j in range(1, int(math.sqrt(i))+1):
        if dp_array[i] > (dp_array[i - j*j] + 1):
            dp_array[i] = dp_array[i - j*j] + 1
        
    
# print(dp_array[:N+1])

# for i in range(5, N+1):
#     before = [dp_array[i-1]+1, dp_array[i-2]+2, dp_array[i-3]+3, dp_array[i-4]+1]
#     if dp_array[i] != 0:
#         before.append(dp_array[i])
#     min_value = min(before)
#     dp_array[i] = min_value
    
# print(dp_array[:N+1])
print(dp_array[N])
