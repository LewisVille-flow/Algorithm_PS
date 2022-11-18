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
	long long left, answer, right, expected_cost = 0;
    vector<int> num_dict(N+1, 0);

    for(int v=0; v<N; v++)
        num_dict[input[v]] ++;

    for(int b=0; b<N; b++)
        cout << input[b] << " ";
    cout << "\n";

    for(int m=1; m<=N; m++)
        cout << num_dict[m] << " ";
    cout << "\n";
	left = input[0];
	right = VALUE_MAX;
	//answer = ((right+left)/2);	// 달성가능한 최선의 최저성능

	while(right - left > 1){
		answer = ((right+left)/2);
        cout << "r, a, l: (" << right << ", " << answer << ", " << left << ")\n";
		expected_cost = 0;
        bool _flag = false;

		for(int j=1; j<=N; j++){
            int value, cnt;
            value = j;
            cnt = num_dict[j];

			if(value < answer)
				expected_cost += pow((answer - value), 2) * cnt;
			//cout << expected_cost << '\n';

			if(expected_cost > B){
				right = answer;
                //_flag = true;
				break;
			}
		}
		if(expected_cost <= B)
        //if(!_flag)
			left = answer;
	}
	cout << left;

	return 0;
}