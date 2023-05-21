"""
    00:55-
"""
import sys
input = sys.stdin.readline
# 1. input
T = int(input().strip())

# 2. for loop and count
for t in range(T):
    day = 1
    max_food = int(input().strip())
    pe = list(map(int, input().split()))
    while True:
        now_food = sum(pe)
        if now_food > max_food:
            print(day)
            break
        
        next = [0 for i in range(6)]
        for pig in range(6):
            next[pig] = pe[pig] + pe[(pig-1)%6] + pe[(pig+1)%6] +pe[(pig+3)%6]

        day += 1
        pe = next
        
    
