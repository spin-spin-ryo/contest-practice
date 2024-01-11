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

void dfs(ll u, vector<vector<ll>> &graph, vector<bool> &visited, vector<ll> &prev, vector<vector<ll>> &children){
    visited[u] = true;
    for (ll v:graph[u]){
        if (!visited[v]){
            prev[v] = u;
            dfs(v,graph,visited,prev,children);
        }
    }
    ll count_children = 1;

    rep(i,children[u].size()){
        count_children += children[u][i];
    }
    if (prev[u]!= -1){
        children[prev[u]].push_back(count_children);
    }

    return;
}


int main(){
    ll N;cin >> N;
    vector<vector<ll>> graph(N);
    rep(i,N-1){
        ll a,b; cin >> a >> b;
        a--;b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<ll> prev(N,-1);
    vector<bool> visited(N,false);
    vector<vector<ll>> children(N);
    dfs(0,graph,visited,prev,children);
    ll ans = N*(N-1)*(N-2)/6;
    rep(i,N){
        ll sum1 = 0;
        ll sum2 = 0;
        rep(j, children[i].size()){
            sum1 += children[i][j];
            sum2 += children[i][j]*children[i][j];
        }
        ll parent_size = N - 1 - sum1;
        sum2 += parent_size*parent_size;
        sum1 = N - 1;
        ans -= (sum1*sum1 - sum2)/2; 
    }
    cout << ans << endl;
}