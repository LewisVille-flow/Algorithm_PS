import sys
input = sys.stdin.readline

# 0. function
def build_p(N):
    p = ""
    for i in range(N+1):
        p += ("IO")
    return p[:-1]

def solve_50score():
    answer = 0
    i = 0
    while i < M:
        if S[i] == "I":
            if i+(N+1)*2-1 <= M and build_p(N) == S[i:i+(N+1)*2-1]:
                answer += 1
                i += 2
                continue
        i += 1
    return answer

# two pointer
def solve():
    answer = 0
    left, right = 0, 0
    
    while right < M:
        if S[right:right+3] == 'IOI':
            right += 2
            if right-left == N*2:
                answer += 1
                left += 2  
        else:
            right += 1
            left = right
            
    return answer

# 1. input
N, M = int(input().strip()), int(input().strip())
S = str(input().strip())
# P_string = build_p(N)

print(solve())