/*
	11:40~12:20
	나는 펠린드롬이 젤 싫어
*/

#include <iostream>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

int N;
char grid[9][9];

void Init() {
	cin >> N;

	fill(&grid[0][0], &grid[9][9], '0');

	string _in;
	
	for (int i = 0; i < 8; i++) {
		cin >> _in;
		for (int j = 0; j < 8; j++)
			grid[i][j] = _in[j];
	}
	return;
}

void Solve(int n) {
	int answer = 0;
	bool _flag = true;
	if (N == 1) {
		answer = 64;
		return;
	}
	
	// row
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j <= 9 - N; j++) {
			_flag = true;
			for (int k = 0; k<int(N / 2); k++) {
				if (grid[i][j + k] != grid[i][N - 1 + j - k]) {
					_flag = false;
					break;
				}
			}
			if (_flag)
				answer++;
			//cout << "j, answer: (" << j << ", " << answer << ")\n";
		}
	}

	// col
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j <= 9 - N; j++) {
			_flag = true;
			for (int k = 0; k<int(N / 2); k++) {
				if (grid[j + k][i] != grid[N - 1 + j - k][i]) {
					_flag = false;
					break;
				}
			}
			if (_flag)
				answer++;
		}
	}
	cout << "#" << n << " " << answer << '\n';
	
	return;
}

int main() {
	for (int i = 0; i < 10; i++) {
		Init();
		Solve(i + 1);
	}

	return 0;
}