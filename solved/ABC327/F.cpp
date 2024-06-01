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
#include "atcoder/lazysegtree"

using namespace std;
using ll = long long;
#define mod 998244353
#define INF 1e+16
#define rep(i, x) for(int i = 0; i < (x); i++)

using  vector2d = vector<vector<int> >;
using S = long long;
using F = long long;


S op(S a, S b){ return std::max(a, b); }
S e(){ return -INF; }
S mapping(F f, S x){ return f+x; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

template <typename T>
void print(vector<T> v){
    rep(i,v.size()){
        cout << v[i] << endl;
    }
    return;
}

F one(){
    return 1;
}
F minus_one(){
    return -1;
}

int main(){
    std::vector<S> v(200001);
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);
    int N,D,W; cin >> N >> D >> W;
    vector<int> T(N),X(N);
    vector<vector<int>> XtoT(200001);
    rep(i,N){
        cin >> T[i] >> X[i];
        XtoT[X[i]].push_back(T[i]);
    }
    int L = 1;
    rep(i,W){
        int s = L+i;
        rep(j,XtoT[s].size()){
            int t = XtoT[s][j];
            seg.apply(max(t-D+1,0),min(t+1,200001),one());
        }
    }
    ll ans = 0;
    for(ll L = 1;L<200001-W;++L){
        ans = max(ans,seg.all_prod());
        rep(j,XtoT[L].size()){
            int t = XtoT[L][j];
            seg.apply(max(t-D+1,0),min(t+1,200001),minus_one());
        }
        rep(j,XtoT[L+W].size()){
            int t = XtoT[L+W][j];
            seg.apply(max(t-D+1,0),min(t+1,200001),one());
        }
    }
    ans = max(ans,seg.all_prod());
    cout << ans << endl;
    
}