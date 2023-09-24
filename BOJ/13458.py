import sys
input = sys.stdin.readline

N = input().strip()
A = list(map(int, input().split()))
B, C = map(int, input().split())
answer = len(A)

for a in A:
    if a > B:
        div = (a-B)//C
        rest = (a-B)%C
        answer += div
        if rest:
            answer += 1
print(answer)
