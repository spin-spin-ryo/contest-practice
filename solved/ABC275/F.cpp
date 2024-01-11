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

using namespace std;
using ll = long long;
#define mod 998244353
#define INF 1e+16
using  vector2d = vector<vector<ll> >;

int main(){
    ll N,M;cin >> N >> M;
    vector<ll> a(N);
    for (ll i=0;i<N;i++) cin >> a[i];
    vector<vector< vector<ll> > > dp(N+1,vector<vector<ll> > (M+1,vector<ll>(2,INF)));
    dp[0][0][1] = 0;
    for (ll n=0;n<N;n++){
        for (ll m=0;m<=M;m++){
            //使わないとき
            dp[n+1][m][0] = min(dp[n+1][m][0],dp[n][m][0]);
            dp[n+1][m][0] = min(dp[n+1][m][0],dp[n][m][1]+1);

            //使う時
            if (m+a[n] <= M){
                dp[n+1][m+ a[n]][1] = min(dp[n+1][m + a[n]][1],dp[n][m][1]);
                dp[n+1][m+ a[n]][1] = min(dp[n+1][m + a[n]][1],dp[n][m][0]);
            }
        }
    }
    for (ll i=1;i<=M;i++){
        if (min(dp[N][i][0],dp[N][i][1]) == INF){
            cout << -1 << endl;
        }else{
            cout << min(dp[N][i][0],dp[N][i][1]) << endl;
        }
        
    }
    return 0;
}