import sys
input = sys.stdin.readline

# function
def solve():

    for i in range(1, len(first_string)+1):
        for j in range(1, len(second_string)+1):
            if first_string[i-1] == second_string[j-1]:
                dp_array[i][j] = dp_array[i-1][j-1]+first_string[i-1]
            else:
                if len(dp_array[i][j-1]) > len(dp_array[i-1][j]):
                    dp_array[i][j] = dp_array[i][j-1]
                else:
                    dp_array[i][j] = dp_array[i-1][j]
    return dp_array[len(first_string)][len(second_string)]

# input
first_string = str(input().strip())
second_string = str(input().strip())

dp_array = [["" for _ in range(len(second_string)+1)] for _ in range(len(first_string)+1)]
answer = solve()

if len(answer) != 0:
    print(len(answer))
    print(answer)
else:
    print(0)