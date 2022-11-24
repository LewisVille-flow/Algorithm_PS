/*
	15:37~16:44
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <climits>
#include <queue>

using namespace std;

int T, N;
int grid[101][101];
int DP[101][101];
queue<pair<int, int>> Queue;

bool InRange(int x, int y) {
	return (x < 0 || x>N - 1 || y<0 || y>N - 1) ? false : true;
}

void Init() {
	cin >> N;
	// init
	fill(&grid[0][0], &grid[N][N], 0);
	
	for (int i = 0; i < N; i++) {
		string _input;
		cin >> _input;

		for(int j=0; j<N; j++)
			grid[i][j] = int(_input[j] - '0');
	}
	/*
	for (int m = 0; m < N; m++) {
		for (int n = 0; n < N; n++)
			cout << grid[m][n] << " ";
		cout << '\n';
	}
	*/
	// dp init
	fill(&DP[0][0], &DP[N][N], INT_MAX);
	/*
	for (int m = 1; m < N; m++) 
		DP[0][m] = DP[0][m - 1] + grid[0][m];
	for (int n = 1; n < N; n++)
		DP[n][0] = DP[n - 1][0] + grid[n][0];
	*/

	return;
}

void Solve() {
	int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
	Queue.push(make_pair(0, 0));

	while (!Queue.empty()) {
		int x = Queue.front().first;
		int y = Queue.front().second;
		Queue.pop();

		//if (x == N - 1 && y == N - 1)	return;
		for (int i = 0; i < 4; i++) {
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];

			if (InRange(nx, ny)) {
				int new_way_value = DP[x][y] + grid[nx][ny];
				if (DP[nx][ny] > new_way_value) {
					DP[nx][ny] = new_way_value;
					Queue.push(make_pair(nx, ny));
				}
			}
		}
	}
	/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			DP[i][j] = min(DP[i - 1][j] + grid[i][j], DP[i][j - 1] + grid[i][j]);
	}
	*/
	return;
}

void Print(int n) {
	cout << "#" << n << " ";
	cout << DP[N - 1][N - 1] << '\n';
	return;
}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		Init();
		Solve();
		Print(i+1);
	}
	return 0;
}