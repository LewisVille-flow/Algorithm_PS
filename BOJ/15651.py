## function
def Solve(num: int, N: int, M: int, _out: list):
    if(num == M):
        print(' '.join(map(str, _out)))
        return
    
    for m in range(1, N+1):
        _out.append(m)
        Solve(num+1, N, M, _out)
        _out.pop()
    return

## main
N, M = map(int, input().split())

_for_output = []
Solve(0, N, M, _for_output)

### 여기서 print는 계속 반복되서 사용되는데, 파이썬은 반복문이 느리기 때문에 살짝 비효율적이다
### 다 붙여서 print 하는 식으로 시간을 줄일 수 있다.
### aesterisk 붙여서 프린트하는 것도 시간 소요가 크다.
### 테크닉 적인걸 알아야 함.