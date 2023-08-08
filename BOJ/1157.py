"""
    09:48-10:04, 16m
"""
import sys
input = sys.stdin.readline

# 1.
input_value = str(input().strip().upper())

# 2.
alphabet = [0]*26
for alp in range(len(alphabet)):
    calp = alp + int(ord('A'))
    calp = chr(calp)

    alp_count = input_value.count(calp)
    alphabet[alp] = alp_count

# 3.
max_value = max(alphabet)
if alphabet.count(max_value) > 1:
    print('?')
else:
    print(chr(alphabet.index(max_value) + ord('A')))

