/*
    21:31-22:55
    - 경계선을 풀고 하나의 나라가 된다 = 맵을 하나 더 만들어 마킹을 해야한다.
    L이상 R이하다 -> 그러면 비교했던 곳의 마킹 값과 같게 한다
            아니다-> 그러면 해당 인덱스를 그대로 둔다
    1. 맵에다가 1~크기 의 값을 넣는다
    2. ij 반복하면서 오른쪽, 아래와 L < <R 인지 확인한다 + inrange + 마킹 
    3. ij 반복하면서 같은 마킹값영역이면 + not visited + bfs로 다 더해서 합을 구한다 ??
        아, 참 구현 되게 어렵네. 같은 영역 확인은 되는데, 다시 back 하면서 같은 영역 값/총합을 써줘야해. 재귀?
    아 이거 프로그래머스 프렌브4블록과 같은 유형같은데 왜 아이디어가 안떠오르냐 + 단지번호붙이기...

    --- 답 참고했음 ㅠㅡㅠ 어렵다. 피곤한가? ㅠㅠ
    전체를 돌면서 영역을 확인한다는 아이디어가 쉽게 떠오르지 않는다. 
    단지 번호가 같다-> LR 범위 내이다. 라는 조건만 달라진건데...

    ++ 
    answer 체크하는 타이밍을 헷갈려한다. -> memset 타이밍이 틀렸기 때문이다
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>

using namespace std;

int N, L, R;
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int map[51][51];
bool visited[51][51];

bool InRange(int x, int y){
    return ( x<0 || x>N-1 || y<0 || y>N-1) ? false:true;
}

bool Condition(int v, int x, int y){
    return (abs(map[x][y] - v) > R || (abs(map[x][y] - v) < L)) ? false:true;
}

int Solve(){
    int answer = 0;
    cin >> N >> L >> R;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            cin >> map[i][j];
    }

    // 인구 이동이 없을 때까지 반복
    while(true){
        bool end_condition = false;
        for(int k=0; k<N; k++)
            memset(visited[k], false, sizeof(bool)*N);

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(visited[i][j])
                    continue;

                // BFS를 통한 조건에 맞는 영역 탐색 
                queue<pair<int, int>> q;
                vector<pair<int, int>> v;
                int sum=map[i][j], cnt=1;  

                visited[i][j] = true;
                q.push({i, j});
                v.push_back({i, j});

                while(!q.empty()){
                    int cx = q.front().first;
                    int cy = q.front().second;
                    int cv = map[cx][cy];
                    q.pop();

                    for(int d=0; d<4; d++){
                        int nx = cx+dir[d][0];
                        int ny = cy+dir[d][1];

                        if(InRange(nx, ny) && !visited[nx][ny] && Condition(cv, nx, ny)){
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                            v.push_back({nx, ny});

                            end_condition = true;                   // 하나라도 있으면 ok
                            sum += map[nx][ny];
                            cnt ++;
                        }
                    }
                }
                //해당 영역 계산
                int value = sum/cnt;
                for(auto iter=v.begin(); iter!=v.end(); iter++){
                    int cx = iter->first;
                    int cy = iter->second;

                    map[cx][cy] = value;
                }
                v.clear();
            }
            /*
            cout << '\n';
            for(int i=0; i<N; i++){
                for(int j=0; j<N; j++)
                    cout << map[i][j] << " ";
                cout << '\n';
            }*/
        }
        

        if(!end_condition)
            break;

        answer ++;        
    }

    return answer;        
}

int main(){
    int answer = Solve();
    cout << answer;

    return 0;
}