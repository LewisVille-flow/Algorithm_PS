/*
    14:30-14:45 15m
*/
#include <iostream>

using namespace std;

int N;
int input[50][5][7];

void Solve(){
    string _in;
    cin >> N;

    //
    for(int n=0; n<N; n++){
        for(int i=0; i<5; i++){
            cin >> _in;
            for(int j=0; j<7; j++)
                input[n][i][j] = _in[j];
        }
    }
    int first, second, min_value = 36;
    for(int a=0; a<N-1; a++){
        for(int b=a+1; b<N; b++){
            int _tmp = 0;
            for(int i=0; i<5; i++){
                for(int j=0; j<7; j++){
                    if(input[a][i][j] != input[b][i][j])
                        _tmp += 1;
                }
            }
            if(_tmp < min_value){
                min_value = _tmp;
                first = a+1;
                second = b+1;
            }
        }
    }

    cout << first << ' ' << second;
}

int main(){
    Solve();
    return 0;
}