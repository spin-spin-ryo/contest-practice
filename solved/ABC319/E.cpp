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

int main(){
    ll N,X,Y; cin >> N >> X >> Y;
    ll n = 3*5*8*7;
    vector<ll> times(n);
    vector<ll> P(N-1);
    vector<ll> T(N-1);
    rep(i,N-1){
        cin >> P[i] >> T[i];
    }
    for(ll s = 0;s<n;s++){
        ll now = s;
        rep(i,N-1){
            if (now % P[i] != 0){
                now += P[i] - now%P[i];
            }
            now += T[i];
        }
        times[s] = now;
        // cout << times[s] << endl;
    }
    ll Q; cin >> Q;
    while(Q>0){
        Q--;
        ll q; cin >> q;
        // cout <<q << " " << X << endl;
        cout << q + X -(q+X)%n + times[(q+X)%n] + Y << endl;
    }
}