/*
    12:13-12:31, 14:48-15:58, 80m
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int CN, FN, L;
vector<int> current_pos;

bool Count(int length){
    int count=0;
    for(int i=0; i<current_pos.size()-1; i++){
        int diff_with_next = current_pos[i+1] - current_pos[i];

        count += diff_with_next/length;
        if(diff_with_next%length == 0)
            count -= 1;
    }
    //cout << ", " << count << '\n';
    return (count > FN) ? true:false;
}


void Solve(){
    // Init
    int _in;
    cin >> CN >> FN >> L;

    current_pos.push_back(0);
    for(int i=0; i<CN; i++){
        cin >> _in;
        current_pos.push_back(_in);
    }
    current_pos.push_back(L);

    sort(current_pos.begin(), current_pos.end());

    // Binary Search
    int low = 1, high = L, mid;
    while(low <= high){
        mid = (low + high)/2;
        //cout << "low, mid, high: " << low << ", " << mid << ", " << high;
        if(Count(mid))      // 계산되는 (필요한) 휴게소의 개수가 FN보다 많으면 간격을 더 늘려본다.
            low = mid +1;
        else
            high = mid -1;
    }
    cout << low;
}

int main(){
    Solve();
    return 0;
}