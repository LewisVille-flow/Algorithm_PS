
N = int(input().strip())

mod = 0
for i in range(1, 9):
    if N // (10**i) > 0:
        mod += 1
    else:
        break
# print(mod)
# div = N % 10

answer = 0

for i in range(0, mod+1):   # 몫이 0 ~ mod 일 때까지 계속 반복, 최대 8
    if i == mod: 
        answer = answer + (i+1) * (N - 10**i + 1)   # 마지막 자리 수 일 때
    else:
        answer = answer + (i+1) * (10**(i+1) - 10**i)
print(answer)