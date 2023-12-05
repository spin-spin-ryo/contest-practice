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
    ll N,A,B,P,Q; cin >> N >> A >> B >> P >> Q;
    vector<vector<ll>> dp1(N-A+1,vector<ll>(N-A+1,0));
    dp1[0][0] = 1;
    vector<vector<ll>> dp2(N-B+1,vector<ll>(N-B+1,0));
    dp2[0][0] = 1;
    for(ll n = 0;n<N-A;n++){
        for(ll x=0;x< N-A;x++){
            for (ll p=1;p<= P;p++){
                dp1[n+1][min(x+p,N-A)] += inv(P)*dp1[n][x];
                dp1[n+1][min(x+p,N-A)] %= mod;
            }
        }
    }
    for(ll n = 0;n<N-B;n++){
        for(ll x=0;x< N-B+1;x++){
            for (ll p=1;p<= Q;p++){
                dp2[n+1][min(x+p,N-B)] += inv(Q)*dp2[n][x];
                dp2[n+1][min(x+p,N-B)] %= mod;
            }
        }
    }

    ll ans = 0;
    for (ll n = 1;n<N-A+1;n++){
        if (n > N-B +1){
            break;
        }else{
            ans += dp1[n][N-A]*(1- dp2[n-1][N-B])%mod;
        }
        ans %= mod;
    }
    if (ans < 0){
        ans += mod;
    }
    cout << ans << endl;
}