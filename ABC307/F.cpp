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
#define rep(i, x) for(ll i = 0; i < (x); i++)

using  vector2d = vector<vector<ll> >;

template <typename T>
void prll(vector<T> v){
    rep(i,v.size()){
        cout << v[i] << endl;
    }
    return;
}

struct edge{
    public:
    ll v;
    ll cost;

    edge() = default;
    explicit edge(ll _v, ll c){
        v = _v;
        cost = c;
    }
};

edge make_edge(ll v, ll cost){
    edge e(v,cost);
    return e;
}


template<typename T>
struct SparseTable{
    vector<vector<T> >st;
    vector<int> lookup;

    SparseTable(const vector<T> &v){
        int b = 0;
        while ((1<<b) <= v.size()) ++b;
        st.assign(b,vector<T>(1<<b));
        for (int i=0;i<v.size();i++){
            st[0][i] = v[i];
        }

        for (int i=1;i<b;i++){
            for (int j=0;j+(1 << i) <= (1<<b);j++){
                st[i][j] = min(st[i-1][j],st[i-1][j + (1 << (i-1))]);
            }
        }
        lookup.resize(v.size() + 1);

        for (int i=2;i < lookup.size();i++){
            lookup[i] = lookup[i >> 1] + 1;
        }
    }
    // [l,r)
    inline T rmq(int l, int r){
        int b = lookup[r-l];
        return min(st[b][l],st[b][r - (1<<b)]);
    }
};


ll interval_binary_search(SparseTable<ll> &solver, ll upper, ll l, ll r){
    // A[l],...A[r-1] の中で upper以下の最小のindexを返す.
    if (r-l == 0) return -1;
    if (solver.rmq(l,r) > upper) return -1;
    while(r - l >1){
        ll m = (r+l)/2;
        if (solver.rmq(l,m) <= upper){
            r = m;
        }else{
            l = m;
        }
    }
    return l;
}


int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll N,M; cin >> N >> M;
    vector<vector<edge>> graph(N);
    vector<ll> dis(N,INF);
    vector<ll> prev(N,-1);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> que;
    rep(i,M){
        ll u,v,w;cin >> u >> v >> w;
        u--;v--;
        graph[u].push_back(make_edge(v,w));
        graph[v].push_back(make_edge(u,w));
    }
    ll K;cin >> K;
    vector<ll> A(K);
    vector<ll> day(N,INF);
    rep(i,K){
        cin >> A[i];
        A[i] --;
        dis[A[i]] = 0;
        prev[A[i]] = A[i];
        que.push(make_pair(dis[A[i]],A[i]));
        day[A[i]] = 0;
    }
    ll D;cin >> D;
    vector<ll> X(D);
    vector<ll> Y(D);
    rep(i,D){
        cin >> X[i];
        Y[i]= -X[i];
    }
    SparseTable<ll> solver(Y);
    vector<ll> res(N,0);
    while(!que.empty()){
        auto p = que.top();
        que.pop();
        ll u = p.second;
        ll d = p.first;
        if (d > dis[u]) continue;
        for (auto e:graph[u]){
            ll v = e.v;
            if (dis[v] > dis[u] + e.cost){
                dis[v] = dis[u] + e.cost;
                prev[v] = u;
                que.push(make_pair(dis[v],v));
                if (day[u] < INF){
                    ll l = res[u];
                    if (l >= e.cost){
                        day[v] = day[u];
                        res[v] = l - e.cost;
                    }
                    ll index = interval_binary_search(solver,-e.cost,day[u],D);
                    if (day[v]>index + 1 & index != -1){
                        day[v] = index+1;
                        res[v] = X[index] - e.cost;
                    }
                }
            }
            if (dis[v]==dis[u]+e.cost){
                bool flag = false;
                if (day[u] < INF){
                    ll l = res[u];
                    if (l >= e.cost){
                        day[v] = day[u];
                        res[v] = l - e.cost;
                        flag = true;
                    }
                    ll index = interval_binary_search(solver,-e.cost,day[u],D);
                    if (day[v]>index + 1 & index != -1){
                        day[v] = index+1;
                        res[v] = X[index] - e.cost;
                        flag = true;
                    }
                }
                if (flag){
                    que.push(make_pair(dis[v],v));
                }
            }
        }
    }
    rep(i,N){
        if (day[i] == INF){
            cout << -1 << endl;
        }else{
            cout << day[i] << endl;
        }    
    }

}