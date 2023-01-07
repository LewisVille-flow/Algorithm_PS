/*
    21:19-22:36, 67m
*/
#include <iostream>
#include <vector>

using namespace std;

int N;
string _input;
int input_array[6][100001];
vector<int> answer;

int main(){
    int idx_i=0, idx_j=0;
    cin >> N >> _input;
    for(int s=0; s<N; s++){
        if(_input[s] == '#')        input_array[idx_i][idx_j] = 1;
        else if(_input[s] == '.')   input_array[idx_i][idx_j] = 0;

        idx_j += 1;
        if(idx_j == N/5){
            idx_j = 0;
            idx_i += 1;
        }
    }

    for(int j=0; j<N/5; j++){
        if(input_array[0][j] == 1){
            // exception
            if(j+1 >= N/5){
                answer.push_back(1);                continue;
            }
            int cur_j = 0, next_j = 0;
            for(cur_j=0; cur_j<5; cur_j++){
                if(input_array[cur_j][j] != 1)       break;
            }
            // 1, 6, 8, 0
            if(cur_j == 5){
                
                for(next_j=0; next_j<5; next_j++){
                    if(input_array[next_j][j+1] != 0)    break;
                }
                if(next_j == 5){
                    answer.push_back(1);    j += 1;     continue;
                }

                if(input_array[1][j+2] == 0){
                    answer.push_back(6);    j += 2;     continue;
                }

                if(input_array[2][j+1] == 0){
                    answer.push_back(0);    j += 2;     continue;
                }

                answer.push_back(8);        j += 2;     continue;
            }

            // 2, 3, 7
            if(input_array[1][j] == 0){
                if(input_array[3][j+2] == 0){
                    answer.push_back(2);        j += 2;     continue;
                }

                if(input_array[2][j] == 1){
                    answer.push_back(3);        j += 2;     continue;
                }

                if(input_array[2][j] == 1){
                    answer.push_back(3);        j += 2;     continue;
                }

                answer.push_back(7);            j += 2;     continue;
            }
            // 4, 5, 9
            if(input_array[4][j] == 0){
                answer.push_back(4);        j += 2;     continue;
            }
            if(input_array[1][j+2] == 1){
                answer.push_back(9);        j += 2;     continue;
            }
            answer.push_back(5);        j += 2;     continue;
        }
    }    
    
    for(int c=0; c<answer.size(); c++)
        cout << answer[c];

    return 0;
}