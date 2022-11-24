#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

//vector<int> v;
vector<int> for_compare;
vector<bool> result;
int M, N;

bool BinarySearch(int target, vector<int> &v, int left, int right){
    //cout << "loop" << '\n';
    if(left > right)
        return false;

    int mid = (left + right) / 2;
    if(target == v[mid]){
        return true;
    }
    if(target < v[mid]){
        return BinarySearch(target, v, left, mid-1);
    }
    if(target > v[mid]){
        return BinarySearch(target, v, mid+1, right);
    }
}

int main(){
    ios_base::sync_with _stdio(0);
	cin.tie(NULL);
    cout.tie(NULL);
    
    int tmp_1, tmp_2;
    int left, right, target;
   
    cin >> M;
    vector<int> v(M);
    for(int i=0; i<M; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    cin >> N;
    for(unsigned int m=0; m<N; m++){
        cin >> target;
        cout << BinarySearch(target, v, 0, M-1) << " ";
    }   

    return 0;
}