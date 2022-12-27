/*
    00:02~
*/
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    string input, key;
    getline(cin, input);
    cin >> key;

    //vector<char> out;
    string out = "";
    for(int i=0; i<input.length(); i++){
        int value;
        if(input[i] == ' '){
            //out.push_back(' ');
            out += ' ';
            continue;
        }
        value = (int)input[i] - (int)key[i%(key.length())];
        
        if(value < 1)
            value = 26+value;
        //out.push_back(char(value)+'a');
        out += (char)(value + 'a'-1);
    }
    //for(int j=0; j<out.size(); j++)
    //    cout << out[j];
    cout << out << '\n';
    return 0;
}