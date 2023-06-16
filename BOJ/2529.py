"""
    100000000 = 10^9
    순열을 만드는 문제와 아주 같다. 조건만 잘 넣으면 된다.
"""
import sys
input = sys.stdin.readline

K = int(input().strip())
relation = list(map(str, input().strip().split()))
max_num, min_num = "-1", "9999999999"

def check_valid(before, now, check):
    if check == '<':    return before < now
    else:               return before > now

def Recursion(depth, visited):
    global max_num, min_num, K
    # print("depth, visited: ", depth, visited)
    if depth == K+1:
        num = "".join(map(str, visited))
        # print("return", min_num, max_num, num)
        if int(min_num) > int(num):
            min_num = num
        elif int(max_num) < int(num):
            max_num = num

        return
    
    for i in range(10):
        if depth == 0 or (i not in visited and check_valid(visited[depth-1], i, relation[depth-1])):

            visited.append(i)
            Recursion(depth+1, visited)
            visited.pop()


visited = []
Recursion(0, visited)

print(max_num)
print(min_num)