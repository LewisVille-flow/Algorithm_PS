/*
    11:34-12:38
    - 사과를 먹었는지 구분하기 -> map에 표시하면 된다.
        사과를 먹고 몸통이 길어진다 == 새로운 좌표 push 만 진행
        일반적인 이동 == 새로운 좌표 push & 이전 것 pop, visited map값 변경
    - 회전 input -> dir ESWN modular 연산
    - 벽에 닿았는지, 몸통에 부딪혔는지 구분하기 
        회전 input에 따라 변한다.
        머리가 벽에 닿았는가 -> InRange
        머리가 몸통에 닿았는가 -> visited map 비교(큐 pop을 통한 지우기)

        hint : queue -> 큐를 이용해 꼬리-머리까지의 좌표를 기억하고, 머리가 이동하면 꼬리 하나를 pop, 맵에서 지운다

    hint 2: map에서 사과의 위치와 뱀의 위치는 중복되지 않는다(사과는 사라진다.)
        따라서 해당 위치가 뱀의 몸통인지를 벡터 탐색을 이용하지 않고, 맵 값을 이용해서(사과=1, 뱀=2) 구분할 수도 있다.
        대신 몸통의 정보를 갖는 큐 + 맵 값 함께 동작시켜야해서 조금 헷갈릴 수 있다.
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, K, L;
int map[101][101];
vector<int> apple(101);
queue<pair<int, char>> move_info;

bool InRange(int x, int y){
    return (x<1 || x>N || y<1 || y>N) ? false:true;
}

bool Body(int x, int y, vector<pair<int, int>>& body){
    for(auto iter=body.begin(); iter!=body.end(); iter++){
        if(x == iter->first && y == iter->second)
            return true;
    }
    return false;
}

int Solve(){
    int answer = 0;
    cin >> N >> K;
    fill(&map[1][1], &map[N][N+1], 0);
    for(int k=0; k<K; k++){
        int x, y;
        cin >> x >> y;
        map[x][y] = 1;
    }
    cin >> L;
    for(int l=0; l<L; l++){
        int x;  char y;
        cin >> x >> y;
        move_info.push({x, y});
    }

    vector<pair<int, int>> body;
    body.push_back({1, 1});
    //map[0][0] = 1;
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int dir_value = 0;
    
    while(true){
        int mtime = move_info.front().first;
        char direction = move_info.front().second;
        int cx = body.back().first;
        int cy = body.back().second;

        //cout << "cx, cy: " << cx << ", " << cy;
        //cout << "dir value: " << dir_value;
        int nx = cx + dir[dir_value][0];
        int ny = cy + dir[dir_value][1];
        //cout << " nx, ny: " << nx << ", " << ny <<'\n';
        if(!InRange(nx, ny) || Body(nx, ny, body)){
            //cout << "break!";
            break;
        }

        body.push_back({nx, ny});

        if(map[nx][ny] != 1)
            body.erase(body.begin());
        else{
            map[nx][ny] = 0;
            //cout << "apple! " << '\n';
        }

        answer ++;

        if(answer == mtime){
            move_info.pop();
            if(direction == 'D')    dir_value = (dir_value+1)%4;
            else{
                dir_value -= 1;
                if(dir_value < 0)
                    dir_value = 3;
            }
        }
    }

    return answer+1;
}

int main(){
    int answer = Solve();
    cout << answer;
    return 0;
}