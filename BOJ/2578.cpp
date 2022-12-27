/*
    23:36-23:40. 23:48-00:15, 34m

ex 1.
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25
6 7 8 9 10
3 13 18 23 5
17 21 1 2 4
11 12 14 15 16
19 20 22 24 25
answer 12

ex 2:
14 12 5 11 13 
9 4 3 8 25 
18 15 19 24 20 
1 6 7 23 17 
22 16 10 2 21 
17 11 9 24 6 
23 1 2 15 12 
8 14 21 10 16 
3 22 18 13 25 
4 5 19 7 20
answer 18

ex3: 
9 10 1 11 12
13 14 2 15 16
3 4 17 5 6
18 19 7 20 21
22 23 8 24 25
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25

answer 17
*/
#include <iostream>
#include <cstring>

using namespace std;

int input_bingo[5][5];
bool check_bingo[5][5];
int cnt_bingo = 0, cnt=0;

int main(){
    //
    for(int i=0; i<5; i++){
        memset(check_bingo[i], false, sizeof(bool)*5);
        for(int j=0; j<5; j++)
            cin >> input_bingo[i][j];
    }


    //
    int _in;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            
            cin >> _in;
            cnt += 1;

            // find
            int m, n;
            for(m=0; m<5; m++){
                for(n=0; n<5; n++){
                    if(input_bingo[m][n] == _in){
                        check_bingo[m][n] = true;
                        
                        // check if bingo in col
                        for(int c=0; c<5 && check_bingo[c][n] == true; c++){
                            if(c == 4 && check_bingo[c][n] == true)
                                cnt_bingo += 1;
                        }

                        // check if bingo in row
                        for(int c=0; c<5 && check_bingo[m][c] == true; c++){
                            if(c == 4 && check_bingo[m][c] == true)
                                cnt_bingo += 1;
                        }

                        // check if bingo in ne - sw diag
                        // if m + n = 4
                        if(m + n == 4){
                            for(int c=0; c<5 && check_bingo[c][4-c] == true; c++){
                                if(c == 4 && check_bingo[c][4-c] == true)
                                    cnt_bingo += 1;
                            }
                        }
                        // check if bingo in nw - se diag
                        if(m == n){
                            for(int c=0; c<5 && check_bingo[c][c] == true; c++){
                                if(c == 4 && check_bingo[c][c] == true)
                                    cnt_bingo += 1;
                            }
                        }
                    }
                }
            }
            if(cnt_bingo >= 3){
                cout << cnt;
                return 0;
            }
        }
    }
    return 0;
}