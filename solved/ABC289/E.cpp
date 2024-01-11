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

using  vector2d = vector<vector<int> >;


int dfs(int start1,int start2,int end1,int end2,vector<vector<int>> graph,vector<int> C){
    int N = graph.size();
    vector<vector<int>> dis(N,vector<int>(N,INF));
    vector<vector<bool>> visited(N,vector<bool>(N,false));
    queue<pair<int,int>> que;
    dis[start1][start2] = 0;
    visited[start1][start2] = true;
    que.push(make_pair(start1,start2));
    while (!que.empty()){
        pair<int,int> p = que.front();
        que.pop();
        int u1,u2;
        u1 = p.first;
        u2 = p.second;
        for (int v1:graph[u1]){
            for (int v2:graph[u2]){
                if (C[v1] != C[v2]){
                    if (!visited[v1][v2]){
                        dis[v1][v2] = dis[u1][u2] + 1;
                        visited[v1][v2] = true;
                        que.push(make_pair(v1,v2));
                    }
                }
            }
        }
    }
    return (visited[end1][end2]?dis[end1][end2]:-1);
};


int main(){
    int T;cin >> T;
    while(T>0){
        T--;
        int N,M;cin >> N >> M;
        vector<int> C(N);
        rep(i,N) cin >> C[i];
        vector<vector<int>> graph(N);
        int u,v;
        rep(i,M){
            cin >> u >> v;
            u--;v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        cout << dfs(0,N-1,N-1,0,graph,C) << endl;

    }
    return 0;
}