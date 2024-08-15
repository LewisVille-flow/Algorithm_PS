"""
    30m
    Stratgy:
    - 남학생 상태 변환 함수
    - 여학생 대칭 상태 확인 함수
        - 범위 내 & 값이 같으면 -> +1후 %2
    
    입력되는 스위치 번호가 idx보다 1 큼에 주의
"""
import sys
input = sys.stdin.readline

N = int(input())
switches = [0] + list(map(int, input().split()))
NS = int(input())

def boys(_switches: list, idx: int) -> list:
    for i in range(idx, N+1, idx):
        _switches[i] = (_switches[i] + 1)%2
    return _switches

def girls(_switches: list, idx: int) -> list:
    i = 1
    _switches[idx] = (_switches[idx] + 1)%2
    while (idx-i>0 and idx+i<=N) and (_switches[idx-i] == _switches[idx+i]):
        _switches[idx-i] = (_switches[idx-i] + 1)%2
        _switches[idx+i] = (_switches[idx+i] + 1)%2
        i += 1
    return _switches

for i in range(NS):
    sex, idx = map(int, input().split())
    if sex == 1:
        switches = boys(switches, idx)
    else:
        switches = girls(switches, idx)

switches.pop(0)
for i in range(0, len(switches), 20):
    print(" ".join(map(str, switches[i:i+20])))