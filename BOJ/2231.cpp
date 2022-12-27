/*
    1010-10:38 28m
*/
#include <iostream>
#include <cmath>
using namespace std;

int simpleFunction(int n){
    int sum = n;

    // 일의 자리부터 하나씩 제거해나가며 더한다.
    while(n){
        sum += n%10;
        n = n/10;
    }
    return sum;
}

int main(){
    int N;
    cin >> N;
    
    /*
    // 기존 방법, 바보같이 연산이 너무 많다.
    for(i=1; i<N; i++){
        int n = i;
        int sum = n;
        for(int z=6; z>0; z--){
            
            int tenpow = pow(10, z);
            int v = n / tenpow;         // 몫
            sum += v;
            if(v != 0)
                n = n-(v*tenpow);
        }        
        int v = n%10;
        sum += v;
        //cout << "i, sum: " << i << ", " << sum << '\n';
        if(sum == N){
            cout << i;
            break;
        }
    }
    if(i == N)
        cout << "0";

    */
    int out;
    for(int i=1; i<N; i++){
        out = simpleFunction(i);
        //cout << "out: " << out << '\n';
        if(out == N){
            cout << i;
            return 0;
        }
    }
    cout << "0";

    return 0;
}