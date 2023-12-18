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

void dfs(int now_node,vector<vector<int>> &graph,vector<int> &prev,vector<bool> &visited, bool output, int &goal,bool &finish_flag){
    if (finish_flag) return;
    visited[now_node] = true;
    if (now_node == goal){
        cout << now_node << endl;
        string ok; cin >> ok;
        finish_flag = true;
        return;
    }
    if (output){
        cout << now_node << endl;
        int k; cin >> k;
        if (k==-1){
            finish_flag = true;
            return;
        }
        rep(i,k){
            int a;cin >> a;
            graph[now_node].push_back(a);
        }
    }

    for (auto next_node:graph[now_node]){
        if (!visited[next_node]){
            prev[next_node] = now_node;
            dfs(next_node,graph,prev,visited,true,goal,finish_flag);
        }
    }

    if (finish_flag) return;
    cout << prev[now_node] << endl;
    int k;cin >> k;
    rep(i,k){
        int a;cin >> a;
    }
    return;
}

int main(){
    int N,M;cin >> N >> M;
    int k;cin >> k;
    
    vector<vector<int>> graph(N+1);
    vector<int> prev(N+1,-1);
    vector<bool> visited(N+1,false);
    rep(i,k){
        int a;cin >> a;
        graph[1].push_back(a);
    }
    bool finish_flag = false;
    dfs(1,graph,prev,visited,false,N,finish_flag);
}