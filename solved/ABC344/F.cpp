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

int main(){
    ll n; cin >> n;
    vector<vector<ll>> p(n,vector<ll> (n,0));
    vector<vector<ll>> r(n,vector<ll> (n-1,0));
    vector<vector<ll>> d(n-1,vector<ll>(n,0));
    vector<ll> P;
    rep(i,n){
        rep(j,n){
            cin >> p[i][j];
            P.push_back(p[i][j]);
        }
    }
    sort(P.begin(),P.end());
    P.erase(unique(P.begin(),P.end()),P.end());
    map<ll,ll> PtoIndex;
    rep(i,P.size()){
        PtoIndex[P[i]] = i;
    }
    
    rep(i,n){
        rep(j,n-1){
            cin >> r[i][j];
        }
    }
    rep(i,n-1){
        rep(j,n){
            cin >> d[i][j];
        }
    }

    vector<vector<vector<ll>>> dis(n,vector<vector<ll>>(n,vector<ll>(P.size(),INF)));
    dis[0][0][PtoIndex[p[0][0]]] = 0;


    // {行動回数、所持金、今までの経路で一番所持金を増やせるところ、現在の点}
    priority_queue<tuple<ll,ll,ll,ll>,vector<tuple<ll,ll,ll,ll>>,greater<tuple<ll,ll,ll,ll>>> que;
    que.push({0,0,p[0][0],0});
    while(!que.empty()){
        tuple<ll,ll,ll,ll> t = que.top();que.pop();
        ll now_ans = get<0>(t);
        ll now_money = get<1>(t);
        ll max_price = get<2>(t);
        ll poll = get<3>(t);
        ll x = poll/n;
        ll y = poll%n;
        if (y<n-1){
            ll ans = now_ans;
            ll money = now_money;
            if (money < r[x][y]){
                ll k = (r[x][y] - money + max_price -1)/max_price;
                ans += k;
                money += max_price*k;
            }
            money -= r[x][y];
            ans ++;
            if (dis[x][y+1][PtoIndex[(max_price,p[x][y+1])]] >= ans){
                dis[x][y+1][PtoIndex[(max_price,p[x][y+1])]] = ans;
                que.push({ans,money,max(max_price,p[x][y+1]),x*n + y+1});
            }
        }
        if (x < n-1){
            ll ans = now_ans;
            ll money = now_money;
            if (money < d[x][y]){
                ll k = (d[x][y] - money + max_price -1)/max_price;
                ans += k;
                money += max_price*k;
            }
            money -= d[x][y];
            ans ++;
            if (dis[x+1][y][PtoIndex[(max_price,p[x+1][y])]] >= ans){
                dis[x+1][y][PtoIndex[(max_price,p[x+1][y])]] = ans;
                que.push({ans,money,max(max_price,p[x+1][y]),(x+1)*n + y});
            }
        }
    }
    ll ans = INF;
    
    rep(k,P.size()){
        ans = min(ans,dis[n-1][n-1][k]);
    }
    cout << ans << endl;
    
}