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

using namespace std;
using ll = long long;
#define mod 998244353
#define INF 1e+16
#define rep(i, x) for(ll i = 0; i < (x); i++)

using  vector2d = vector<vector<ll> >;

void dfs(ll u, vector<vector<pair<ll,ll>>> &graph, vector<ll> &dis,vector<ll> &first_visit,vector<ll> &first_leaf, vector<ll> &finish,ll &first_time, ll &finish_time,queue<int> &que){
    bool leaf_flag = true;
    que.push(u);
    for (auto p:graph[u]){
        ll v,w;
        v = p.first;
        w = p.second;
        if (first_visit[v]==-1){
            leaf_flag = false;
            first_visit[v] = first_time;
            dis[v] = dis[u] + w;
            first_time++;
            dfs(v,graph,dis,first_visit,first_leaf,finish,first_time,finish_time,que);
        }
    }
    if (leaf_flag){
        while (!que.empty()){
            int v = que.front();
            que.pop();
            first_leaf[v] = u;
        }
    }
    finish[u]=finish_time;
    finish_time++;
    return;
}

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
    
    explicit LCA(vector<vector<ll> > &g){
        V = g.size();
        first_appear.resize(V);
        visited.resize(V);
        DFS(0,0,g);
        build();
    }

    void DFS(ll v, ll d, vector<vector<ll> > &graph){
        visited[v] = true;
        first_appear[v] = euler.size();
        euler.push_back(make_pair(d,v));
        for (ll i=0;i<graph[v].size();i++){
            ll u = graph[v][i];
            if (!visited[u]){
                DFS(u,d+1,graph);
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


    private:
    vector<pair<ll,ll> > euler;
    vector<ll> first_appear;
    vector<bool> visited;
    ll V;
    SparseTable<pair<ll,ll>> sp;
};

class BIT{
    // 1-indexed
    public:

    BIT() = default;
    // 入力は0-indexed
    explicit BIT(size_t size): m_bit(size+1){}

    explicit BIT(const vector<long long>& v) : m_bit(v.size()+1){
        for (ll i=0;i<v.size();i++){
            add((i+1),v[i]);
        }
    }

    // a[1] + ... + a[r]
    long long sum(ll r) const{
        long long ret = 0;
        for (; 0< r;r-=(r& -r)){
            ret += m_bit[r];
        }

        return ret;
    }

    // a[r] +  ... + a[l]
    long long sum(ll l, ll r) const{
        return (sum(r) - sum(l-1));
    }

    void add(ll i, long long value){
        for (;i< m_bit.size();i+= (i& -i)){
            m_bit[i] += value; 
        }
    }

    private:
    
    vector<long long> m_bit;

};

class BIT_RAQ{
    public:
    BIT_RAQ() = default;

    explicit BIT_RAQ(size_t size): m_bit0(size),m_bit1(size) {}

    explicit BIT_RAQ(const vector<long long>& v): m_bit0(v), m_bit1(v.size()) {}

    long long sum(ll r) const{
        return (m_bit0.sum(r) + m_bit1.sum(r)*r);
    }

    long long sum(ll l, ll r) const{
        return (sum(r) - sum(l-1));
    }

    void add(ll i, long long value){
        m_bit0.add(i,value);
    }

    void add(ll l, ll r, long long value){
        m_bit0.add(l ,(-value*(l-1)));
        m_bit0.add((r+1),(value*r));
        m_bit1.add(l,value);
        m_bit1.add((r+1),-value);
    }

    private:

    BIT m_bit0;
    BIT m_bit1;

};


int main(){
    ll N;cin >> N;
    vector<vector<pair<ll,ll>>> weighted_gran(N);
    vector<vector<ll>> graph(N);
    vector<pair<pair<ll,ll>,ll>> edges(N-1);
    rep(i,N-1){
        ll u,v,w;cin >> u >> v >> w;
        u--;v--;
        edges[i] = make_pair(make_pair(u,v),w);
        graph[u].push_back(v);
        graph[v].push_back(u);
        weighted_gran[u].push_back(make_pair(v,w));
        weighted_gran[v].push_back(make_pair(u,w));
    }
    // 必要な情報計算
    LCA lca(graph);
    vector<ll> dis(N,INF);
    dis[0] = 0;
    vector<ll> first_visit(N,-1);
    vector<ll> finish(N,-1);
    vector<ll> first_leaf(N,-1);
    queue<int> que;
    first_visit[0] = 0;
    ll first_time = 0;
    ll finish_time = 0;
    dfs(0,weighted_gran,dis,first_visit,first_leaf,finish,first_time,finish_time,que);
    vector<ll> node2index(N,-1);
    rep(u,N){
        node2index[u] = N -1  - finish[u];
    }
    vector<ll> dis2(N+1);
    rep(u,N){
        dis2[node2index[u]] = dis[u]; 
    }
    BIT_RAQ raq(dis2);
    ll Q;cin >> Q;
    while (Q > 0){
        Q -- ;
        ll q;
        cin >> q;
        if (q == 1){
            ll edge_num,w;
            cin >> edge_num >> w;
            edge_num --;
            ll a,b,v;
            a = edges[edge_num].first.first;
            b = edges[edge_num].first.second;
            v = edges[edge_num].second;
            if (finish[b] < finish[a]){
                a = b;
            }
            ll c = first_leaf[a];
            ll index1 = node2index[a] + 1;
            ll index2 = node2index[c] + 1;
            raq.add(index1,index2,w - v);
            // cout << w - v << endl;
            edges[edge_num].second = w;
        }else{
            ll u,v; cin >>u >> v;
            u--;v--;
            ll w = lca.lca(u,v);
            // cout << u << " " << v << " " << w << endl;
            ll index1 = node2index[u] +1;
            ll index2 = node2index[v] +1;
            ll index3 = node2index[w] +1;
            ll a = raq.sum(index1,index1);
            ll b = raq.sum(index2,index2);
            ll c = raq.sum(index3,index3);
            cout << a + b - 2*c << endl;
        }
    }
}