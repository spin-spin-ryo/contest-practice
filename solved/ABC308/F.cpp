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
#define INF 10000000000
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
    ll N,M;cin >> N >> M;
    vector<ll> P(N);
    rep(i,N) cin >> P[i];
    vector<ll> L(M);
    vector<ll> D(M);
    rep(i,M) cin >> L[i];
    rep(i,M) cin >> D[i];
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> que;
    rep(i,N){
        que.push(make_pair(P[i],INF));
    }
    rep(i,M){
        que.push(make_pair(L[i],D[i]));
    }
    priority_queue<ll> discount;
    ll ans = 0;
    while (!que.empty()){
        auto p = que.top();
        que.pop();
        if (p.second == INF){
            ans += p.first;
            if (!discount.empty()){
                ans -= discount.top();
                discount.pop();
            }   
        }else{
            discount.push(p.second);
        }
    }
    cout << ans << endl;

}