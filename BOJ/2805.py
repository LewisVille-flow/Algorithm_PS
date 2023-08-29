import sys
input = sys.stdin.readline

# function
def solve():
    left, right = min(trees), max(trees)
    
    while right >= left:
        mid = int((right+left)/2)
        amounts = 0
        for t in trees:
            if t>mid: amounts += (t-mid)
        
        if amounts > M:
            left = mid+1
        else:
            right = mid-1
    
    return right

# input
N, M = map(int, input().split())
trees = list(map(int, input().split()))

answer = solve()
print(answer)