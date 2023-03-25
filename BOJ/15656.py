def Recursive(num: int, tar: int, _in: list, _out: list):
    if num == tar:
        print(' '.join(map(str, _out)))
        return
    
    for m in range(len(_in)):
        _out.append(_in[m])
        Recursive(num + 1, tar, _in, _out)
        _out.pop()


_input1 = list(map(int, input().split()))
_input2 = list(map(int, input().split()))

N, M = _input1[0], _input1[1]

_for_print = []
_input2.sort()

Recursive(0, M, _input2, _for_print)