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


int main(){
    initialize_factor();
    ll N; cin >> N;
    ll a = 0;
    ll b = 0;
    ll c = 0;
    ll n = N;
    while (n%2 == 0){
        a ++;
        n/= 2;
    }
    while (n%3 == 0){
        b++;
        n/=3;
    }
    while (n%5 == 0){
        c ++;
        n/=5;
    }
    if (n!= 1){
        cout << 0 << endl;
        return 0; 
    }

    ll ans = 0;
    for (ll x2 = 0;x2<= a;x2++){
        for (ll x3 =0;x3<=b;x3++){
            ll x6 = b-x3;
            if ( (a - x6 - x2)%2 != 0) continue;
            ll x4 = (a - x6 - x2)/2;
            if (x4 < 0) continue;
            ll x5 = c;
            ll p = 0;
            ll p2 = 0;
            ll p3 = 0;
            ll p4 = 0;
            ll p5 = 0;
            ll p6 = 0;
            n = x2 +x3+ x4+x5+x6;
            
            if (x2 > 0){
                p2 += factorial_inv[x2-1];
                p2 *= factorial_inv[x3];
                p2%= mod;
                p2 *= factorial_inv[x4];
                p2%= mod;
                p2 *= factorial_inv[x5];
                p2%= mod;
                p2 *= factorial_inv[x6];
                p2%= mod;
            }
            if (x3 > 0){
                p3 += factorial_inv[x2];
                p3 *= factorial_inv[x3-1];
                p3%= mod;
                p3 *= factorial_inv[x4];
                p3%= mod;
                p3 *= factorial_inv[x5];
                p3%= mod;
                p3 *= factorial_inv[x6];
                p3%= mod;
            }
            if (x4 > 0){
                p4 += factorial_inv[x2];
                p4 *= factorial_inv[x3];
                p4%= mod;
                p4 *= factorial_inv[x4-1];
                p4%= mod;
                p4 *= factorial_inv[x5];
                p4%= mod;
                p4 *= factorial_inv[x6];
                p4%= mod;
            }
            if (x5 > 0){
                p5 += factorial_inv[x2];
                p5 *= factorial_inv[x3];
                p5%= mod;
                p5 *= factorial_inv[x4];
                p5%= mod;
                p5 *= factorial_inv[x5-1];
                p5%= mod;
                p5 *= factorial_inv[x6];
                p5%= mod;
            }
            if (x6 > 0){
                p6 += factorial_inv[x2];
                p6 *= factorial_inv[x3];
                p6%= mod;
                p6 *= factorial_inv[x4];
                p6%= mod;
                p6 *= factorial_inv[x5];
                p6%= mod;
                p6 *= factorial_inv[x6-1];
                p6%= mod;
            }
            p += p2;
            p %= mod;
            p += p3;
            p %= mod;
            p += p4;
            p %= mod;
            p += p5;
            p %= mod;
            p += p6;
            p %= mod;
            p*= factorial[n-1];
            p%= mod;
            p*= power(inv(5),n);
            p%= mod;
            ans += p;
            ans %= mod;
        }
    }
    cout << ans << endl;
    return 0;
}