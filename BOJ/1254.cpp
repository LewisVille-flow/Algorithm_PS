/*
    09:38~10:13 35m
*/
#include <algorithm>
#include <cstring>
#include <iostream>


using namespace std;

string input;

bool IsPalindrome(string s){
    string _org = s;
    reverse(s.begin(), s.end());
    return (s == _org) ? true:false;
}

int Solve(){
    int answer;
    string sub_input = "";

    if(IsPalindrome(input))
        return input.size();

    for(int i=0; i<input.size(); i++){
        sub_input += input[i];
        string _to_add = sub_input;
        reverse(_to_add.begin(), _to_add.end());

        if(IsPalindrome(input+_to_add)){
            answer = (input+_to_add).size();
            return answer;
        }
    }
    return input.size() *2 -1;
}

void Do(){
    cin >> input;

    int answer = Solve();

    cout << answer;
    return;
}

int main(){

    Do();

    return 0;
}