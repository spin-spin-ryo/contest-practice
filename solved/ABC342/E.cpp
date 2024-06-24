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
#include <atcoder/lazysegtree>

using namespace std;
using ll = long long;
#define mod 998244353
#define INF 1e+19
#define rep(i, x) for(int i = 0; i < (x); ++i)


struct edge{
    public:
     int index;
     int to;
     edge() = default;
     edge(int v, int index){
        this-> to = v;
        this-> index = index;
     }
};


int main(){
    int n,m; cin >> n >> m;
    vector<ll> l(m),d(m),k(m),c(m),a(m),b(m);
    vector<vector<edge>> graph(n);
    rep(i,m){
        cin >> l[i] >> d[i] >> k[i] >> c[i] >> a[i] >> b[i];
        a[i]--;b[i]--;
        graph[b[i]].push_back(edge(a[i],i));
    }
    priority_queue<pair<ll,ll>> que;
    que.push({INF,n-1});
    vector<ll> dis(n,0);
    dis[n-1] = INF;
    while(!que.empty()){
        auto p = que.top();
        que.pop();
        ll now_time = p.first;
        int u = p.second;
        for (edge e:graph[u]){
            int index = e.index;
            int v = e.to;
            // 現在時刻から最も近い電車の到着時間を探す。
            ll K = min((now_time - l[index] - c[index])/d[index],k[index]-1);
            if (K >= 0){
                ll next_time = l[index] + K*d[index];
                if (next_time > dis[v]){
                    dis[v] = next_time;
                    que.push({next_time,v});
                }
            }
        }
    }
    rep(i,n-1){
        if (dis[i]!=0){
            cout << dis[i] << endl;
        }else{
            cout << "Unreachable" << endl;
        }
    }
    
}
