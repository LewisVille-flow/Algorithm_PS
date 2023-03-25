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