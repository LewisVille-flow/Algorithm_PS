/*
	22:40~22:58
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> input;

void Init() {
	int tmp;
	cin >> N;
	input.clear();

	for (int i = 0; i < 100; i++) {
		cin >> tmp;
		input.push_back(tmp);
	}

	sort(input.begin(), input.end());

	return;
}

void Solve(int n) {
	for (int i = 0; i < N; i++) {
		int _min = input[0];
		int _max = input[99];

		_min += 1;
		_max -= 1;

		input[0] = _min;
		input[99] = _max;

		sort(input.begin(), input.end());
	}

	cout << "#" << n << " " << input[99] - input[0] << '\n';

	return;
}

int main() {
	for (int i = 0; i < 10; i++) {
		Init();
		Solve(i+1);
	}
	return 0;
}