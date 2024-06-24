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
#include <atcoder/segtree>

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

struct counter{
    public:
    pair<ll,ll> first = {0,0};
    pair<ll,ll> second = {0,0};
    counter() = default;
    counter(int n){
        this->first.first = n;
        this->first.second = 1;
    }
};

using S = counter;
S op(S a, S b){
  map<ll,ll> count;
  count[a.first.first] += a.first.second;
  count[a.second.first] += a.second.second;
  count[b.first.first] += b.first.second;
  count[b.second.first] += b.second.second;
  if (count.size() == 1){
    auto itr = count.end();
    itr--;
    counter c;
    c.first.first = (*itr).first;
    c.first.second = (*itr).second;
    return c;
  }else{
    auto itr = count.end();
    itr--;
    counter c;
    c.first.first = (*itr).first;
    c.first.second = (*itr).second;
    itr--;
    c.second.first = (*itr).first;
    c.second.second = (*itr).second;
    return c;
  }
}
S e(){
  return counter();
}

int main(){
    int n,Q; cin >> n >> Q;
    vector<int> a(n);
    vector<S> vec(n);
    rep(i,n){
        cin >> a[i];
        vec[i] = counter(a[i]);
    }
    atcoder::segtree<S,op,e> seg(vec);
    while(Q>0){
        Q--;
        int q; cin >> q;
        if (q == 1){
            int p,x; cin >> p >> x;
            p--;
            seg.set(p,counter(x));
        }else{
            int l,r; cin >> l >> r;
            l--;
            S c = seg.prod(l,r);
            cout << c.second.second << endl;
        }
        
    }
}