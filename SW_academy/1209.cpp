/*
	23:20~23:40
*/
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

int N;
int grid[101][101];
int row_sum[101];
int col_sum[101];
int diag_sw_sum = 0;
int diag_se_sum = 0;

int main() {
	int _input, _max_result = INT_MIN;
	for (int i = 0; i < 10; i++) {
		cin >> N;
		//fill(grid, grid+101, 0);
		fill(row_sum, row_sum +101, 0);
		fill(col_sum, col_sum+101, 0);
		
		diag_sw_sum = 0;
		diag_se_sum = 0;

		for (int m = 0; m < 100; m++) {
			for (int n = 0; n < 100; n++) {
				cin >> _input;
				//grid[m][n];
				row_sum[m] += _input;
				col_sum[n] += _input;
				if (m + n + 1 == 100)
					diag_sw_sum += _input;
				if (m == n)
					diag_se_sum += _input;
			}
		}
		int _max_row = INT_MIN, _max_col = INT_MIN;
		for (int k = 0; k < 100; k++) {
			_max_row = max(_max_row, row_sum[k]);
			_max_col = max(_max_col, col_sum[k]);
		}

		vector<int> v;
		v.push_back(_max_row);
		v.push_back(_max_col);
		v.push_back(diag_sw_sum);
		v.push_back(diag_se_sum);

		sort(v.begin(), v.end());

		cout << "#" << i + 1 << " " << v[3] << '\n';

	}
	return 0;
}