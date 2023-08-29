import sys
input = sys.stdin.readline

# input
N = int(input())
for n in range(N):
    sentence = list(map(str, input().split()))
    
    print("Case #%d: %s" % (n+1 ," ".join(sentence[::-1])))
