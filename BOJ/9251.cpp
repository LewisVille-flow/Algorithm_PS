/*
    11:47-13:16
*/
#include <iostream>
#include <cstring>

using namespace std;

const int N_MAX = 1001;
int dp_array[N_MAX][N_MAX];

int Solve(){
    
    int answer;
    string inputA, inputB;
    cin >> inputA >> inputB;
    //int dp_array[inputA.size()+2][inputB.size()+2];
    
    fill(&dp_array[0][0], &dp_array[inputA.size()][inputB.size()+1], 0);
    /*
    for(int i=0; i<inputB.size(); i++){
        if(inputB[i] == inputA[0])
            dp_array[0][i] = 1;
        else if(inputB[i] != inputA[0] && i>0)
            dp_array[0][i] = dp_array[0][i-1];
    }

    for(int i=0; i<inputA.size(); i++){
        if(inputA[i] == inputB[0])
            dp_array[i][0] = 1;
        else if(inputA[i] != inputB[0] && i>0)
            dp_array[i][0] = dp_array[i-1][0];
    }
    */

    for(int i=1; i<=inputA.size(); i++){
        for(int j=1; j<=inputB.size(); j++){
            if(inputB[j-1] == inputA[i-1])
                dp_array[i][j] = dp_array[i-1][j-1]+1;
            else
                dp_array[i][j] = max(dp_array[i-1][j], dp_array[i][j-1]);
        }
    }

    answer = dp_array[inputA.size()][inputB.size()];
    
    return answer;
}

int main(){
    int answer = Solve();
    cout << answer;
    return 0;
}