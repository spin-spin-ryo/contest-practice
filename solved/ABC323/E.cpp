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
    ll N,X; cin >> N >> X;

    vector<ll> T(N);
    rep(i,N) cin >>T[i];
    vector<vector<ll>> dp(X+3,vector<ll>(2,0));
    dp[0][1] = 1;
    

    rep(x,X+2){
        if (x > 0){
            dp[x][0] += dp[x-1][0];
            dp[x][0] %= mod;
        }
        if (x <X+1){
          rep(i,N){
            dp[min(T[i]+x,X+2)][1] += dp[x][1]*inv(N)%mod;
            dp[min(T[i]+x,X+2)][1] %= mod;
            
          }
          dp[x][0] += dp[x][1]*inv(N)%mod;
          dp[x][0] %= mod;  
          dp[min(T[0]+1+x,X+2)][0] -= dp[x][1]*inv(N)%mod;
          dp[min(T[0]+1+x,X+2)][0] %= mod;  
        }
        
    }
    cout << (dp[X+1][0]+mod)%mod << endl;
}