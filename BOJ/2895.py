N, M = map(int, input().split())
 
trees = list(map(int, input().split()))

def solve():
    min_height = 1
    max_height = max(trees)
    
    while max_height>=min_height:
        middle = int((min_height+max_height)/2)
        now_get = 0
        
        for t in trees:
            if t > middle:
                now_get += (t-middle)
        
        if now_get >= M:     # 더 크게 잘라야 한다.
            min_height = middle+1
        elif now_get < M:   # 더 작게 잘라야 한다.
            max_height = middle-1
    
    return max_height       # 크거나 같을 경우 min + 1 이므로, while 을 벗어나게 되는 경우 max 가 정답

print(solve())
    
