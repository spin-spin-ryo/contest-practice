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
using  vector2d = vector<vector<int> >;


ll power(ll n, ll r){
    ll ans = 1;
    for (int i=0;(r>>i) >0 ;i++){
        if ((r>>i)&1){
            ans *= n;
            ans %= mod;
        }
        n *= n;
        n %= mod;
    }
    return ans;
}

ll inv(ll n){
    return power(n, mod-2);
}


int main(){
    ll N,M,K;cin >> N >> M >> K;
    ll m_inv = inv(M);
    vector<vector<ll> > dp(N+1,vector<ll>(K+1,0));
    dp[0][0] = 1;
    for (ll k=0;k<K;k++){
        for (ll i = 0;i<N;i++){
            for (int m = 1;m<=M;m++){
                if (i+m<= N){
                    dp[i+m][k+1] += dp[i][k]*m_inv%mod;
                    dp[i+m][k+1] %= mod;
                }else{
                    dp[2*N - i -m][k+1] += dp[i][k]*m_inv%mod;
                    dp[2*N - i -m][k+1] %= mod;
                }
                
            }
        }
    }
    ll ans = 0;
    for (int i=1;i<=K;i++){
        ans += dp[N][i];
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}