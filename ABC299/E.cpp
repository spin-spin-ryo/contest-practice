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

vector<ll> bfs(ll start,vector<vector<ll>> graph){
    ll N = graph.size();
    vector<ll> dis(N,INF);
    vector<bool> visited(N,false);
    queue<ll> que;
    dis[start] = 0;
    visited[start] = true;
    que.push(start);
    while (!que.empty()){
        ll u = que.front();
        que.pop();
        for (ll v:graph[u]){
            if (!visited[v]){
                dis[v] = dis[u] + 1;
                visited[v]=true;
                que.push(v);
            }
        }
    }
    return dis;
}

int main(){
    ll N,M;cin >> N >> M;
    vector<vector<ll>> graph(N);
    rep(i,M){
        ll u,v;cin >> u >> v;
        u--;v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    ll K;cin >> K;
    vector<ll> p(K);
    vector<ll> d(K);
    rep(i,K){
        cin >> p[i] >> d[i];
        p[i]--;
    }
    vector<vector<ll>> dis(N);
    rep(i,N){
        dis[i] = bfs(i,graph);
    }
    vector<ll> ng(N,0);
    rep(k,K){
        rep(u,N){
            ll temp_d = dis[p[k]][u];
            if (temp_d < d[k]){
                ng[u] = 1;
            }
        }
    }
    vector<int> color(N,0);
    bool black_exist = false;
    rep(k,K){
        bool exist = false;
        rep(u,N){
            if (dis[p[k]][u] == d[k] & ng[u]==0){
                exist = true;
                black_exist = true;
                color[u] = 1;
            }
        }
        if (!exist){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    if (!black_exist){
        rep(i,N){
            if (ng[i]==0){
                color[i] = 1;
            }
        }
    }
    rep(i,N){
        cout << color[i];
    }
    cout << endl;

}