#include<iostream>
#include<vector>

using namespace std;
using ll = long long;
#define mod 998244353
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
    ll n = 3;
    ll r = 4;
    cout << cmb(4,4) << endl;
    return 0;
}