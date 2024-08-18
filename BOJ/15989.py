"""
    80m
    - set에 모든 조합을 넣어두고, 다음 수로 넘어갈 때 이전 저장된 조합에 1씩 더 넣어두고, -2, -3 idx의 조합에 +2, +3 해보는 것?
        뭔가 dp 의 개념을 절반만 사용한 접근 같다.
    - 점화식 문제.
        - dp array row: 1만 사용해서 나타낼 때 / 1, 2만  / 1, 2, 3 만 사용해서
        - dp array col: 표현하고자 하는 수
        - dp array value: 중복을 제거한 가지 수
        규칙: 
            - 모든 수는 1만 사용해 최소 한 가지의 표현 방법이 있으므로, 초기화 = 1
            - 2를 포함하게 되는 경우: (i 번째 수를 1로만 표현하는 가지 수) + (i-2 번째 수를 1, 2로 표현한 가지 수 -> 이 표현 법에 모두 +2를 하면 되므로)
            - 3을 포함하게 되는 경우: (i 번째 수를 1, 2로만 표현하는 가지 수) + (i-3 번째 수를 1, 2, 3으로 표현한 가지 수 -> 이 표현 법에 모두 +3 을 하면 되므로)
            이전 인덱스 = 초기화: 이전 값만 사용한 경우 수로 초기화
"""

T = int(input().strip())
max_number = 10000

# dp array 1 만 사용한 경우 초기화
dp_array = [[1 for _ in range(max_number+1)] for _ in range(3)]     # (3 * 10001), col 은 1 부터 10000까지.

# dp array 1, 2만 사용한 경우 초기화
for col in range(1, max_number+1):
    if col < 2:
        dp_array[1][col] = dp_array[0][col]
    else:
        dp_array[1][col] = dp_array[0][col] + dp_array[1][col-2]

# dp array 1, 2, 3만 사용한 경우 초기화
for col in range(1, max_number+1):
    if col < 3:
        dp_array[2][col] = dp_array[1][col]
    else:
        dp_array[2][col] = dp_array[1][col] + dp_array[2][col-3]

for t in range(T):
    target_num = int(input().strip())
    # print(dp_array[0][:target_num+1])
    # print(dp_array[1][:target_num+1])
    # print(dp_array[2][:target_num+1])
    print(dp_array[2][target_num])
    