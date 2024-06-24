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


vector<bool> visited(5010,false);

template <typename T>
void print(vector<T> v){
    rep(i,v.size()){
        cout << v[i] << endl;
    }
    return;
}


void dfs(int u, vector<vector<int>> &graph, vector<ll> &a, vector<ll> &w,
          vector<ll> &one_coma_max, vector<ll> &all_coma_max){
    visited[u] = true;
    vector<int> thisvisited;
    for (auto v:graph[u]){
        if (!visited[v]){
            thisvisited.push_back(v);
            dfs(v,graph,a,w,one_coma_max,all_coma_max);
        }
    }
    int l = graph[u].size();
    if (w[u] != INF){
        vector<vector<ll>> dp(l+1,vector<ll>(w[u],0));
        dp[0][0] = 1;
        for(int i=0;i<l;i++){

            int v = graph[u][i];
            for (int j=0;j<w[u];j++){
                if (j + w[v] < w[u]){
                    dp[i+1][j + w[v]] = max(dp[i+1][j + w[v]],dp[i][j] + one_coma_max[v]);
                }
                dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
            }
        }
        rep(j,w[u]){
            one_coma_max[u] = max(one_coma_max[u],dp[l][j]);
        }

    }
    for(int v:thisvisited){
        all_coma_max[u] += all_coma_max[v];
    }


    all_coma_max[u] += a[u] * one_coma_max[u];
    return;
}

int main(){
    int n,m; cin >> n >> m;
    vector<int> u(m),v(m);
    rep(i,m){
        cin >> u[i] >> v[i];
        u[i]--;v[i]--;
    }
    vector<ll> w(n+1);
    vector<ll> a(n+1,0);
    rep(i,n) cin >> w[i];
    rep(i,n) cin >> a[i];
    w[n] = INF;
    vector<vector<int>> graph(n+1);
    vector<int> parents_num(n,0);
    vector<ll> one_coma_max(n+1,1);
    vector<ll> all_coma_max(n+1,0);
    rep(i,m){
        if (w[u[i]] > w[v[i]]){
            graph[u[i]].push_back(v[i]);
            parents_num[v[i]]++;
        }else if (w[u[i]] < w[v[i]]){
            graph[v[i]].push_back(u[i]);
            parents_num[u[i]] ++;
        }
    }
    rep(i,n){
        if (parents_num[i] == 0){
            graph[n].push_back(i);
        }
    }
    dfs(n,graph,a,w,one_coma_max,all_coma_max);
    cout << all_coma_max[n] << endl;

    

}