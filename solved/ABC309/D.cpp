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
#define rep(i, x) for(ll i = 0; i < (x); i++)

using  vector2d = vector<vector<ll> >;

template <typename T>
void prll(vector<T> v){
    rep(i,v.size()){
        cout << v[i] << endl;
    }
    return;
}

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
    ll N1,N2,M;cin >> N1 >> N2 >> M;
    vector<vector<ll>> graph(N1+N2);
    rep(i,M){
        ll a,b;cin >>a >> b;
        a--;b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<ll> dis1 = bfs(0,graph);
    vector<ll> dis2 = bfs(N1+N2 -1 ,graph);
    ll max1 = 0;
    ll max2 = 0;
    rep(i,N1){
        max1 = max(max1,dis1[i]);
    }
    rep(i,N2){
        max2 = max(max2,dis2[i+N1]);
    }
    cout << max1 + max2 +1 << endl;
}