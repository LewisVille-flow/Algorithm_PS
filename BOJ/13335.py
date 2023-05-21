"""
    10:40-11:20
    bridge 위의 트럭 시간을 ++ 하는 것이 아니라 리스트의 길이 = 시간 으로 모델링하면 간단하다.
"""
import sys
input = sys.stdin.readline

# 1. input and queue
N, L, W = map(int, input().split())
trucks = list(map(int, input().split()))
bridge = [0] * L

# 2. loop
nW, T = 0, 0
while bridge:
    T += 1
    nW -= bridge.pop(0)
    if trucks:
        if nW + trucks[0] <= W:
            nW += trucks[0]
            bridge.append(trucks[0])
            trucks.pop(0)
        
        else:
            bridge.append(0)
print(T)
        