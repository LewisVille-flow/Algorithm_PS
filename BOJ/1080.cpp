/*
    11:36-11:43, 11:58-12:28, 40m
*/
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> inputA(50, vector<int>());
vector<vector<int>> inputB(50, vector<int>());

void Reverse(int x, int y){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            inputA[x+i][y+j] = !inputA[x+i][y+j];
        }
    }
}

void Solve(){
    //
    cin >> N >> M;

    string _input;
    for(int c=0; c<N; c++){
        cin >> _input;
        for(int i=0; i<_input.size(); i++)
            inputA[c].push_back(_input[i]-'0');
    }
    for(int c=0; c<N; c++){
        cin >> _input;
        for(int i=0; i<_input.size(); i++)
            inputB[c].push_back(_input[i]-'0');
    }

    if(N < 3 || M < 3){
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(inputA[i][j] != inputB[i][j]){
                    cout << "-1";
                    return;
                }
            }
        }
        
    }

    //
    int count = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(((M-j < 3) || (N-i < 3)) && (inputA[i][j] != inputB[i][j])){
                cout << "-1";
                return;
            }
            if(inputA[i][j] != inputB[i][j]){
                Reverse(i, j);
                count ++;
            }
        }
    }
    cout << count;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    Solve();
    return 0;
}
