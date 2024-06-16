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
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
    }
    vector<int> u(m);
    vector<int> v(m);
    UnionFind solver(n);
    rep(i,m){
        cin >> u[i] >> v[i];
        u[i]--;v[i]--;
        if (a[u[i]] == a[v[i]]){
            solver.unite(u[i],v[i]);
        }
    }
    vector<int> roots;
    rep(i,n){
        roots.emplace_back(solver.root(i));
    }
    vector<vector<int>> graph(n);
    rep(i,m){
        int U,V;
        U = roots[u[i]];
        V = roots[v[i]];
        if (U != V){
            graph[U].push_back(V);
            graph[V].push_back(U);
        }
    }
    

    priority_queue<pair<int,int>> que;
    que.push(make_pair(1,roots[0]));
    vector<int> ans(n,-100000);
    ans[roots[0]] = 1;
    map<int,vector<int>> potential2nodes;
    rep(i,n){
        potential2nodes[a[i]].emplace_back(i);
    }
    vector<int> potentialList(n);
    copy(a.begin(),a.end(),potentialList.begin()); 
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    for (int potential:a){
        for (int u:potential2nodes[potential]){
            for (int v:graph[roots[u]]){
                if (potentialList[v] > potentialList[u] & ans[u] > 0) ans[v] = max(ans[v], ans[u] + 1);
            }
        }
    }
    cout << max(0,ans[roots[n-1]]) << endl;
}