"""
    각 손님들이 원하는 곳에 도착하게 되는 시간 출력
    최대 인원 M 이동시간 t, N 명의 손님
    
    현재 시간을 기록해야 함. 현재 시간보다 낮은 시간의 사람들을 큐에서 뽑아가면서 시간 + 이동시간 더해서 출력
    왜 골드3이지? 
    - 아 왼쪽 오른쪽 구분해야 한다.
    - 현재 나룻배의 위치를 알아야 한다.
    - 손님의 도착시간이 현재 시간과 엄청 차이날 수 있다.
    - 먼저 pop하는 것으로 해서 현재 시간을 이동시켜야한다.
    - left 와 right를 구분해야한다.
"""
## main - 힙 안써도 될거같은데.
import sys, heapq
input = sys.stdin.readline

M, T, N = map(int, input().split())
people = {"left":[], "right":[]}
for n in range(N):
    ti, lo = map(str, input().split())
    #heapq.heappush(people, (int(ti), lo))
    if lo == 'left':
        people[lo].append((n, int(ti)))
    else:
        people[lo].append((n, int(ti)))

answer = [0 for _ in range(N)]
boat_loc = "left"
current_t = 0
total_move_count = 0

#print(people[boat_loc])

## function
while total_move_count < N:

    #print("now time and loc: ", current_t, boat_loc)
    if boat_loc == 'left':  other_loc = 'right'
    else:                   other_loc = 'left'
    
    # 현재 위치에서 탈 수 있는 사람이 있을 때
    if people[boat_loc] and current_t >= people[boat_loc][0][1]:
        count = 0
        while people[boat_loc] and current_t >= people[boat_loc][0][1] and count < M:
            idx = people[boat_loc][0][0]
            count += 1
            answer[idx] = current_t + T
            people[boat_loc].pop(0)
            total_move_count += 1
        current_t += T
        boat_loc = other_loc
        
    # 현재 위치에서 탈 수 있는 사람이 없을 때
    else:
        
        # 현재 위치에 더 이상 사람이 안 온다면
        if not people[boat_loc]:
            # 반대 쪽에 사람이 도착할 때 까지 대기
            current_t = max(current_t, people[other_loc][0][1])
            current_t += T
            boat_loc = other_loc
            
        elif not people[other_loc]:
            current_t = max(current_t, people[boat_loc][0][1])
            
        # 먼저 도착하는 쪽 확인
        else:
            # 같은 쪽
            if people[boat_loc][0][1] <= people[other_loc][0][1]:
                current_t = max(current_t, people[boat_loc][0][1])
            
            else:    
                current_t = max(current_t, people[other_loc][0][1])
                current_t += T
                boat_loc = other_loc
    #print("answer: ", " ".join(map(str, answer)))
    
print("\n".join(map(str, answer)))


## 현재 시간보다 작고 && 최대 인원을 넘지 않을 때만 반복해서 pop

## 해당 인원들의 도착 시간은 현재 시간 + t 로 기록

## 현재 시간 = +2t 해두고

## 반복

## 틀린 풀이

"""
    
    person_move = []
    # pop 한다
    person_now = people[0]

    # 시간 세팅 - 사람이 도착하는 시간이 더 크면 그걸로 세팅. 반대로 도착해도 상관없을 듯.
    if person_now[0] > current_t:
        current_t = person_now[0]
    
    # 위치가 다르면 ti + t 아니면 그냥 ti.
    if person_now[1] != boat_loc:
        boat_loc = person_now[1]
        current_t += T
    
    #print("now person: ", person_now, "cur time: ", current_t, "cur loc: ", boat_loc)

    # 그 시간보다 커지기 직전까지 사람들 pop
    count = 0
    while people and people[0][0] <= current_t and count < M:
        if people[0][1] == boat_loc:
            #print("next: ", people[0], "cur time: ", current_t)
            heapq.heappop(people)
            person_move.append(current_t+T)
            count += 1
    answer.extend(person_move)
    current_t += T

    if boat_loc == 'left': boat_loc = 'right'
    else:                  boat_loc = 'left'
    #print("answer now: ", answer)

"""

## 틀린 풀이 2
"""
print("loc, time: ", boat_loc, current_t)
    # 초기화
    target_idx = []
    count = 0
    
    # 현재 시간 내 같은 위치에서 있는 사람 확인
    for idx in range(len(people)):
        if people[idx][0] > current_t:
            break
        if people[idx][1] == boat_loc and people[idx][0] != -1:
            target_idx.append(idx)
            people[idx] = (-1, "moved")
    
    # 이동가능한 사람이 있다?
    if target_idx:
        print("target idx: ", target_idx)
        for idx in target_idx:
            if count >= M:
                break
            answer[idx] = current_t + T
            total_move_count += 1
            count += 1
        
        print("answer: ", answer)
        
    # 없다?
    else:
        print("no one here: ", boat_loc)
        current_t += T
        if boat_loc == 'left':      boat_loc = 'right'
        else:                       boat_loc = 'left'

"""