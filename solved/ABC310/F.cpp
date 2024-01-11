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
#define mod 998244353
#define INF 1e+16
#define rep(i, x) for(ll i = 0; i < (x); i++)

using  vector2d = vector<vector<int> >;

template <typename T>
void print(vector<T> v){
    rep(i,v.size()){
        cout << v[i] << endl;
    }
    return;
}

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
    ll N;cin >> N;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];
    vector<vector<ll>> dp(N+1,vector<ll>(1<<10,0));
    dp[0][0] = 1;
    rep(n,N){
        
       rep(a,min(A[n]+1,ll(11))){
            rep(S,1<<10){
                
                if (a == 0){
                    ll r =  inv(A[n]) %mod;
                    r *= max((ll)0, A[n] - 10);
                    r%= mod;
                    dp[n+1][S] += dp[n][S] * r %mod;
                    dp[n+1][S] %= mod;
                }else{
                    ll s = 1 << (a-1);
                    s = s | (S << a);
                    s = s & ((1<< 10) - 1);
                    s = S | s;
                    
                    dp[n+1][s] += dp[n][S]*inv(A[n])%mod;
                    dp[n+1][s] %= mod;
                }
            }
       }
    }
    ll ans = 0;
    for (int i= (1<<9);i< (1<<10);i++){
        ans += dp[N][i];
        ans %= mod;
    }
    cout << ans << endl;
}