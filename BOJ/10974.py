"""
    1. 조합(combination): 그냥 라이브러리 쓰면 됨 -> 아니네, 순열 해야하는구나. permutation.
    2. 재귀적 구현 - 중복없이 + 사전 순
        내가 이전 스텝에서 어떤 원소를 넣었는지, 어떤 원소들이 남았는지 알아야 함.
        인자: 현재까지 넣은 원소 개수, 목표 depth, 배열을 계속 넘겨야하나? -> cpp: visited 배열을 썼었다. python: 탐색?
        
        python-> visited list보다는 중복이 없다면 set이 더 빠르다(크기가 커질 때)
"""
import sys
input = sys.stdin.readline

### def
def Solution(cur_num: int, target_num: int):
    # exit condition
    if cur_num == target_num:
        print(' '.join(map(str, answer_list)))
        return

    for i in range(0, target_num):
        if i not in visited:
            visited.add(i)
            answer_list.append(i+1)
            Solution(cur_num+1, target_num)
            answer_list.pop()
            visited.remove(i)
    
    return

### main
N = int(input())
answer_list = []
#visited = [0 for _ in range(0, N)]
visited = set()

Solution(0, N)