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
#define rep(i, x) for(int i = 0; i < (x); i++)

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
    vector<ll> dp(N+1,0);
    vector<ll> sum_dp(N+1,0);
    rep(i,N){
        dp[i+1] = sum_dp[i]*inv(N)%mod;
        dp[i+1] += ((power((inv(N)+1)%mod,i)*inv(N))%mod)*A[i]%mod;
        dp[i+1] %= mod;
        sum_dp[i+1] = (sum_dp[i] + dp[i+1])%mod;
        
    }
    ll ans = 0;
    rep(i,N){
        ans += (dp[i+1]*inv(N)%mod) * (i+1)%mod;
        ans %= mod;
    }
    cout << ans << endl;
}