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

int main(){
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll sqrt_n = 500;
    vector<ll> dp(n,0);
    dp[0]=1;
    vector<vector<ll>> dp2(sqrt_n,vector<ll>(sqrt_n,0));
    rep(i,n){
        for (int j=1;j<sqrt_n;j++){
            dp[i] += dp2[j][i%j];
            dp[i] %= mod;
        }
        if(a[i] < sqrt_n){
            dp2[a[i]][i%a[i]] += dp[i];
            dp2[a[i]][i%a[i]] %= mod;        
        }else{
            for(ll j = 1;i+a[i]*j<n;j++){
                dp[i+a[i]*j] += dp[i];
                dp[i+a[i]*j] %= mod;
            }
        }
    }
    ll ans = 0;
    rep(i,n){
        ans += dp[i];
        ans %= mod;
    }
    cout << ans << endl;
}