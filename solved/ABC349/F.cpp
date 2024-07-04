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
#include <unordered_map>

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

ll gcd(ll a,ll b){
    if (a < b) return gcd(b,a);
    if (a%b == 0) return b;
    return gcd(b,a%b);
}

ll lcm(ll a, ll b){
    return (a/gcd(a,b))*b;
}



vector<long long> enum_divisors(long long N) {
    vector<long long> res;
    for (long long i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            // 重複しないならば i の相方である N/i も push
            if (N/i != i) res.push_back(N/i);
        }
    }
    // 小さい順に並び替える
    sort(res.begin(), res.end());
    return res;
}

int main(){
    ll n,m; cin >> n >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> factors = enum_divisors(m);
    unordered_map<ll,bool> isFactor;
    unordered_map<ll,int> factor2Index;
    rep(i,factors.size()){
        isFactor[factors[i]] = true;
        factor2Index[factors[i]] = i;
    }
    vector<vector<ll>> dp(n+1,vector<ll>(factors.size() ,0));

    dp[0][0] = 1;
    rep(i,n){
        rep(j,factors.size()){
            ll p = factors[j];
            ll l = lcm(p,a[i]);
            if (isFactor[l]){
                int index = factor2Index[l];
                dp[i+1][index] += dp[i][j];
                dp[i+1][index] %= mod;
            }
            dp[i+1][j] += dp[i][j];
            dp[i+1][j]%= mod;
        }
    }
    cout << dp[n][factors.size() -1] << endl;
}