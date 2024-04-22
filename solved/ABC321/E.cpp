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

ll power(ll n, ll r){
    ll ans = 1;
    for (int i=0;(r>>i) >0 ;i++){
        if ((r>>i)&1){
            ans *= n;
        }
        n *= n;
    }
    return ans;
}

ll f(ll n, ll k, ll N){
    ll r = power(2,k);
    if (r == 0) return 0;
    return min(max(N- r*n,(ll)0),r );
}

int main(){
    ll T;
    cin >>  T;
    while (T>0){
        T --;
        ll N,X,K; cin >> N >> X >> K;
        ll ans = 0;
        ans += f(X,K,N);
        ll count = 0;
        // cout << ans << endl;
        while (X!=0){
            ll x= X/2;
            ll y = 0;
            if (2*x == X){
                y = 2*x+1;
            }else{
                y = 2*x;
            }
            count ++;
            if (y<=N & K-count -1 >=0 & y>0){
                // cout <<y << " " << K-count -1  << endl;
                ans += f(y,K-count -1,N);
            }
            if (count == K){
                ans ++;
            }
            X = x;
        }
        cout << ans << endl;
    }
}