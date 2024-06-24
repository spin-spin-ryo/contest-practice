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
    ll n,t; cin >> n >> t;
    vector<ll> a(t),b(t);
    ll ans = 1;
    map<ll,ll> count;
    count[0] = n;
    vector<ll> scores(n,0);
    rep(i,t){
        cin >> a[i] >> b[i];
        a[i]--;
        count[scores[a[i]]]--;
        if (count[scores[a[i]]] == 0){
            ans --;
        }
        scores[a[i]] += b[i];
        auto itr = count.find(scores[a[i]]);
        if (itr != count.end()){
            count[scores[a[i]]] ++;
            if (count[scores[a[i]]] == 1){
                ans ++;
            }
        }else{
            count[scores[a[i]]] = 1;
            ans ++;
        }
        cout << ans << endl;
    }
}