/*
    17:10-18:47
    치킨 집을 M개만 골랐을 때, 치킨 거리의 최솟값
    전수조사? 치킨집 최대 13개, 집 최대 100가구 -> 13C6*100가지 - 얼마 안 될거같네
    각 치킨집에서는 집까지의 거리를 저장할 수 있다. 그 정보를 토대로 최소인 순으로 정렬해서 M개만 뽑은뒤 합을 리턴

    치킨 거리는 가까운 집만을 기준으로 정렬하지만,
    대신 리턴 값은 '모든' 집을 기준으로 해야 함.
    --- 아아아, 아니다 문제를 아예 잘못 이해했다..

    도시의 치킨거리를 최소화 하는 M개를 선정해야 한다. 도시의 치킨거리는 집에서 가장 가까운 치킨집과의 거리의 합.
    무슨 자료구조를 써야하지?
    모든 집에서 가깝다 = 도시의 치킨거리를 최소화한다 라고 가정할 수 있나? 분명 예외케이스가 있을 것.
    주어진 치킨집에서 M개만 뽑아서 최솟값을 찾는게 brute force인데, 코드를 어떻게 짜지?

    -- 재귀..... ㅆㅃㅆㅃㅆㅃㅆㅃㅆㅃㅆ!!
    백트래킹해서 M개만큼의 치킨 집을 임시 벡터에 넣어뒀으면, 거리를 구한 뒤 최솟값이라면 answer update

    Backtracking(idx, cnt)
        // end conditon
        값 계산, 업데이트

        //
        이전에 안 들어갔던 값을 어떻게 알지? -> 그럼 그야 당연히 visted 써야지!!
    
    --- 문제의 핵심
    1. N개 중 M개를 선택하기 -> 재귀적 함수 호출을 설계할 수 있어야 한다.
    2. 재귀 호출 시간복잡도 고려 -> 이전에 탐색했던 것을 제외하고 탐색할 수 있어야 한다. visited배열을 쓰고 idx를 인자로 넘긴다.
    3. 문제는 좌표계 형태를 갖지만, 좌표는 큰 상관이 없다. -> 집 정보와 가게 정보를 담는 자료구조 사용.
    4. 문제를 제대로 이해할 수 있는가?
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

const int _MAX = 987654321;
int N, M, result = _MAX;
bool visited[101];
vector<pair<int, int>> house;
vector<pair<int, int>> market;
vector<pair<int, int>> survived;


void Recursion(int idx, int cnt){
    // end condition
    if(cnt == M){
        int dist = 0;
        for(int i=0; i<house.size(); i++){
            int x = house[i].first;
            int y = house[i].second;
            int d = _MAX;

            for(int j=0; j<survived.size(); j++)
                d = min(d, abs(x-survived[j].first) + abs(y-survived[j].second));
            dist += d;
        }
        result = min(result, dist);
        return;
    }

    for(int i=idx; i<market.size(); i++){
        if(visited[i])    continue;
        
        int x = market[i].first;
        int y = market[i].second;

        visited[i] = true;
        survived.push_back({x, y});
        Recursion(i, cnt + 1);
        survived.pop_back();
        visited[i] = false;
    }
}

int Solve(){
    cin >> N >> M;
    memset(visited, false, sizeof(bool)*M);
    // init
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int value;
            cin >> value;

            if(value == 1)          house.push_back({i, j});
            else if(value == 2)     market.push_back({i, j});
        }
    }

    // recursion
    Recursion(0, 0);

    return result;
}


/*
bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
    return a.second < b.second;
}

int Solve(){
    int answer = 987654321;
    // init
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
            if(map[i][j] == 2)
                market.push_back({{i, j}, 0});
        }
    }

    // brute-force
    for(int i=0; i<market.size(); i++){
        int x = market[i].first.first;
        int y = market[i].first.second;
        int dist = 987654321;

        for(int m=0; m<N; m++){
            for(int n=0; n<N; n++){
                if(map[m][n] == 1)
                    dist = dist + abs(m-x) + abs(n-y);
            }
        }
        market[i].second = dist;
    }
    stable_sort(market.begin(), market.end(), comp);

    for(int i=0; i<M; i++){
        cout << market[i].second << " ";
        int x = market[i].first.first, y = market[i].first.second;
        int dist = 0;

        for(int m=0; m<N; m++){
            for(int n=0; n<N; n++){
                if(map[m][n] == 1)
                    dist = dist + abs(m-x) + abs(n-y);
            }
        }
    }

    return answer;
}
*/

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
    int answer = Solve();
    cout << answer;
    return 0;
}
