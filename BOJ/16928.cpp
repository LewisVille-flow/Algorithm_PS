/*
    start at 16:50 finished at 18:00
    사다리 -> 금방 100 번째 칸으로 가게 함, 뱀 -> 100번째 칸보다 더 멀게 함

    condition
        - 원하는 만큼 앞으로 이동 가능(1~6 만 가능)

    idea
        - 빠르게 100에 도달하는 방법을 아는 것이므로 DFS가 나을 것.
            - 근데 최소 경로를 알아야하므로 이건 ... 최단경로 탐색알고리즘??
        - 재귀: 현재 위치, 주사위 굴린 횟수
        - input으로 뱀, 사다리 위치 확인해서 현재 위치 == 저장위치 이면 현재위치 이동 후 작업진행
        - 도전 1: visited와 cnt 비교를 통한 BFS
        Correct!
        - visited는 중복으로 인해 오류가 생길 수 있어 삭제하였음.
        - Dist 기록 후 새로 계산된 cnt가 이전 dist보다 짧을 경우에만 업데이트, 100번째 dist 출력.
    
*/
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N, M;

bool visited[101] = {false,};
int Dist[101];
int Up_or_Down[101] = {0,};
queue<pair<int, int>> game_queue;

void Search_Shortest(){
    
    // 1. init
    int value, cnt, new_value, new_cnt;

    // 2. Search
    while(!game_queue.empty()){

        value = game_queue.front().first;
        cnt = game_queue.front().second;
        //cout << "value : " << value << "\tcnt: " << cnt << '\n';

        game_queue.pop();

        for(int dice=1; dice<=6; dice++){
            new_value = value + dice;
            new_cnt = cnt + 1;

            //cout << "new_ value : " << new_value << "\tnew_cnt: " << new_cnt << '\n';
            if(new_value > 100) continue;

            // if Up or Down
            if(Up_or_Down[new_value] != 0){
                new_value = Up_or_Down[new_value];

                if(Dist[new_value] > new_cnt){
                    Dist[new_value] = new_cnt;
                    game_queue.push(make_pair(new_value, new_cnt));
                }
            }

            // else
            else if(Dist[new_value] > new_cnt){
                //cout << "here" << '\n';
                Dist[new_value] = new_cnt;
                game_queue.push(make_pair(new_value, new_cnt));
            }
        }
    }
    return;
}

int main(){
    // 1. init
    cin >> N >> M;
    for(int u=0; u<(N+M); u++){
        int x, y;
        cin >> x >> y;
        Up_or_Down[x] = y;
    }   
   
    memset(Dist, 101, sizeof(int)*101);

    // 2. function
    visited[1] = true;                   // start
    game_queue.push(make_pair(1, 0));    // start point

    Search_Shortest();

    // 3. out
    int result = Dist[100];
    cout << result << '\n';

    return 0;
}