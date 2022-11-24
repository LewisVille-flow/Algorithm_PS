/*
	21:49~22:30
	1. 문제가 이해되지 않는다. N이 건물 개수이면
		양 옆의 0 0  은 포함인가 아닌가? 포함인듯
		높이 0 도 건물이랬으니.
	2. 제공되는 ide에 작성된 코드가 틀려있네 이런;;
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int T, N;
int input[1001];
int output[1001];

void Init() {
	cin >> N;
	fill(input, input + N+1, 0);
	fill(output, output + N+1, 0);

	for (int i = 0; i < N; i++)
		cin >> input[i];

	return;
}

void Solve(int num) {
	int answer=0, tmp;
	for (int i = 2; i < N - 2; i++) {
		int max_within_two = 0;

		for (int j = i - 2; j <= i + 2; j++) {
			if(j != i)
				max_within_two = max(max_within_two, input[j]);
		}
		
		tmp = input[i] - max_within_two;
		if (tmp > 0)
			output[i] = tmp;
	}
	
    /*
	for (int l = 0; l < N; l++) {
		cout << output[l] << " ";
	}
	cout << "\n";
    */

	for (int m = 0; m < N; m++)
		answer += output[m];
	
	cout << '#' << num << " " << answer << '\n';
	return;
}

int main() {
	cin >> T;
	for (int t = 0; t < T; t++) {
		Init();
		Solve(t+1);
	}
	return 0;
}