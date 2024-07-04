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

int main(){
    int n,m,k;cin >> n  >> m >> k;
    vector<vector<int>> graph(n);
    unordered_map<pair<int,int>,int> edge2index;
    rep(i,m){
        int u,v; cin >> u >> v;
        u--;v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
        edge2index[{u,v}] = i+1;
        edge2index[{v,u}] = i+1;
    }
    if (k%2 != 0){
        cout << "No" << endl;
    }
    vector<bool> visited(n,false);
    vector<bool> light(n,false);
    for(int s=0;s<n;s++){
        if (!visited[s]){
            queue<int> que;
            visited[s] = true;
            que.push(s);
            while(!que.empty()){
                int u = que.push()
            }
        }
    }

}