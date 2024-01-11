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
        ll u,v;
        cin >> u >> v;
        u--;v--;
        graph[u].push_back(v);
    }
    ll ans = 0;
    for (ll i=0;i<N;i++){
        vector<ll> dis = bfs(i,graph);
        rep(j,N){
            if (dis[j]>=2 & dis[j] != INF){
                // cout << dis[j] << endl;
                ans++;
            }
        }
    }
    cout << ans << endl;
    
}