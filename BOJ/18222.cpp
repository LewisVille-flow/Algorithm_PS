/*
    15:30~17:33 123m
0 1 1 0 1 0 0 1
0 1 2 3 4 5 6 7
*/
#include <iostream>
#include <cmath>

using namespace std;

int checkpowN(long long num){
    int i=0;
    while(num>1){
        num >>= 1;
        i++;
    }
    return i;
}

bool Solve(long long num){
    if(num == 1)
        return false;

    /*
    long long i;
    for(i=1;i+i<num;i+=i);
	return !Solve(num-i);
    */
    
    /*
    long long m=1;
    int cnt = checkpowN(num);
    if(pow(2, cnt) == num) cnt--;
    for(int i=0; i<cnt; i++)
        m <<= 1;
    long long t = pow(2, cnt);
    cout << "m, pow : " << m << " " << t << '\n';
    return !Solve(num-m);
    */

    /*
    안 되는 방식 .... ->pow는 소수점 일정 자리에서 올림 처리해버린다. 따라서 틀린 계산이 된다.
    pow를 리턴 타입을 지정하고 하면 될듯??? 응... 되네
    /// The function may also cause a range error if the result is too great 
    /// or too small to be represented by a value of the return type.
    */
    int cnt = checkpowN(num);
    long long t = pow(2, cnt);
    if(t == num) t = pow(2, --cnt);
    return !Solve(num-t);
    
}

int main(){
    long long k;
    //int cnt, rev=0;
    cin >> k;
    
    cout << Solve(k);

    return 0;
}