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
#include <atcoder/scc>

using namespace std;
using ll = long long;
#define mod 998244353
#define INF 1e+16
#define rep(i, x) for(ll i = 0; i < (x); i++)

using  vector2d = vector<vector<ll> >;


class UnionFind{
    vector<ll> parent;


    public:
    vector<ll> connection_size;
    explicit UnionFind(size_t size):parent(size){
        connection_size.resize(size,1);
        for (ll i=0;i<size;i++) parent[i] = i;
    }

    ll root(ll x){
        if (parent[x] == x) return x;
        return parent[x] = root(parent[x]);
    }

    void unite(ll x,ll y){
        ll rx = root(x);
        ll ry = root(y);
        if (rx == ry) return;
        parent[rx] = ry;
        connection_size[ry] += connection_size[rx];
        connection_size[rx] = 0;
    }

    bool same(ll x, ll y){
        ll rx = root(x);
        ll ry = root(y);
        return rx==ry;
    }

    ll get_size(ll x){
        ll rx = root(x);
        return connection_size[rx];
    }

};

ll main(){
    ll n,m; cin >> n >> m;
    vector<ll> u(m),v(m),w(m);
    atcoder::scc_graph g(n);
    vector<vector<ll>> dp(1<<n,vector<ll>(n+1,INF));
    dp[0][0] = 0;
    vector<vector<ll>> dis(n,vector<ll>(n,INF));
    
    rep(i,m){
        cin >> u[i] >> v[i] >> w[i];
        u[i]--;v[i]--;
        g.add_edge(u[i],v[i]);
        dis[u[i]][v[i]] = w[i];
    }
    auto scc = g.scc();
    vector<ll> node2scc(n,-1);
    rep(i,scc.size()){
        rep(j,scc[i].size()){
            node2scc[scc[i][j]] = i;
        }
    }
    
    vector<vector<pair<ll,ll>>> edges(scc.size());
    rep(i,m){
        if (node2scc[u[i]] == node2scc[v[i]]){
            continue;
        }else if(node2scc[u[i]] + 1 == node2scc[v[i]]){
            edges[node2scc[u[i]]].push_back(make_pair(u[i],v[i]));
        }else{
            cout << "No" << endl;
            return 0;
        }
    }

    // あとはBIT DP明日の私に任せた
    ll visited = 0;
    rep(i,scc.size()){
        // distanceを計算する
        vector<int> nodes = scc[i];
        if (i==0){
            for (ll a:nodes){
                dp[1<<a][a] = 0;
            }
        }else{
            for (auto e:edges[i-1]){
                ll a = e.first;
                ll b = e.second;
                dp[visited + 1L << b][b] = min(dp[visited][a] + dis[a][b],dp[visited + 1L << b][b]);
            }
        }
        ll next_visit = 0;
        for (ll a:nodes){
            next_visit += 1L << a;
            for(ll b:nodes){
                for(ll c:nodes){
                    if (dis[b][c] > dis[b][a] + dis[a][c]){
                        dis[b][c] = dis[b][a] + dis[a][c];
                    }
                }
            }
        }

        vector<ll> subsets;
        for (ll subset = next_visit; subset > 0; subset = (subset - 1L) & next_visit) {
            subsets.push_back(subset);
        }
        reverse(subsets.begin(),subsets.end());
        // tourする
        for (ll subset:subsets){
            for (ll a:nodes){
                for (ll b:nodes){
                    if ((subset >> b & 1)){
                        continue;
                    }
                    dp[visited + subset + (1L<<b)][b] = min(dp[visited + subset + (1L<<b)][b], dp[visited + subset][a] + dis[a][b]);
                }
            }
        }
        visited += next_visit;
    }
    ll ans = INF;
    rep(i,n){
        ans = min(ans,dp[(1L<< n) -1][i]);
    }
    if (ans == INF){
        cout << "No" << endl;
    }else{
        cout << ans << endl;
    }
}