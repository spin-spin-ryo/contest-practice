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
    ll N; cin >> N;
    vector<ll> ans(N,0);
    vector<ll> prev(N,0);
    prev[0] = 1;
    for (int i=0;i<N-1;i++){
        for (int j=0;j<i+1;j++){
            ans[0] += prev[j] * inv(power(2,i-j+1))%mod;
            ans[0] %= mod;
        }
        ll coef =inv( 2- inv(power(2,i+1)))%mod;
        if (coef < 0) coef += mod;
        ans[0]*= coef;
        ans[0] %= mod;
        for (int j = 1;j<i+2;j++){
            ans[j] = (ans[j-1]*inv(2)%mod + prev[j-1]*inv(2)%mod)%mod;
        }
        rep(j,i+2){
            prev[j] = ans[j];
            ans[j] = 0;
        }
    }
    for (int i=0;i<N;i++){
        cout << prev[i] << " ";
    }

    cout << endl;
}