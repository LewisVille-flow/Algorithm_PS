import sys
input = sys.stdin.readline
N, W, L = map(int, input().split())

total_sec = 0
bridge_queue = [0]*W
trucks_waiting = list(map(int, input().split()))
now_weight = 0

def check_total_weight(queue, next):
    value = 0
    for i in queue:
        value += i
    return value+next

while trucks_waiting or now_weight > 0:
    total_sec += 1
    now_weight -= bridge_queue.pop(0)
    
    if trucks_waiting and now_weight+trucks_waiting[0] <= L:
        now_weight += trucks_waiting[0]
        bridge_queue.append(trucks_waiting.pop(0))
    else:
        bridge_queue.append(0)

print(total_sec)