/*
  09:03~09:36
*/
#include <iostream>
#include <cstring>
#include <set>

using namespace std;

string input;

int Solve(){
    set<string> _set;

    for(int i=0; i<input.size(); i++){
        string _s_tmp = "";
        for(int j=i; j<input.size(); j++){
            _s_tmp += input[j];
            _set.insert(_s_tmp);
        }
    }

    return _set.size();
}


void Do(){
    cin >> input;
    int answer = Solve();

    cout << answer << '\n';

    return;
}


int main(){
    Do();
    return 0;
}