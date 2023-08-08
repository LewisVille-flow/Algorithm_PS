"""
09:17-09:19, 09:31-09:43, 15m
"""
import sys
input = sys.stdin.readline

# 1.
iv = [0]*3
counting = [0]*10

for i in range(3):
    iv[i] = int(input().strip())

multipled = iv[0] * iv[1] * iv[2]
multipled = str(multipled)

# # 2.
# for i in range(10):
#     for j in multipled:
#         if i == int(j):
#             counting[i] += 1
for i in range(10):
    counting[i] = multipled.count(str(i))
            
# 3.
print("\n".join(map(str, counting)))