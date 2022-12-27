/*
    10:35-10:54 19m
*/
#include <iostream>

using namespace std;

int A, B;

int GCD(int a, int b){
    int num1 = max(a, b);
    int num2 = min(a, b);
    int div;

    while(num2 != 0){
        div = num1%num2;
        num1 = num2;
        num2 = div;
    }
    return num1;
}

int LCM(int a, int b){
    return (a*b / GCD(a, b));
}

int main(){
    int T;
    cin >> T;

    for(int t=0; t<T; t++){
        cin >> A >> B;
        cout << LCM(A, B) << '\n';
    }
    return 0;
}