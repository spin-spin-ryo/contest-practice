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
    vector<string> S(N);
    rep(i,N) cin >> S[i];
    vector<vector<ll>> graph1(N);
    vector<vector<ll>> graph2(N);    
    rep(i,N){
        rep(j,M){
            if (S[i][j] == '1'){
                graph1[i].push_back(i+j+1);
                graph2[i+j+1].push_back(i);
            }
        }
    }
    vector<ll> dis1 = bfs(0,graph1);
    vector<ll> dis2 = bfs(N-1,graph2);
    rep(k,N-2){
        ll s = INF;
        for (ll m1 = -1;m1>-M;m1--){
            for (ll m2 = 1;m2<M+1;m2++){
                if (m1+m2 > 0 & k+1+m1 >= 0 & k+1+m1 <N & k+1+m1+m2 < N){
                    if (S[k+1+m1][m2-1] == '1'){
                        s = min(s,dis1[k+1+m1] + 1 + dis2[k+1+m1+m2]);
                    } 
                }
            }
        }
        cout << (s>=INF?-1:s) << " ";
    }
    cout << endl;
    return 0;
}