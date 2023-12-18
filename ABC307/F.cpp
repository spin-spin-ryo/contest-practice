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

template <typename T>
struct RMQ{
    const T INF = numeric_limits<T>::max();
    int n;
    vector<T> dat;
    RMQ(int n_):n(), dat(n_*4 ,INF){
        int x = 1;
        while (n_>x){
            x*= 2;
        }
        n = x;
    }

    void update(int i, T x){
        i += n-1;
        dat[i] = x;
        while (i>0){
            i = (i-1)/2;
            dat[i] = min(dat[2*i +1],dat[i*2+2]);
        }
    }

    T query(int a, int b){
        return query_sub(a,b,0,0,n);
    }

    T query_sub(int a, int b, int k, int l, int r){
        if (r <= a || b <= l){
            return INF;
        }else{
            if (a <= l && r <= b){
                return dat[k];
            }
        }
        T vl = query_sub(a,b,k*2 +1 ,l, (l+r)/2);
        T vr = query_sub(a,b,k*2+2,(l+r)/2,r);
        return min(vl,vr);
    }

};

int interval_binary_search(RMQ<ll> solver, ll upper, ll l, ll r){
    // A[l],...A[r-1] の中で upper以下の最小のindexを返す.
    if (solver.query(l,r) > upper) return -1;
    while(r - l >1){
        ll m = (r+l)/2;
        if (solver.query(l,m) <= upper){
            r = m;
        }else{
            l = m;
        }
    }
    return l;
}


int main(){
    ll N,M; cin >> N >> M;
    vector<vector<edge>> graph(N);
    vector<ll> dis(N,INF);
    vector<ll> prev(N,-1);
    priority_queue<pair<ll,ll>> que;
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
    rep(i,D) cin >> X[i];
    RMQ<ll> solver(D);
    rep(i,D){
        solver.update(i,-X[i]);
    }
    vector<ll> res(N,0);
    while(!que.empty()){
        auto p = que.top();
        que.pop();
        int u = p.second;
        for (auto e:graph[u]){
            int v = e.v;
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
                    ll index = interval_binary_search(solver,day[u],N);
                    if (day[v]>index + 1){
                        day[v] = index+1;
                        res[v] = X[index] - e.cost;
                    }
                }
            }
        }
    }

}