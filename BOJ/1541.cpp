/*
    18:23-19:07, 44m
*/
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

string input;
stringstream ss;
vector<int> number;
vector<char> oper;

int main(){
    cin >> input;
    ss.str(input);

    int num;
    char op;
    while(ss >> num >> op){
        number.push_back(num);
        oper.push_back(op);
    }
    number.push_back(num);

    int answer = number[0], sum = 0;
    bool minus = false;
    for(int i=0; i<oper.size(); i++){
        if(oper[i] == '+' && !minus)
            answer += number[i+1];
        
        else if(oper[i] == '+' && minus)
            sum += number[i+1];

        else if(oper[i] == '-' && !minus){
            minus = true;
            sum += number[i+1];
        }
        else if(oper[i] == '-' && minus){
            answer -= sum;
            sum = number[i+1];
        }
    }
    if(sum != 0)
        answer -= sum;

    cout << answer;

    return 0;
}