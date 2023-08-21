import sys
input = sys.stdin.readline

# 0.
def Recursion(X):
    if X == 1:
        return dp_array[1]
    if dp_array[X] != 0:
        return dp_array[X]
    
    if X%2 == 0 and X%3 == 0:
        dp_array[X] = min(Recursion(X//2)+1, Recursion(X//3)+1)
    elif X%2 == 0:
        dp_array[X] = min(Recursion(X//2)+1, Recursion(X-1)+1)
    elif X%3 == 0:
        dp_array[X] = min(Recursion(X//3)+1, Recursion(X-1)+1)
    else:
        dp_array[X] = Recursion(X-1)+1
        
    return dp_array[X]

# 1.
X = int(input())
dp_array = [0] * (X+1)
dp_array[0] = 0
dp_array[1] = 0
if X > 2:
    dp_array[2] = 1
    dp_array[3] = 1

print(Recursion(X))