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

using namespace std;
using ll = long long;
#define mod 998244353
#define INF 1e+16
using  vector2d = vector<vector<ll> >;

int main(){
    ll N;cin >> N;
    vector<ll> A(N);
    for (ll i=0;i<N;i++){
        cin >> A[i];
    }
    vector<ll> score(N);
    for (ll i=0;i<N;i++){
        if (i==0){
            score[i] = 0;
        }else{
            score[i] += score[i-1];
            score[i] += A[(i-1)/2];
        }
    }

    // 1日目は休日にしても問題ない
    vector<vector<ll>> dp(N,vector<ll>(N,0));
    // dp[n][i] n曜日において最後の休みがi日前の時の最大値
    dp[0][0] = score[N-1];
    for (ll i=1;i<N;i++){
        for (ll j=i;j>=0;j--){
            if (j==0){
                for (ll k=1;k<i+1;k++){
                    dp[i][0] = max(dp[i][0], dp[i][k] - score[N - i + k-1] + score[k-1] + score[N-i -1]);
                }
            }else{
                if (j>0) dp[i][j] = dp[i-1][j-1];
            }
        }
    }
    ll ans = 0;
    for (ll i=0;i<N;i++){
        ans = max(ans,dp[N-1][i]);
    }
    cout << ans << endl;
    return 0;
}