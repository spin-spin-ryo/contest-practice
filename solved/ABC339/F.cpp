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
#include <random>

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
    random_device seed_gen;
    mt19937_64 engine(seed_gen());
    vector<ll> S(20);
    rep(i,20){
        S[i] = 1000000000 + engine()%1000000000;
    }
    ll n; cin >> n;
    vector<vector<ll>> a(n,vector<ll>(20,0));
    rep(i,n){
        string s; cin >> s;
        rep(k,20){
            rep(j,s.size()){
                a[i][k] = (a[i][k]*10 %S[k] + (ll)(s[j]-'0'))%S[k];
            }
        }
    }

    sort(a.begin(),a.end());
    
    ll ans = 0;
    rep(i,n){
        rep(j,n){
            vector<ll> b(20);
            rep(k,20){
                b[k] = a[i][k]*a[j][k]%S[k];
            }
            auto itrlb = lower_bound(a.begin(),a.end(),b);
            auto itrub = upper_bound(a.begin(),a.end(),b);
            ans += (itrub - itrlb);

        }
    }
    cout << ans << endl;
    return 0;
}