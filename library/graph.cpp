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



void dfs_stack(int start, vector<vector<int>> graph, vector<int> &prev){
    int N = graph.size();
    vector<bool> visited(N,false);
    stack<int> sta;
    sta.push(start);
    visited[start] = true;
    while (!sta.empty()){
        int u = sta.top();
        sta.pop();
        for (auto v:graph[u]){
            if (!visited[v]){
                prev[v] = u;
                visited[v] = true;
                sta.push(v);
            }
        }
    }
    return;
}

template<typename T>
struct edge{
    public:
    T v;
    ll cost;

    edge() = default;
    explicit edge(T _v, ll c){
        v = _v;
        cost = c;
    }
};

template<typename T>
edge<T> make_edge(T v, ll cost){
    edge<T> e(v,cost);
    return e;
}

template<typename T>
unordered_map<T,ll> dijkstra(T start, unordered_map<T,vector<edge<T>>> graph){
    int N = graph.size();
    unordered_map<T,ll> dis;
    unordered_map<T,ll> prev;
    auto itr = graph.begin();
    while (itr != graph.end()){
        auto key = (*itr).first;
        dis[key] = INF;
        prev[key] = -1;
    }    
    
    priority_queue<pair<ll,T>,vector<pair<ll,T>>,greater<pair<ll,T>>> que;
    prev[start] = start;
    dis[start] = 0;
    que.push(make_pair(dis[start],start));
    while(!que.empty()){
        auto p = que.top();
        que.pop();
        int d = p.first;
        T u = p.second;
        if (d > dis[u]) continue;
        for (auto e: graph[u]){
            T v = e.v;
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