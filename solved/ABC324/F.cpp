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
using ld = long double;
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

template <typename T>
T dijkstra(ll start, ll end, vector<vector<pair<ll,T>>> graph){
    ll N = graph.size();
    vector<T> dis(N,INF);
    dis[start] = 0;
    rep(i,N){
        for (auto p:graph[i]){
            ll u = p.first;
            dis[u] = min(dis[u],dis[i] + p.second);
        }
    }
    return dis[end];
};

int main(){
    ll N,M; cin >> N >> M;
    vector<ll> u(M),v(M);
    vector<ld> b(M),c(M);
    vector<vector<pair<ll,ld>>> graph(N);
    rep(i,M){
        cin >> u[i] >> v[i] >> b[i] >> c[i];
        u[i]--;v[i]--;
    }
    ld l = 0;
    ld r = 10e+10;
    while (r-l > 1e-12){
        vector<vector<pair<ll,ld>>> graph(N);
        ld t = (r+l)/2;
        rep(i,M){
            graph[u[i]].push_back(make_pair(v[i],t*c[i] - b[i]));
        }
        ld now = dijkstra(0,N-1,graph);
        if (now >0){
            r = t;
        }
        if (now < 0){
            l = t;
        }
        if (now == 0){
            break;
        }
    }
    ld t = (r+l)/2 ;
    cout << setprecision(16) << t << endl;
    return 0;
}