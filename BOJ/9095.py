"""
    8m
"""
T = int(input().strip())
max_number = 10

dp_array = [1] * (max_number+1)     # 1~ maxnumber indexing

dp_array[1] = 1
dp_array[2] = 2
dp_array[3] = 4
for i in range(4, max_number+1):
    dp_array[i] = dp_array[i-1] + dp_array[i-2] + dp_array[i-3]

for t in range(T):
    n = int(input().strip())
    print(dp_array[n])
    
