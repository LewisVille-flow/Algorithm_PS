/*
    11:16-11:43
    - 문자열 비교를 위한 compare, assign, push_back 등 기본적인 문자열 처리 방법의 이해
*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

string Solve(){
    string answer = "";
    vector<char> st;
    string input_str, input_exp;
    cin >> input_str >> input_exp;

    for(int i=0; i<input_str.size(); i++){
        char now = input_str[i];

        if(now == input_exp[input_exp.size()-1] && st.size() >= input_exp.size()-1){
            string comp;
            comp.assign(st.end()-(input_exp.size()-1), st.end());
            comp.push_back(now);

            if(comp.compare(input_exp) == 0){
                //cout << "exp" << '\n';
                for(int s=0; s<input_exp.size()-1; s++)
                    st.pop_back();
            }
            else
                st.push_back(now);
        }
        else
            st.push_back(now);

    }
    if(st.size() > 0){
        for(int a=0; a<st.size(); a++)
            answer.push_back(st[a]);
    }
    else
        answer="FRULA";

    return answer;

}

int main(){
    string output = Solve();
    cout << output;
    return 0;
}