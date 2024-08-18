"""
    백트래킹으로 풀어보기. 20m
    1, 2, 3 순서대로 리스트에 넣으며,
    합이 N인 경우 종료하며 global cnt +=1,
    cnt == K 인 경우 출력하며 종료 sys.exit(0)
"""
import sys
input = sys.stdin.readline

numbers = [1, 2, 3]
N, K = map(int, input().split())
queue = []
global answer, cnt
cnt = 0
answer = -1

def recursive(sum: int):
    global answer, cnt
    # print(f"\n>> sum: {sum}, cnt: {cnt}, q: {queue}")
    if sum == N:
        cnt += 1
        if cnt == K:
            answer = "+".join(map(str, queue))
            print(answer)
            sys.exit(0)
        else:
            return
    
    for i in numbers:
        if sum+i <= N:
            queue.append(i)
            recursive(sum+i)
            queue.pop()
            
recursive(0)
print(answer)