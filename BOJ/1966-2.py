import sys
input = sys.stdin.readline

T = int(input())
for t in range(T):
    N, M = map(int, input().split())
    queue = list(map(int, input().split()))
    printer = [(idx, imp) for idx, imp in enumerate(queue)]
    queue = sorted(queue, reverse=True)
    count = 0
    
    while queue:
        now_imp = queue.pop(0)
        while printer[0][1] != now_imp:
            printer.append(printer.pop(0))
        
        now_printer = printer.pop(0)
        count += 1
        if now_printer[0] == M:
            print(count)
            break
