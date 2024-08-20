S = str(input().strip())
answer = set()

for i in range(0, len(S)):
    sub_s = ""
    for j in range(i, len(S)):
        sub_s += S[j]
        answer.add(sub_s)
print(len(answer))
        