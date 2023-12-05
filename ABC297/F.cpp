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
#define rep(i, x) for(int i = 0; i < (x); i++)

#define MAX_M 1000100

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
    if (r > n){
        return 0;
    }
    if (n <= 0 || r < 0){
        return 0;
    }
    return factorial[n]*factorial_inv[n-r]%mod * factorial_inv[r] % mod;
}

ll get_prob(ll h, ll w, ll k, ll H, ll W){
    ll a = 0;
    a += cmb(h*w,k);
    a %= mod;
    a -= 2*cmb((h-1)*w,k)%mod;
    a %= mod;
    a += cmb((h-2)*w,k)%mod;
    a %= mod;
    a -= 2*cmb((w-1)*h,k)%mod;
    a %= mod;
    a += cmb((w-2)*h,k)%mod;
    a %= mod;
    a += 4*cmb((h-1)*(w-1),k)%mod;
    a %= mod;
    a -= 2*cmb((h-2)*(w-1),k)%mod;
    a %= mod;
    a -= 2*cmb((w-2)*(h-1),k)%mod;
    a %= mod;
    a += cmb((w-2)*(h-2),k)%mod;
    a %= mod;
    a *= inv(cmb(H*W,k)%mod);
    a %= mod;
    return a;
}

int main(){
    initialize_factor();
    ll H,W,k; cin >> H >> W >> k;
    if (k==1){
        cout << 1 << endl;
        return 0;
    }
    ll ans = 0;
    for (ll h = 1;h<= H ;h++){
        for (ll w = 1;w <= W;w++){
            ll count = (H-h+1)*(W-w+1)%mod;
            ll p = get_prob(h,w,k,H,W);
            ll m = (h*w%mod);
            m %= mod;
            m *= count;
            m%= mod;
            m *= p;
            m %= mod;
            ans += m;
            ans %= mod; 
        }
    }
    if (ans < 0){
        ans += mod;
    }
    cout << ans << endl;
}