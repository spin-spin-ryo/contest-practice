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

using namespace std;
using ll = long long;
#define mod 998244353
using  vector2d = vector<vector<ll> >;


class UnionFind{
    vector<ll> parent;
    


    public:
    vector<bool> cycle;
    explicit UnionFind(size_t size):parent(size),cycle(size){
        for (ll i=0;i<size;i++){
            parent[i] = i;
            cycle[i] = false;
        } 
    }

    ll root(ll x){
        if (parent[x] == x) return x;
        return parent[x] = root(parent[x]);
    }

    void unite(ll x,ll y){
        ll rx = root(x);
        ll ry = root(y);
        if (rx == ry){
            cycle[rx] = true;
            return;
        }
        parent[rx] = ry;
        if (cycle[rx] || cycle[ry]){
            cycle[ry] = true;
            cycle[rx] = true;
        }
        
    }

    bool same(ll x, ll y){
        ll rx = root(x);
        ll ry = root(y);
        return rx==ry;
    }

};

template<typename T>
struct SparseTable{
    vector<vector<T> >st;
    vector<ll> lookup;
    
    SparseTable() = default;
    SparseTable(const vector<T> &v){
        ll b = 0;
        while ((1<<b) <= v.size()) ++b;
        st.assign(b,vector<T>(1<<b));
        for (ll i=0;i<v.size();i++){
            st[0][i] = v[i];
        }

        for (ll i=1;i<b;i++){
            for (ll j=0;j+(1 << i) <= (1<<b);j++){
                st[i][j] = min(st[i-1][j],st[i-1][j + (1 << (i-1))]);
            }
        }
        lookup.resize(v.size() + 1);

        for (ll i=2;i < lookup.size();i++){
            lookup[i] = lookup[i>> 1] + 1;
        }
    }

    inline T rmq(ll l, ll r){
        ll b = lookup[r-l];
        return min(st[b][l],st[b][r - (1<<b)]);
    }
};

class LCA{
    public:
    LCA() = default;
    
    explicit LCA(vector<vector<pair<ll,ll> > > &g){
        V = g.size();
        first_appear.resize(V);
        visited.resize(V);
        dis.resize(V);
        DFS(0,0,0,g);
        build();
    }

    void DFS(ll v, ll d,ll now_dis, vector<vector<pair<ll,ll>> > &graph){
        visited[v] = true;
        dis[v] = now_dis;
        first_appear[v] = euler.size();
        euler.push_back(make_pair(d,v));
        for (ll i=0;i<graph[v].size();i++){
            ll u = graph[v][i].first;
            ll w = graph[v][i].second;
            if (!visited[u]){
                DFS(u,d+1,now_dis + w,graph);
                euler.push_back(make_pair(d,v));
            }
        }
    }

    void build(){
        sp = SparseTable<pair<ll,ll>>(euler);
    }

    ll lca(ll u, ll v){
        ll p1 = first_appear[u];
        ll p2 = first_appear[v];

        if (p2 < p1) swap(p1,p2);
        pair<ll,ll> p = sp.rmq(p1,p2+1);
        return p.second;
    }
    vector<ll> dis;

    private:
    vector<pair<ll,ll> > euler;
    vector<ll> first_appear;
    vector<bool> visited;
    
    ll V;
    SparseTable<pair<ll,ll>> sp;
};


int main(){
    ll N,M,Q;cin >> N >> M >>Q;
    vector<vector<pair<ll,ll> > > weight_graph(N+1);
    UnionFind components(N);
    vector<pair<ll,pair<ll,ll>>> temp_edges;
    for (ll i=0;i<M;i++){
        ll a,b,c; cin >> a >> b >> c;
        if (components.same(a-1,b-1)){
            temp_edges.push_back(make_pair(c,make_pair(a,b)));
        }else{
            weight_graph[a].push_back(make_pair(b,c));
            weight_graph[b].push_back(make_pair(a,-c));
        }
        components.unite(a-1,b-1);        
    }
    for (ll i=0;i<N;i++){
        weight_graph[0].push_back(make_pair(i+1,0));
    }
    LCA solver(weight_graph);

    // 保留した枝によってできるサイクルが0出ないかしらべるひつようがある
    vector<bool> absolute_unchanged(N,false);
    for (ll i=0;i<temp_edges.size();i++){
        ll dis_cycle = - solver.dis[temp_edges[i].second.first] + solver.dis[temp_edges[i].second.second] - temp_edges[i].first;
        if (dis_cycle == 0){
            if (!absolute_unchanged[components.root(temp_edges[i].second.first-1)]){
                components.cycle[components.root(temp_edges[i].second.first-1)] = false;
            }
        }else{
            absolute_unchanged[components.root(temp_edges[i].second.first-1)] = true;
            components.cycle[components.root(temp_edges[i].second.first-1)] = true;
        }
    }

    for (ll i=0;i<Q;i++){
        ll x,y; cin >> x >> y;
        x--;y--;
        // 同じ成分か
        if (!components.same(x,y)){
            cout << "nan" << endl;
            continue;
        }

        //　サイクルがあるか
        if (components.cycle[components.root(x)]){
            cout << "inf" << endl;
            continue;
        }

        //距離を計算します
        cout << - solver.dis[x+1] + solver.dis[y+1]  << endl;
    }
    
}