import sys
input = sys.stdin.readline

target = int(input())

# 1.
end, cnt = 0, 0
while end < target:
    cnt += 1
    end += cnt

thn = end - target

# 2.
if cnt % 2 == 0:
    top = cnt-thn
    bottom = thn + 1
else:
    top = thn + 1
    bottom = cnt-thn

print(top, '/', bottom, sep='')