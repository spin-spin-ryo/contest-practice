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
#define rep(i, x) for(ll i = 0; i < (x); i++)

using  vector2d = vector<vector<ll> >;

template <typename T>
void prll(vector<T> v){
    rep(i,v.size()){
        cout << v[i] << endl;
    }
    return;
}

class WeightedUnionFind{
    vector<ll> parent;
    vector<ll> rank;
    vector<ll> diff_weight;
    // diff_weightは親に対する枝での重みを累積したもの


    public:
    vector<ll> connection_size;
    explicit WeightedUnionFind(size_t size):parent(size){
        connection_size.resize(size,1);
        diff_weight.resize(size,0);
        rank.resize(size,0);
        for (ll i=0;i<size;i++) parent[i] = i;
    }

    ll root(ll x){
        if (parent[x] == x) return x;
        ll r = root(parent[x]);
        diff_weight[x] += diff_weight[parent[x]];
        return parent[x] = r;
    }

    void unite(ll x,ll y, ll w){
        w+= weigth(x);
        w-= weigth(y);
        ll rx = root(x);
        ll ry = root(y);
        if (rx == ry) return;
        parent[ry] = rx;
        diff_weight[ry] = w;
        connection_size[rx] += connection_size[ry];
        connection_size[ry] = 0;
    }

    ll weigth(ll x){
        root(x);
        return diff_weight[x];
    }

    bool same(ll x, ll y){
        ll rx = root(x);
        ll ry = root(y);
        return rx==ry;
    }

    ll get_size(ll x){
        ll rx = root(x);
        return connection_size[rx];
    }

    ll diff(ll x, ll y){
        return weigth(y) - weigth(x);
    }

};


int main(){
    ll n,q; cin >> n >> q;
    ll a,b,d;
    WeightedUnionFind solver(n);
    vector<ll> ans;
    rep(i,q){
        cin >>a >> b >> d;
        a--;b--;
        if (solver.same(a,b)){
            if (solver.diff(a,b) == d){
                ans.push_back(i+1);
            }
        }else{
            solver.unite(a,b,d);
            ans.push_back(i+1);
        }
    }
    rep(i,ans.size()){
        cout << ans[i] << " ";
    }
    cout << endl;
}