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

using namespace std;
using ll = long long;
#define mod 998244353
using  vector2d = vector<vector<ll> >;
#define INF 1e+16

class UnionFind{
    vector<ll> parent;
    public:
    explicit UnionFind(size_t size):parent(size){
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
    }

    bool same(ll x, ll y){
        ll rx = root(x);
        ll ry = root(y);
        return rx==ry;
    }

};


int main(){
    ll N,M;cin >> N >> M;
    vector<ll> X(N);
    for (ll i=0;i<N;i++) cin >> X[i];
    vector<ll> Y(N);
    for (ll i=0;i<N;i++) cin >> Y[i];
    vector<ll> A(M);
    vector<ll> B(M);
    vector<ll> Z(M);
    for (ll i=0;i<M;i++) cin >> A[i] >> B[i] >> Z[i];

    //どちらも使わないとき
    UnionFind solver(N);
    vector<pair<ll,pair<ll,ll> > > edges;
    for (ll i=0;i<M;i++){
        edges.push_back(make_pair(Z[i],make_pair(A[i],B[i])));
    }
    sort(edges.begin(),edges.end());
    ll ans1=0,ans2= 0,ans3=0,ans4=0;
    
    ll count = 0;
    for (ll i=0;i<M;i++){
        ll u = edges[i].second.first;
        ll v = edges[i].second.second;
        ll z = edges[i].first;
        u--;v--;
        if (!solver.same(u,v)){
            solver.unite(u,v);
            ans1 += z; 
            count ++;
        }
    }
    if (count != N-1){
        ans1 = INF;
    }
    count = 0;
    edges.clear();

    //空港だけ
    UnionFind solver1(N+1);
    for (ll i=0;i<M;i++){
        edges.push_back(make_pair(Z[i],make_pair(A[i],B[i])));
    }
    for (ll i=0;i<N;i++){
        edges.push_back(make_pair(X[i],make_pair(i+1,N+1)));
    }
    sort(edges.begin(),edges.end());
    for (ll i=0;i<M+N;i++){
        ll u = edges[i].second.first;
        ll v = edges[i].second.second;
        ll z = edges[i].first;
        u--;v--;
        if (!solver1.same(u,v)){
            solver1.unite(u,v);
            ans2 += z; 
            count ++;
        }
    }
    if (count != N){
        ans2 = INF;
    }

    count = 0;
    edges.clear();
    //港だけ
    UnionFind solver2(N+1);
    for (ll i=0;i<M;i++){
        edges.push_back(make_pair(Z[i],make_pair(A[i],B[i])));
    }
    for (ll i=0;i<N;i++){
        edges.push_back(make_pair(Y[i],make_pair(i+1,N+1)));
    }
    sort(edges.begin(),edges.end());
    for (ll i=0;i<M+N;i++){
        ll u = edges[i].second.first;
        ll v = edges[i].second.second;
        ll z = edges[i].first;
        u--;v--;
        if (!solver2.same(u,v)){
            solver2.unite(u,v);
            ans3 += z; 
            count ++;
        }
    }
    if (count != N){
        ans3 = INF;
    }

    //どちらも
    count = 0;
    edges.clear();
    
    UnionFind solver3(N+2);
    for (ll i=0;i<M;i++){
        edges.push_back(make_pair(Z[i],make_pair(A[i],B[i])));
    }
    for (ll i=0;i<N;i++){
        edges.push_back(make_pair(Y[i],make_pair(i+1,N+1)));
        edges.push_back(make_pair(X[i],make_pair(i+1,N+2)));
    }
    sort(edges.begin(),edges.end());
    for (ll i=0;i<M+2*N;i++){
        ll u = edges[i].second.first;
        ll v = edges[i].second.second;
        ll z = edges[i].first;
        u--;v--;
        if (!solver3.same(u,v)){
            solver3.unite(u,v);
            ans4 += z; 
            count ++;
        }
    }
    if (count != N+1){
        ans4 = INF;
    }

    ll ans = min(ans1,ans2);
    ans = min(ans3,ans);
    ans = min(ans4,ans);
    cout << ans << endl;


}