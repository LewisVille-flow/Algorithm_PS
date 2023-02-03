/*
    14:43-16:27...
    // N=격자 크기, M=나무의 개수, K= k년이 지난 후 남은 나무의 개수
    1. 초기 NxN 땅에는 양분이 5만큼 있고, 4계절이 지난 후에는 A[r][c]만큼 더해진다
    2. 사계절을 나누어야한다 -> season = (season+1)%4
    3. 나무의 위치 tree[][]와 양분의 양 energy[][] 가 필요하다
        한 칸에 여러 나무가 있을 수 있다 -> 3차원 벡터? 가장 어린 나무를 탐색해야한다. 어떤 자료구조가 효율적이지?
            - x,y 정보와 age가 담겨있어야 한다. 나무의 개수 M은 최대 100개. k<=1000이므로, .... 
              아무래도 벡터에 넣고 x,y를 기준으로 탐색하는 건 무리다.
            - 입력으로 주어지는 나무들은 서로 달라도, 나무가 주변으로 번식한다. 그 정보를 저장해아한다.
        -> 3차원 벡터
    
    나무의 나이 순으로 정렬 -> priority queue 써도 되겠다, tree는... 하지만 3차원벡터가 낫겠지
    계절 정보에 따라
        봄 -> 양분 값 --, 못 먹는 나무는 죽는다. 죽은 나무를 저장하는 3차원 벡터에 나이를 저장
        여름-> 죽은 나무 양분 ++
        가을-> 나무의 번식:tree[][]에 dir 수행하며 나무 개수 ++
        겨울-> energey에다가 A 값 추가
        year ++

    ---
    문제의 핵심
    0. 나무정보를 저장하기 위한 자료구조 -> 3차원 벡터, 행렬 사용할 줄 알아야 함.
    1. '어린' 나무부터 양분을 소비한다 -> 나이순으로의 정렬이 필요함 -> 정렬에서의 시간초과를 염두에 두어야 함.
    2. 양분을 소비하지 못하는 나무는 '없어지고 양분이 된다.' -> 없어지는 처리를 위한 자료구조가 필요
    3. 전체 반복에서의 종료조건
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;
int A[11][11];
int energy[11][11];
vector<int> tree[11][11];
vector<int> afterspring[11][11];
vector<int> deadtree[11][11];
//vector<vector<vector<int>>> tree(11, vector<vector<int>>(11, vector<int>()));
//vector<vector<vector<int>>> deadtree(11, vector<vector<int>>(11, vector<int>()));

bool InRange(int x, int y){
    return ( x<1 || x>N || y<1 || y>N ) ? false:true;
}

void Spring(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(tree[i][j].size()!=0)
                sort(tree[i][j].begin(), tree[i][j].end());

            for(int k=0; k<tree[i][j].size(); k++){
                int age = tree[i][j][k];
                int en = energy[i][j];

                if(en >= age){
                    afterspring[i][j].push_back(age+1);             // for문을 안건드리도록 벡터를 추가했다.
                    energy[i][j] -= age;
                }
                else if(age!= -1 && en < age){
                    //tree[i][j].erase(tree[i][j].begin()+k);     // 이 구문이 k에 해당하는 for문을 건드린다.
                    deadtree[i][j].push_back(age);
                }
            }
            tree[i][j].clear();
            tree[i][j] = afterspring[i][j];
            afterspring[i][j].clear();
        }   
    }
}

void Summer(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            for(int k=0; k<deadtree[i][j].size(); k++){
                int dage = deadtree[i][j][k];
                int de = dage/2;
                energy[i][j] += de;
            }
            deadtree[i][j].clear();         // 이걸 안해줘서 계속 누적되었다.
        }
    }

}

void Fall(){
    int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            for(int k=0; k<tree[i][j].size(); k++){
                int age = tree[i][j][k];

                if(age%5 == 0){
                    for(int d=0; d<8; d++){
                        int ni = i + dir[d][0];
                        int nj = j + dir[d][1];

                        if(InRange(ni, nj)){
                            //tree[ni][nj].insert(tree[ni][nj].begin(), 1);
                            tree[ni][nj].push_back(1);
                        }
                    }
                }
            }
        }
     }
}

void Winter(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            int en= A[i][j];
            energy[i][j] += en;
        }
    }
}


void Print(){
    cout << '\n';
    for(int i=1; i<11; i++){
        for(int j=1; j<11; j++)
            cout << tree[i][j].size() << " ";
        cout << '\n';
    }
    cout << '\n';
}

int Solve(){
    int year = 0;
    // init
    cin >> N >> M >> K;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> A[i][j];
            energy[i][j] = 5;
        }
    }
    for(int t=0; t<M; t++){
        int x, y, age;
        cin >> x >> y >> age;
        tree[x][y].push_back(age);
    }

    //Print();

    // loop
    while(year < K){
        Spring();   //Print();
        Summer();   //Print();
        Fall();     //Print();
        Winter();   //Print();
    
        year ++;
    }

    // print
    int answer=0;
    for(int i=1; i<11; i++){
        for(int j=1; j<11; j++){
            answer += tree[i][j].size();
        }
    }
    return answer;

}


int main(){
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);

    int answer = Solve();
    cout << answer;
    return 0;
}
