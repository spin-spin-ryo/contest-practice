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

class UnionFind{
    vector<int> parent;


    public:
    vector<int> connection_size;
    explicit UnionFind(size_t size):parent(size){
        connection_size.resize(size,1);
        for (int i=0;i<size;i++) parent[i] = i;
    }

    int root(int x){
        if (parent[x] == x) return x;
        return parent[x] = root(parent[x]);
    }

    void unite(int x,int y){
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        parent[rx] = ry;
        connection_size[ry] += connection_size[rx];
        connection_size[rx] = 0;
    }

    bool same(int x, int y){
        int rx = root(x);
        int ry = root(y);
        return rx==ry;
    }

    int get_size(int x){
        int rx = root(x);
        return connection_size[rx];
    }

};

int main(){
    int n,m; cin >> n >> m;
    vector<int> a(m);
    vector<int> b(m);
    UnionFind solver(n);
    rep(i,m){
        cin >> a[i] >> b[i];
        a[i]--;b[i]--;
        solver.unite(a[i],b[i]);
    }
    vector<int> root;
    rep(i,n){
        root.push_back(solver.root(i));
    }
    sort(root.begin(),root.end());
    root.erase(unique(root.begin(),root.end()),root.end());
    unordered_map<ll,ll> edge_num;
    unordered_map<ll,ll> nodes_num;
    rep(i,m){
        int index = solver.root(a[i]);
        edge_num[index]++;
        nodes_num[index] = solver.get_size(a[i]);
    }
    ll ans = 0;
    auto itr = nodes_num.begin();
    while(itr != nodes_num.end()){
        ll key = (*itr).first;
        ans += nodes_num[key]*(nodes_num[key] - 1)/2 - edge_num[key];
        itr++;
    }
    cout << ans << endl;
}