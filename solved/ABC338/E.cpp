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
// 区間和区間加算
S op(S a, S b){
  return a+b;
}
S e(){
  return 0;
}
S mapping(F f, S x){ return f+x; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

int main(){
    ll n; cin >> n;
    vector<pair<ll,ll>> points(n);
    rep(i,n){
        ll a,b; cin >> a >> b;
        a--;b--;
        if (b<a) swap(a,b);
        points[i].first = a;
        points[i].second = b;
    }
    sort(points.begin(),points.end());
    vector<ll> count(2*n,0);
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(count);
    rep(i,n){
        int a = points[i].first,b = points[i].second;
        int count1 = seg.get(a);
        int count2 = seg.get(b);
        if (count1!= count2){
            cout << "Yes" << endl;
            return 0;
        }
        seg.apply(a,b+1,1);
    }
    cout << "No" << endl;
    return 0;
}