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


int main(){
    cout << "Hello World" << endl;
    return 0;
}