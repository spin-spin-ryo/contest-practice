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
#define MAX_M 300000

ll factorial[MAX_M];
ll factorial_inv[MAX_M];

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

void initialize_factor(){
    factorial[0] = 1;
    factorial_inv[0] = 1;
    for (ll i=1;i<MAX_M;i++){
        factorial[i] = (factorial[i-1]*i)%mod;
        factorial_inv[i] = inv(factorial[i]);
    }
}

ll cmb(ll n, ll r){
    return factorial[n]*factorial_inv[n-r]%mod * factorial_inv[r] % mod;
}


int main(){
    initialize_factor();
    ll N,P;cin >> N >>P ;
    ll ans = 0;
    for (ll k=1;k<=N;k++){
        if (2*k - N >=0){
            ans += k*cmb(k,N-k)%mod * power(P*inv(100)%mod,N-k)%mod * power(1 - P*inv(100)%mod,2*k-N)%mod;
            ans %= mod;
        }
        if (2*k - N - 1 >=0){
            ans += k*cmb(k-1,N-k)%mod * power(P*inv(100)%mod,N + 1 -k)%mod * power(1 - P*inv(100)%mod,2*k-N - 1)%mod;
            ans %= mod;
        }
    }
    if (ans < 0){
        ans += mod;
    }
    cout << ans << endl;
}