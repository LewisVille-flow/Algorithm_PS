/*
    13:31~13:55 24m
*/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main(){
    int N;
    vector<string> input;
    vector<string> output;
    cin >> N;

    string _tmp;
    for(int i=0; i<N; i++){
        cin >> _tmp;
        input.push_back(_tmp);
    }

    output.push_back(input[0]);
    int size = input[0].size();

    for(int s=0; s<size; s++){
        char ch = input[0][s];
        for(int p=1; p<N; p++){
            if(input[p][s] != ch){
                output[0][s] = '?';
                break;
            }
        }
    }

    for(int k=0; k<size; k++)
        cout << output[0][k];


    return 0;
}