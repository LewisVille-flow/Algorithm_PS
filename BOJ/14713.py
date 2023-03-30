"""
    10:20 - 10:45;;
    1. 문장 사이에 끼어들 수 있지만 단어중간엔 끼어들지 않는다.
        섞인 문장이 가능한 문장인가 확인하기
        
    순서가 맞아야한다..
    생각나는 솔루션 - 각 리스트 앞을 Pop if match/found
     pop 한 것이 아니면 impossible
     모든리스트가 empty면 possible
     
    의문점
    input 문장단위로 어떻게? \n 제거하는 쉬운 방법?
"""
import sys
input = sys.stdin.readline

## main
N = int(input())
input_sentence = []
for n in range(N):
    input_sentence.append(input().split())

output_sentence = input().split()

## function
answer = "Possible"
for tok in output_sentence:
    for n in range(N):
        if input_sentence[n] and tok == input_sentence[n][0]:
            input_sentence[n].pop(0)
            break
    else:
        answer = "Impossible"
        break

# 예외상황
for n in range(N):
    if input_sentence[n]:
        answer = "Impossible"
print(answer)