#include<iostream>
#include<vector>

using namespace std;
using ll = long long;
#define mod 998244353

int main(){
    int N;cin >> N;
    vector<int> a(N);
    for (int i=0;i<N;i++) cin >> a[i];

    
    ll ans = 0;
    for (int n=1;n<N+1;n++){
        vector<vector<vector<ll> > > dp(N+1,vector<vector<ll> >(n,vector<ll>(n+1,0)));
        dp[0][0][0] = 1;
        for (int i=0;i<N;i++){
            for (int j=0;j<n;j++){
                for (int k=0;k<n+1;k++){
                    // 使うとき
                    if (k<n){
                        dp[i+1][(j + a[i]%n)%n][k+1] = (dp[i+1][(j + a[i]%n)%n][k+1] + dp[i][j][k])%mod;
                    }
                    
                    // 使わない時
                    dp[i+1][j][k] += dp[i][j][k];
                    dp[i+1][j][k]%=mod;
                }
            }
        }
        // cout << dp[N][0][n] << endl;
        ans += dp[N][0][n];
        ans %= mod;
    }
    cout << ans << endl;

}