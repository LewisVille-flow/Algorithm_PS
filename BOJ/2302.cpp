 /*
    16:54-17:27 30m
 */

#include <iostream>

using namespace std;

int main(){
   int N, M, answer = 1, idx = 1;
   int dp_array[41];

   cin >> N >> M;

   dp_array[0] = 1;
   dp_array[1] = 1;
   dp_array[2] = 2;
   dp_array[3] = 3;

   for(int i=4; i<=N; i++)
      dp_array[i] = dp_array[i-1] + dp_array[i-2];

   for(int n=0; n<M; n++){
      int vip;
      cin >> vip;

      answer *= dp_array[vip - idx];
      idx = vip + 1;
   }
   answer *= dp_array[(N+1) - idx];

   cout << answer;

   return 0;
}