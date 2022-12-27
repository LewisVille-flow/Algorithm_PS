/*
    23:07~23:33 26m
*/
#include <iostream>
#include <vector>

using namespace std;

const int N_MAX = 101;
const int STU_MAX = 101;
bool switch_state[N_MAX] = {false, };
//vector<pair<int, int>> stu_num;

int switch_num, stu_num;

int main(){
    //
    cin >> switch_num;
    for(int sn=1; sn<=switch_num; sn++)
        cin >> switch_state[sn];
    
    cin >> stu_num;
    for(int stn=0; stn<stu_num; stn++){
        int gender, num;
        cin >> gender >> num;
        //stu_num.push_back(make_pair(gender, num));

        //
        if(gender == 1){
            for(int i=1; num*i <= switch_num; i++)
                switch_state[num*i] = !switch_state[num*i];
        }
        else{
            switch_state[num] = !switch_state[num];             // for zero

            for(int i=1; (num+i<=switch_num) && (num-i>=1) &&(switch_state[num+i] == switch_state[num-i]); i++){
                switch_state[num+i] = !switch_state[num+i];
                switch_state[num-i] = !switch_state[num-i];
            }
        }
    }

    //
    for(int i=1; i<=switch_num; i++){
        cout << switch_state[i] << " ";
        if(i % 20 == 0)
            cout << '\n';
    }
        

    return 0;
}