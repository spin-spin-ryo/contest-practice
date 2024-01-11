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

template <typename T>
void print(vector<T> v){
    rep(i,v.size()){
        cout << v[i] << endl;
    }
    return;
}


vector<int> bfs(int start,vector<vector<int>> graph, vector<int> &save){
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
                if (save[u]!= -1){
                    save[v] = max(save[v],save[u] -1);
                }
                visited[v]=true;
                que.push(v);
            }
        }
    }
    return dis;
}


int main(){
    int N,M;cin >> N >> M;
    vector<vector<int>> graph(N);
    rep(i,N-1){
        int p;cin >> p;
        p--;
        graph[p].push_back(i+1);
    }
    vector<int> save(N,-1);
    rep(i,M){
        int x,y;cin >> x >> y;
        x--;
        save[x] = max(y,save[x]);
    }
    bfs(0,graph,save);
    int ans = 0;
    rep(i,N){
        if (save[i] >=0) ans++;
    } 
    cout << ans << endl;
}