#include<iostream>
#include<string>
#include<queue>
 
#define endl "\n"
#define MAX 1000
using namespace std;
 
int N, M;
int MAP[MAX][MAX];
int Visit[MAX][MAX][2];
 
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
 
void Input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string Inp;
        cin >> Inp;
        for (int j = 0; j < M; j++)
        {
            int Tmp = Inp[j] - '0';
            MAP[i][j] = Tmp;
        }
    }
}
 
int BFS()
{
    queue<pair<pair<int, int>, pair<int,int>>> Q;
    Q.push(make_pair(make_pair(0, 0), make_pair(0, 1)));
    Visit[0][0][0] = 1;
 
    while (Q.empty() == 0)
    {
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int B = Q.front().second.first;
        int Cnt = Q.front().second.second;
        Q.pop();
        cout << "x, y: " << x << ", " << y << ", " << Cnt << ", " << B << '\n';
 
        if (x == N - 1 && y == M - 1)
        {
            return Cnt;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
 
            if (nx >= 0 && ny >= 0 && nx < N && ny < M)
            {
                if (MAP[nx][ny] == 1 && B == 0)
                {
                    Visit[nx][ny][B+1] = Cnt + 1;
                    Q.push(make_pair(make_pair(nx, ny), make_pair(B + 1, Cnt + 1)));
                }
                else if (MAP[nx][ny] == 0 && Visit[nx][ny][B] == 0)
                {
                    Visit[nx][ny][B] = Cnt + 1;
                    Q.push(make_pair(make_pair(nx, ny), make_pair(B, Cnt + 1)));
                }
            }
        }
    }
    return -1;
}
 
void Solution()
{
    int R = BFS();
    cout << R << endl;

    cout << '\n';
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++)
            cout << Visit[i][j][0] << " ";
        cout << '\n';
    }
    cout << '\n';
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++)
            cout << Visit[i][j][1] << " ";
        cout << '\n';
    }
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}
