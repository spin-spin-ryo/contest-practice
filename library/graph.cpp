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


vector<int> bfs(int start,vector<vector<int>> graph){
    int N = graph.size();
    vector<int> dis(N,INF);
    vector<bool> visited(N,false);
    queue<int> que;
    dis[start] = 0;
    visited[start] = true;
    que.push(start);
    while (!que.empty()){
        int u = que.front();
        que.pop();
        for (int v:graph[u]){
            if (!visited[v]){
                dis[v] = dis[u] + 1;
                visited[v]=true;
                que.push(v);
            }
        }
    }
    return dis;
}

void dfs(int u, vector<vector<int>> &graph, vector<int> &first_visit, vector<int> &finish,int &time){
    for (int v:graph[u]){
        if (first_visit[v]==-1){
            first_visit[v] = time;
            time++;
            dfs(v,graph,first_visit,finish,time);
        }
    }
    finish[u]=time;
    time++;
    return;
}

struct edge{
    public:
    ll v;
    ll cost;

    edge() = default;
    explicit edge(ll _v, ll c){
        v = _v;
        cost = c;
    }
};

edge make_edge(ll v, ll cost){
    edge e(v,cost);
    return e;
}

vector<ll> dijkstra(ll start, vector<vector<edge>> graph){
    int N = graph.size();
    vector<ll> dis(N,INF);
    vector<ll> prev(N,-1);
    priority_queue<pair<ll,ll>> que;
    prev[start] = start;
    dis[start] = 0;
    que.push(make_pair(dis[start],start));
    while(!que.empty()){
        auto p = que.top();
        int u = p.second;
        for (auto e: graph[u]){
            int v = e.v;
            if (dis[v] > dis[u] + e.cost){
                dis[v] = dis[u] + e.cost;
                prev[v] = u;
                que.push(make_pair(dis[v],v));
            }
        }
    }
    return dis;
}




int main(){
    cout << "Hello World" << endl;
    return 0;
}