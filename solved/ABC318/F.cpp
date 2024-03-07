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
                    if (e.end == sink) break;
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


int bipartite_matching(vector<vector<int>> pairs,int n, int m){
    // 1~n と1~mのマッチング
    vector<vector<edge>> graph(n+m+2);
    rep(i,n+m+1){
        if (i==0){
            rep(j,n){
                graph[i].push_back(make_edge(j+1,1));
            }
        }else{
            if (i > n){
                graph[i].push_back(make_edge(n+m+1,1));
            }else{
                for (auto v:pairs[i-1]){
                    graph[i].push_back(make_edge(v+n+1,1));
                }
            }
            
        }
    }

    max_flow solver(graph);
    return solver.run(0,n+m+1);
}



struct compressed_vector{
    public:
    map<ll,ll> org2com;
    vector<ll> com2org;
    vector<ll> original;
    vector<ll> compressed;

    compressed_vector() = default;

    explicit compressed_vector(vector<ll> _v){
        original.resize(_v.size());
        copy(_v.begin(), _v.end(), original.begin());
        com2org = _v;
        sort(com2org.begin(), com2org.end());
        com2org.erase(unique(com2org.begin(), com2org.end()), com2org.end());
        rep(i,com2org.size()){
            org2com[com2org[i]] = i;
        }
        rep(i,original.size()){
            compressed.push_back(org2com[original[i]]);
        }
    }

    ll& operator[](size_t index){
        return compressed[index];
    }
};
     

int main(){
    ll N; cin >> N;
    vector<ll> X(N);
    vector<ll> L(N);
    rep(i,N) cin >> X[i];
    rep(i,N) cin >> L[i];
    vector<ll> v;
    rep(i,N){
        rep(j,N){
            v.push_back(X[i] - L[j]);
            v.push_back(X[i] + L[j] + 1);
        }
    }
    compressed_vector com(v);
    vector<vector<vector<ll>>> sum_v(com.com2org.size(),vector<vector<ll>> (N,vector<ll>(N,0)));
    rep(i,N){
        rep(j,N){
            ll l = com.org2com[X[i] - L[j]];
            ll r = com.org2com[X[i] + L[j] + 1];
            sum_v[l][i][j] ++;
            sum_v[r][i][j] --;
        }
    }
    rep(i,com.com2org.size()-1){
        rep(j,N){
            rep(k,N){
                sum_v[i+1][j][k] += sum_v[i][j][k];
            }
        }
    }
    ll ans = 0;
    
    rep(i,com.com2org.size() - 1){
        vector<vector<int>> pairs(N);
        rep(j,N){
            rep(k,N){
                if (sum_v[i][j][k] == 1){
                    pairs[j].push_back(k);
                }
            }
        }
    
        // if (bipartite_matching(pairs,N,N) == N){
        //     // cout << com.com2org[i+1] << " " << com.com2org[i] << endl;
        //     ans += com.com2org[i+1]  - com.com2org[i];
        // }
    }
    cout << ans << endl;


}