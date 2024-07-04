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
#include <unordered_map>

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

void dfs(int u, vector<vector<int>> &graph, vector<ll> &dis,vector<bool> &visited, vector<ll> &c,vector<vector<int>> &tree_graph,vector<ll> &sum_C){
    visited[u] = true;
    ll sum_c = 0;
    for(int v:graph[u]){
        if (!visited[v]){
            dis[v] = dis[u] + 1;
            tree_graph[u].push_back(v);
            dfs(v,graph,dis,visited,c,tree_graph,sum_C);
            sum_c += sum_C[v];
        }
    }
    sum_c += c[u];
    sum_C[u] = sum_c;
}

void dfs2(int u,vector<vector<int>> &tree_graph,vector<ll> &ans,vector<ll> &sum_C, ll &sum_c){
    for (int v:tree_graph[u]){
        ans[v] = ans[u] - 2*sum_C[v] + sum_c; 
        dfs2(v,tree_graph,ans,sum_C,sum_c);
    }
}

int main(){
    int n; cin >> n;
    vector<vector<int>> graph(n);
    rep(i,n-1){
        int a,b; cin >> a >> b;
        a--;b--;
        graph[a].push_back(b);
        graph[b].push_back(a);

    }
    ll sum_c = 0;
    vector<ll> c(n);
    rep(i,n){
        cin >> c[i];
        sum_c += c[i];
    }
    vector<ll> dis(n,0);
    vector<vector<int>> tree_graph(n);
    vector<ll> sum_C(n,0);
    vector<bool> visited(n,false);
    dfs(0,graph,dis,visited,c,tree_graph,sum_C);
    ll now_ans = 0;
    vector<ll> ans(n,0);
    rep(i,n){
        now_ans += c[i]*dis[i];
    }
    ans[0] = now_ans;
    dfs2(0,tree_graph,ans,sum_C,sum_c);
    ll min_ans = ans[0];
    rep(i,n){
        min_ans = min(min_ans,ans[i]);
    }
    cout << min_ans << endl;

}