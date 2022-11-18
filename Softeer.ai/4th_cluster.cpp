#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

const int VALUE_MAX = 2*pow(10, 9);
int N;
long long B;
vector<int> input;

int main(int argc, char** argv)
{
	int p;
	cin >> N >> B;

	for(int i=0; i<N; i++){
		cin >> p;
		input.push_back(p);
	}

	sort(input.begin(), input.end());
	long long left, answer, right;
	long long expected_cost = 0;
	left = input[0];
	right = VALUE_MAX;
	

	while(right - left > 1){
        answer = ((right+left)/2);	// 달성가능한 최선의 최저성능
		//cout << "r, a, l: (" << right << ", " << answer << ", " << left << ")\n";

		expected_cost = 0;

		for(int j=0; j<N; j++){
			if(input[j] < answer)
				expected_cost += pow((answer - input[j]), 2);
			//cout << expected_cost << '\n';

			if(expected_cost > B){
				right = answer;
				break;
			}
		}
		if(expected_cost <= B)
			left = answer;

		answer = ((right+left)/2);
	}
	cout << answer;

	return 0;
}