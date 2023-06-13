#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <algorithm>
#include <stack>
#include <utility>
#include <queue>
#include <map>
#include <iomanip>

// unsolved

using namespace std;
using ll = long long;
#define mod 998244353
using  vector2d = vector<vector<int> >;

int main(){
    int N,K;cin >> N >> K;
    vector<int> A(K);
    for (int i=0;i<K;i++) cin >> A[i];
   vector<vector<int> > dp(N+1,vector<int>(2,0));
   for (int i=0;i<N;i++){
    for (int k=0;k<K;k++){
        if (i+A[k]<=N){
            if (dp[i+A[k]][0]==0){
                dp[i+A[k]][0] = dp[i][1];
            }else{
                dp[i+A[k]][0] = min(dp[i+A[k]][0],dp[i][1]);
            }
            dp[i+A[k]][1] = max(dp[i+A[k]][1],dp[i][0] + A[k]);
        }
    }
   }
   cout << dp[N][1] << endl;

}