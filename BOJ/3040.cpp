/*
    20:30~20:45
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    vector<int> input;
    int _tmp;

    for(int i=0; i<9; i++){
        cin >> _tmp;
        input.push_back(_tmp);
    }

    for(int m=0; m<8; m++){
        for(int n=m+1; n<9; n++){
            int _out1 = input[m], _out2 = input[n];

            int sum=0;
            for(int k=0; k<9; k++){
                if(k!=m && k!=n)
                    sum += input[k];
            }
            if(sum == 100){
                for(int p=0; p<9; p++){
                    if(p!=m && p!=n)
                        cout << input[p] << '\n';
                }  
                return 0;
            }
        }
    }
    return 0;
}