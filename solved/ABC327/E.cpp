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
#include <cmath>
#include <set>
#include <list>
#include <deque>
#include <limits>

using namespace std;
using ll = long long;
using ld = long double;
#define mod 998244353
#define INF 1e+16
#define rep(i, x) for(int i = 0; i < (x); i++)

using  vector2d = vector<vector<int> >;

template <typename T>
void print(vector<T> v){
    rep(i,v.size()){
        cout << v[i] << endl;
    }
    return;
}




int main(){
    int N;cin >> N;
    vector<long double> P(N);
    rep(i,N) cin >> P[i];
    vector<vector<ld>> dp(N+1,vector<ld>(N+1,0));
    vector<long double> r09(N+1,1);
    rep(i,N){
        r09[i+1] = r09[i]*0.9;
    }
    rep(i,N){
        rep(k,i+1){
            // 使う場合
            long double now_rate = dp[i+1][k+1];
            long double next_rate = dp[i][k]*0.9 + P[i];
            if (next_rate > now_rate){
                dp[i+1][k+1] = dp[i][k]*0.9 + P[i];
            }
            // 使わない場合
            if (k!=0){
                now_rate = dp[i+1][k];
                next_rate =  dp[i][k];
                if (next_rate > now_rate){
                    dp[i+1][k] = dp[i][k];
                }
            }
            if (k==N-1){
                now_rate = dp[i+1][k+1];
                next_rate =  dp[i][k+1];
                if (next_rate > now_rate){
                    dp[i+1][k+1] = dp[i][k+1];
                }
            }
            
        }
    }
    long double ans = -10000;
    rep(k,N){
        long double r = 10 - 10*r09[k+1];
        ans = max(ans,dp[N][k+1]/r - 1200/(sqrt(k+1)));
        // cout << dp[N][k+1] << endl;
    }
    cout << setprecision(16) <<ans << endl;
}
