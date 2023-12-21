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
    multiset<pair<ll,ll>> c;
    vector<ll> L(M);
    vector<ll> D(M);
    rep(i,M) cin >> L[i];
    rep(i,M) cin >> D[i];
    rep(i,M){
        c.insert(make_pair(L[i],D[i]));
    }

    sort(P.begin(),P.end());
    ll ans = 0;
    rep(i,N){
        auto itr = c.upper_bound(make_pair(P[i],(ll)INF));
        if (itr != c.begin()){
            itr -- ;
            ll d = (*itr).second;
            ans += P[i] - d;
            c.erase(itr);
        }else{
            ans += P[i];
        }
    }
    cout << ans << endl;
}