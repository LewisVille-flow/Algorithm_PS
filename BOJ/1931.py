"""
    1. 시작시간 오름차순으로 정렬 후 끝나는 시간 <= 다음 시작시간 그리디하게 계속 탐색, max 출력
    2. 가장 빨리 끝나는 회의를 먼저 배정
"""

import sys
input = sys.stdin.readline

N = int(input())
meeting = []
for n in range(N):
    meeting.append(tuple(map(int, input().split())))

meeting = sorted(meeting, key=lambda x:(x[1], x[0]), reverse=False)
print(meeting)
max_number = 1
end = meeting[0][1]
for n in range(1, N):
    if meeting[n][0] >= end:
        max_number += 1
        end = meeting[n][1]

print(max_number)