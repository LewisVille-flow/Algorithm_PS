/*
    19:57-20:46
    - 최대 거리를 찾는 데에 이분탐색을 쓰자. 
    - 해당 거리로 공유기를 놓을 수 있다면 그 상태에서 더 멀리 놓을 수 있는지 탐색한다(left = mid + 1)
    - 공유기를 놓을 수 있는가? -> 개수 체크, 위치 체크
    - 놓을 수 있는가 확인이 이 문제의 핵심인 듯. 거리가 5다 -> 5의 배수?

    예제
    1 2 0 4 0 0 0 8 9
    V     V       V or
    V     V         V
    - count
    시작 지점과 비교지점의 거리 차 >= mid 이면 시작지점 = 비교지점, count ++
    count >= 공유기 수 이면 거리를 늘려보고
    아니면 거리를 줄인다
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N, C;
vector<int> input;

int Count(int mid){
    int count = 1;
    int now=input[0], next=input[1];
    //cout << now << " ";
    for(int i=1; i+1<=N; i++){
        if((next - now) >= mid){
            //cout << next << " ";
            now = next;
            count ++;
        }
        else{}
        if(i+1 != N) next = input[i+1];
    }
    //cout << '\n';
    return count;
}

int Count_v2(int mid){
    int count = 1;
    int now = input[0];
    for(int i=1; i<N; i++){
        int next = input[i];
        if(next - now >= mid){
            count ++;
            now = next;
        }
    }
    return count;
}


void Solve(){
    int _in;
    cin >> N >> C;
    for(int i=0; i<N; i++){
        cin >> _in;     
        input.push_back(_in);
    }
    sort(input.begin(), input.end());

    int left=1, right=input[N-1], mid=(right+left)/2;
    int count;
    int answer = -1;
    while(left <= right){
        mid = (right+left)/2;
        //count = Count(mid);
        count = Count_v2(mid);
        
        //cout << "left, mid, right: " << left << ", " << mid << ", " << right << ", and cnt: " << count << '\n';
        if(count >= C){
            left = mid + 1;
            answer = max(answer, mid);
        }
        else
            right = mid - 1;
    }
    cout << answer;

}

int main(){
    Solve();
    return 0;
}