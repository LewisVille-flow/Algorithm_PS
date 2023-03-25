"""
    - m개 중에 n 개 고르고 출력하기
    - 출력문 사이에 공백, 테스트케이스마다 줄바꿈
"""
import sys
input = sys.stdin.readline

## def
def Solution(num: int, depth: int):
    if depth == 6:
        #print(' '.join(map(str, list_out)))
        print(*list_out)
        return
    
    for el in range(num, len(input_list)):
        list_out.append(input_list[el])
        Solution(el+1, depth+1)
        list_out.pop()
        
    return

while True:
    ## main
    input_list = list(map(int, input().split()))
    N = input_list[0]
    input_list.pop(0)
    
    if N == 0:
        break
    
    list_out = []
    Solution(0, 0)
    print()
