/*
	12:25~12:50
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string _target = "";
vector<string> input;

void Init() {
	int n;
	string _in;
	cin >> n >> _target >> _in;

	input.clear();
	input.push_back(_in);

	return;
}

void Solve(int n) {
	int answer = 0;
	int _target_index = input[0].find(_target);
	
	//while (_target_index + _target.size() <= input[0].size() && _target_index >= 0) {
	while(_target_index != string::npos){	
        //cout << _target_index << '\n';
		answer += 1;
		_target_index = input[0].find(_target, _target_index+_target.size());
	}
	//cout << _target_index << '\n';
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