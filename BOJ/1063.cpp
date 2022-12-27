/*
    16:23-17:13, 50m
*/
#include <iostream>
#include <cstring>

using namespace std;

string king_pos, stone_pos;
char king_col, king_row, stone_col, stone_row;
int N;
int grid[8][8];

bool InRange(int x, int y){
    return (x<1 || x>8 || y<1 || y>8) ? false:true;
}

// return row, col
pair<int, int> CheckDir(string next_move){
    pair<int, int> dir;

    if(next_move == "R")            dir = make_pair(0, 1);
    else if(next_move == "L")       dir = make_pair(0, -1);
    else if(next_move == "B")       dir = make_pair(-1, 0);
    else if(next_move == "T")       dir = make_pair(1, 0);
    else if(next_move == "RT"){     dir = make_pair(1, 1);      }      
    else if(next_move == "LT"){     dir = make_pair(1, -1);     }
    else if(next_move == "RB"){     dir = make_pair(-1, 1);     }
    else if(next_move == "LB"){     dir = make_pair(-1, -1);    }

    return dir;
}

void Move(){
    //A~H, 1~8
    string next_move;
    char next_col, next_row;

    cin >> next_move;

    // save next dir
    pair<int, int> dir = CheckDir(next_move);
    next_row = king_row + dir.first;
    next_col = king_col + dir.second;

    // check next king's pos in in Range first.
    if(InRange(next_row-'0', next_col-'A'+1)){
        // if stones == king next then move stone
        if(next_row == stone_row && next_col == stone_col){
            char stone_next_row = stone_row + dir.first, stone_next_col = stone_col + dir.second;

            if(InRange(stone_next_row-'0', stone_next_col-'A'+1)){
                king_col = next_col;
                king_row = next_row;
                stone_col = stone_next_col;
                stone_row = stone_next_row;
            }
            else{}
        }
        else{
            king_col = next_col;
            king_row = next_row;
        }
    }
    else{}

    return;
}

void Print(){
    cout << king_col << king_row << '\n' << stone_col << stone_row;
}

void Solve(){
    cin >> king_pos >> stone_pos >> N;
    king_row = king_pos[1];
    king_col = king_pos[0];
    stone_row = stone_pos[1];
    stone_col = stone_pos[0];

    for(int n=0; n<N; n++)
        Move();
    Print();
}

int main(){
    Solve();
    return 0;
}