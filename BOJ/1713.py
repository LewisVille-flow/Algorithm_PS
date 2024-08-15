"""
    Strategy:
    - 리스트 큐, (학생 번호, 추천 수)
    - 오래된 순 == 가장 왼쪽
    - 이미 있는 학생이 추천된다 == 다시 오른쪽으로 삽입
        즉 리스트 큐 전체 탐색 함수가 있어야 함.
    출력: 정렬
"""
import sys
from collections import defaultdict
input = sys.stdin.readline

N = int(input())
T = int(input())
students_recommend = list(map(int, input().split()))
board = defaultdict(0)

for idx, st in enumerate(students_recommend):
    if board.get(st, False):
        board[st] += 1
    else:
        if len(board) == N:
            students = list(board.keys())
            rec = list(board.values())
            min_idx = rec.index(min(rec))   # 앞에 있는 값 먼저 인덱싱 리턴
            min_idx = students[min_idx]     # 동일하게 적은 수의 추천을 받았다면, 오래된 놈부터 제거해야 함.
            
            del(board[min_idx])             # defaultdict의 특성상 먼저 추천된 놈이 먼저 key로 등록됨
        board[st] = 1

board = sorted(board.keys())
print(" ".join(map(str, board)))