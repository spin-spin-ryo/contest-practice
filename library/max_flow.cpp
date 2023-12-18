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
    int end;
    int cap = 0;
    
    edge() = default;
    
    edge(int e, int c){
        end = e;
        cap = c;
    }
};

edge make_edge(int end, int cap){
    edge e(end,cap);
    return e;
}


// graph[u] = {(v,w)} v:終点 w:容量
class max_flow{
    public:
    max_flow() = default;

    explicit max_flow(vector<vector<edge>> g){
        residual_graph.resize(g.size());
        N = g.size();
        rep(i,g.size()){
            rep(j,g[i].size()){
                edge e = g[i][j];
                edge e1(e.end,e.cap);
                edge e2(i,0);
                edge2index.insert(make_pair(make_pair(i,e.end),residual_graph[i].size()));
                edge2index.insert(make_pair(make_pair(e.end,i),residual_graph[e.end].size()));

                residual_graph[i].push_back(e1);
                residual_graph[e.end].push_back(e2);
            }
        }
    }

    bool find_flow(ll source, ll sink){
        ll flow_num = INF;
        stack<int> sta;
        vector<bool> visited(N,false);
        visited[source] = true;
        vector<int> prev(N,-1);
        sta.push(source);
        while(!sta.empty()){
            int u = sta.top();
            sta.pop();
            for (auto e:residual_graph[u]){
                if ( (!visited[e.end]) & (e.cap > 0)){
                    visited[e.end] = true;
                    flow_num = min(flow_num,(ll)e.cap);
                    sta.push(e.end);
                    prev[e.end] = u;
                    if (e.end = sink) break;
                }
            }
            
        }
        if (visited[sink]){
            update(source,sink,prev,flow_num);
            ans += flow_num;
            return true;
        }else{
            return false;
        }
    }
    
    void update(ll source, ll sink, vector<int> prev, ll flow){
        int v = sink;
        while(true){
            int u = prev[v];
            if (u==-1) break;
            int index = edge2index[make_pair(u,v)];
            int rindex = edge2index[make_pair(v,u)];
            residual_graph[u][index].cap -= flow;
            residual_graph[v][rindex].cap += flow;
            v = u;
        }
    }

    ll run(ll source, ll sink){
        while(true){
            bool flag = find_flow(source,sink);
            if (!flag){
                return ans;
            }
        }
        
    }

    
    private:
    int N;
    ll ans = 0;
    vector<vector<edge>> residual_graph;
    map<pair<ll,ll>,int> edge2index;
};


int main(){
    int n = 4;
    vector<vector<edge>> g(n);
    g[0].push_back(make_edge(1,4));
    g[0].push_back(make_edge(2,3));
    g[1].push_back(make_edge(2,2));
    g[1].push_back(make_edge(3,3));
    g[2].push_back(make_edge(3,2));
    max_flow solver(g);
    cout << solver.run(0,3) << endl;
    return 0;
}