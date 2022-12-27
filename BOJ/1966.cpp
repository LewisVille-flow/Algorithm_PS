/*
    17:20-17:30, 19:10-19:50 50m
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int N_MAX=101;

int main(){
    int T;
    cin >> T;
    for(int t=0; t<T; t++){
        //
        int N, M, _in;
        vector<int> for_compare;
        queue<pair<int, int>> q;

        cin >> N >> M;
        for(int n=0; n<N; n++){
            cin >> _in;
            for_compare.push_back(_in);
            q.push(make_pair(_in, n));
        }

        //
        sort(for_compare.begin(), for_compare.end(), greater<int>());
        int answer = 0, target = M;
        while(true){
            int cur = q.front().first;
            int idx = q.front().second;
            q.pop();
            cout << "cur, idx, ans: " << cur << ", "<< idx << ", " << answer << '\n';
            if(for_compare.front() == cur){
                answer++;
                if(idx == target)
                    break;
                else
                    for_compare.erase(for_compare.begin());
            }
            else
                q.push(make_pair(cur, idx));
        }
        cout << answer << '\n';
    }
    return 0;
}
