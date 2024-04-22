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


vector<ll> dijkstra(ll start, vector<vector<pair<ll,ll>>> graph){
    ll N = graph.size();
    vector<ll> dis(N,INF);
    vector<ll> prev(N,-1);
    priority_queue<pair<ll,ll>> que;
    dis[start] = 0;
    prev[start] = start;
    que.push(make_pair(dis[start],start));
    while (!que.empty()){
        auto p = que.top();
        que.pop();
        ll u = p.second;
        for (auto e: graph[u]){
            ll v = e.first;
            ll w = e.second;
            if (dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                prev[v] = u;
                que.push(make_pair(dis[v],v));
            }
        }
    }
    return dis;
};

template <typename T>
vector<T> dijkstra(ll start, vector<vector<pair<ll,T>>> graph){
    ll N = graph.size();
    vector<T> dis(N,INF);
    vector<ll> prev(N,-1);
    priority_queue<pair<T,ll>> que;
    dis[start] = 0;
    prev[start] = start;
    que.push(make_pair(dis[start],start));
    while (!que.empty()){
        auto p = que.top();
        que.pop();
        ll u = p.second;
        for (auto e: graph[u]){
            ll v = e.first;
            T w = e.second;
            if (dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                prev[v] = u;
                que.push(make_pair(dis[v],v));
            }
        }
    }
    return dis;
};
