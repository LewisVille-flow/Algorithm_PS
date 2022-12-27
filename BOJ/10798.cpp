#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main(){
    string inStr;
    char revCol[15][5];

    fill(&revCol[0][0], &revCol[15][5], '\0');

    for(int i=0; i<5; i++){
        cin >> inStr;
        for(int j=0; j<inStr.size(); j++){
            revCol[j][i] = inStr[j];
        }
    }

    for(int m=0; m<15; m++){
        for(int n=0; n<5; n++){
            if(revCol[m][n] != '\0')
                cout << revCol[m][n];
        }
    }
    
    return 0;
}