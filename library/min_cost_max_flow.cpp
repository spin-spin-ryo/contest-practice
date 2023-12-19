// ポテンシャル法
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

using  vector2d = vector<vector<int> >;

template <typename T>
void print(vector<T> v){
    rep(i,v.size()){
        cout << v[i] << endl;
    }
    return;
}

struct edge{
    public:
    int to;
    int cap = 0;
    int cost;
    
    edge() = default;
    
    edge(int e, int c,int _cost){
        to = e;
        cap = c;
        cost = _cost;
    }
};

edge make_edge(int to, int cap,int cost){
    edge e(to,cap,cost);
    return e;
}

struct min_cost_flow{
    public:


    min_cost_flow() = default;
    min_cost_flow(vector<vector<edge>> g){
        N = g.size();
        potential.resize(N,0);
        sup_graph.resize(N);
        rep(i,N){
            for (auto e:g[i]){
                int to = e.to;
                ll cost = e.cost;
                ll cap = e.cap;
                edge e1 = make_edge(to,cap,cost);
                edge e2 = make_edge(i,0,-cost);
                int index1 = sup_graph[i].size();
                int index2 = sup_graph[to].size();
                set_edge_index(i,to,index1);
                set_edge_index(to,i,index2);
                add_edge(i,e1);
                add_edge(to,e2);
            }
        }
    }

    void add_edge(int from, edge e){
        sup_graph[from].push_back(e);
    }

    void set_edge_index(int u, int v, int index){
        edge2index.insert(make_pair(make_pair(u,v),index));
    }

    int get_edge_index(int u, int v){
        return edge2index[make_pair(u,v)];
    }

    edge get_edge(int u,int v){
        int index = edge2index[make_pair(u,v)];
        return sup_graph[u][index];
    }

    bool find_flow(int start, int sink){
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> que;
        dis.resize(N,INF);
        prev.resize(N,-1);
        dis[start] = 0;
        que.push(make_pair(dis[start],start));
        while(!que.empty()){
            auto p = que.top();
            int d = p.first;
            int u = p.second;
            if (d > dis[u]) continue;
            for (auto e: sup_graph[u]){
                int v = e.to;
                ll cost = e.cost;
                ll cap = e.cap;
                cost = cost - potential[u] + potential[v];
                if (dis[v] > dis[u] + cost & cap > 0){
                    dis[v] = dis[u] + cost;
                    prev[v] = u;
                    que.push(make_pair(dis[v],v));
                }
            }
        }
        return (dis[sink] != INF);
    }

    void update(ll start, ll sink){
        int v = sink;
        ll flow = INF;
        while(true){
            potential[v] -= dis[v];
            int u = prev[v];
            if (u==-1) break;
            int index = get_edge_index(u,v);
            int rindex = get_edge_index(v,u);
            flow = min(flow,(ll)sup_graph[u][index].cap);
            v = u;
        }
        v = sink;
        while(true){
            int u = prev[v];
            if (u==-1) break;
            int index = get_edge_index(u,v);
            int rindex = get_edge_index(v,u);
            sup_graph[u][index].cap -= flow;
            sup_graph[v][rindex].cap += flow;
            v = u;
        }
        ans += flow;
    }

    ll run(ll source, ll sink){
        while(true){
            bool flag = find_flow(source,sink);
            if (flag){
                update(source,sink);
            }else{
                return ans;
            }
        }
        
    }

    private:
    int N;
    ll ans = 0;
    vector<vector<edge>> sup_graph;
    vector<ll> potential;
    map<pair<ll,ll>,ll> edge2index;
    vector<ll> dis;
    vector<ll> prev;
        

}

