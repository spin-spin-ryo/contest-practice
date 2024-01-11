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

bool dfs_stack(int start, vector<vector<int>> graph, vector<int> &prev, vector<bool> &visited){
    int N = graph.size();
    stack<int> sta;
    sta.push(start);
    visited[start] = true;
    while (!sta.empty()){
        int u = sta.top();
        sta.pop();
        for (auto v:graph[u]){
            if (!visited[v]){
                prev[v] = u;
                visited[v] = true;
                sta.push(v);
            }else{
                int b = u;
                vector<int> ans;
                while(prev[b] != v){
                    ans.push_back(b);
                    b = prev[b];
                }
                ans.push_back(b);
                ans.push_back(v);
                cout << ans.size() << endl;
                rep(i,ans.size()){
                    cout << ans[ans.size() - 1 -i] +1 << " ";
                }
                cout << endl;
                return true;
            }
        }
    }
    return false;
}


int main(){
    int N;cin >> N;
    vector<vector<int>> graph(N);
    rep(i,N){
        int a;
        cin >> a;
        a--;
        graph[i].push_back(a);
    }
    vector<int> prev(N,-1);
    vector<bool> visited(N,false);
    rep(i,N){
        if (!visited[i]){
             bool flag = dfs_stack(i,graph,prev,visited);
            if (flag) return 0;
        }
       
    }
}