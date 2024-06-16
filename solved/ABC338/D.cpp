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
#include <atcoder/lazysegtree>

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

using S = long long;
using F = long long;
S op(S a, S b){
  return min(a,b);
}
S e(){
  return INF;
}
S mapping(F f, S x){ return f+x; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

int main(){
    ll n,m; cin >> n >> m;
    vector<ll> x(m);
    vector<ll> v(n+10,0);
    rep(i,m){
        cin >> x[i];
        x[i]--;
    }
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);
    ll ans = 0;
    rep(i,m-1){
        ll l = abs(x[i] - x[i+1]);
        ans += min(l, n - l);
        ll a = x[i];
        ll b = x[i+1];
        if (b<a){
            swap(a,b);
        }
        if (2*(b-a) < n){
            seg.apply(a,b,n - 2*(b-a));
        }else{
            seg.apply(0,a,2*(b-a) - n);
            seg.apply(b,n,2*(b-a) - n);
        }
    }
    ans += seg.prod(0,n);
    cout << ans << endl;
}