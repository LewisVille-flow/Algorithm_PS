/*
    10:53-11:49 50m
*/
#include <iostream>
#include <cstring>
#include <regex>

using namespace std;

int N;

void Gene_Check_new(){
    //regex regExp("([ABCDEF] ?)([A]+)([F]+)([C]+)([ABCDEF] ?)");
    regex regExp(R"(^[A-F]?A+F+C+[A-F]?$)");
    string _input;
    cin >> _input;

    if(regex_match(_input, regExp))
        cout << "Infected!\n";
    else
        cout << "Good\n";
}

string Simple(string _input){
    string result = "";
    int size = _input.size();
    char comp = _input[0];
    result.push_back(comp);

    for(int i=1; i<size; i++){
        if(comp != _input[i]){
            result.push_back(_input[i]);
            comp = _input[i];
        }
    }

    return result;
}

void Gene_Check(){
    string _input, output;
    cin >> _input;

    //
    string _input_simpled = Simple(_input);

    //
    char first[5] = {'B', 'C', 'D', 'E', 'F'};

    if(_input_simpled[0] - 'A' + 1 > 6){
        output = "Good";
        cout << output;
        return;
    }

    if(_input_simpled[0] - 'A' + 1 > 1 && _input_simpled[0] - 'A' + 1 < 7){
        // 두 번째 문자부터 체크
        int b = _input_simpled.find("AFC");
        cout << b;
    }
    else{}
    cout << output;
}

void Solve(){
    cin >> N;
    for(int n=0; n<N; n++)
        Gene_Check_new();
}

int main(){
    Solve();
    return 0;
}