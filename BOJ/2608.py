"""
    오른쪽부터 읽어서 무슨 수인지는 확인할 수 있긴 하다(현재 기호보다 더 작은 기호면 그냥 빼는 걸로)
    만드는게 문제임. 최소 개수로 만들어야 함.
    4 단위면 해당 기호 + 하나 더 큰 기호 로 해서 두 개로 줄여야한다. Ex. 400 = CD, not CCCC
    같은 문자가 4개면 replace 하는 식으로 구현?
    
    왜 골드지? 아 변환하는게 번거롭네
"""
import sys
input = sys.stdin.readline
### Main
arab = [1, 5, 10, 50, 100, 500, 1000]
rome = ['I', 'V', 'X', 'L', 'C', 'D', 'M']

rome_to_arab = {r:a for a, r in zip(arab, rome)}
arab_to_rome = {a:r for a, r in zip(arab, rome)}

first_rome = input().strip()
second_rome = input().strip()

### Function
# convert rome to arab and sum
def convert(rome):
    arab, before = 0, 0
    for f in str(rome)[::-1]:
        _arab = rome_to_arab[f]
        if _arab < before:
            _arab = -_arab
        
        arab += _arab
        before = abs(_arab)
    
    return int(arab)

sum = convert(first_rome) + convert(second_rome)
print(sum)

# arab to rome
now = sum
answer = ""
# 역순으로 반복해나가면서, 표현할 수 있는 로마숫자 계속 확인
for arabian in arab[::-1]:
    while now >= arabian:
        # arabian이 10 단위 수가 아닐 수 있다...는게 문제임
        if str(now)[0] == '4':
            answer += arab_to_rome[arabian] + arab_to_rome[arabian*5]
            now -= 4*arabian
            continue
        
        if str(now)[0] == '9':  # 이 경우에는 무조건 arabian 의 마지막 자리수는 5보다크다
            arabian //= 5
            answer += arab_to_rome[arabian] + arab_to_rome[arabian*10]
            now -= 9*arabian
            continue

        answer += arab_to_rome[arabian]
        now -= arabian
    
    #print(f"now number: {now}, answer: {answer}")
print(answer)