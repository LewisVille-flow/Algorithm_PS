#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int N, num_area = 0;
int grid[10][10];
int visited[10][10];
vector<int> num_each;
queue<pair<int, int>> Queue;

bool InRange(int x, int y){
	return (x < 0 || x > N-1 || y < 0 || y > N-1) ? false:true;
}

void Init(){
	cin >> N;
	fill(&visited[0][0], &visited[10][10], false);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++)
			cin >> grid[i][j];
	}
	return;
}

void Area_Search(){
	int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	int size = 1;
	
	while(!Queue.empty()){
		int x = Queue.front().first;
		int y = Queue.front().second;
		Queue.pop();
		
		for(int i=0; i<4; i++){
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			
			if(InRange(nx, ny) && grid[nx][ny] && !visited[nx][ny]){
				visited[nx][ny] = true;
				size += 1;
				
				Queue.push(make_pair(nx, ny));
			}
		}
	}
	num_each.push_back(size);
	return;
}

void Solve(){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(grid[i][j] && !visited[i][j]){
				visited[i][j] = true;
				Queue.push(make_pair(i, j));
				num_area += 1;
				
				Area_Search();
			}
		}
	}
	return;
}

void Print(){
	cout << num_area << '\n';
	
	sort(num_each.begin(), num_each.end());
	for(unsigned int i=0; i<num_each.size(); i++)
		cout << num_each[i] << " ";
	
	return;
}

int main() {
	Init();
	Solve();
	Print();
	return 0;
}