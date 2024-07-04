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
#include <unordered_map>

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
int main(){
    ll n,k; cin >> n >> k;
    ll ans = k*(k+1)/2;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    unordered_map<ll,int> counter;
    rep(i,n){
        auto itr =counter.find(a[i]); 
        if (itr != counter.end()){
            continue;
        }else{
            counter[a[i]] = 1;
            if (a[i] <= k) ans -= a[i];
        }
    }
    cout << ans << endl;
}