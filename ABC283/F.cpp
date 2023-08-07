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

using namespace std;
using ll = long long;


// 点変更、区間最小値, 0-indexed
// update a[i]
// RMQ [a,b)
template <typename T>
struct RMQ{
    const T INF = 1e+16;
    ll n;
    vector<T> dat;
    RMQ(ll n_):n(), dat(n_*4 ,INF){
        ll x = 1;
        while (n_>x){
            x*= 2;
        }
        n = x;
    }

    void update(ll i, T x){
        i += n-1;
        dat[i] = x;
        while (i>0){
            i = (i-1)/2;
            dat[i] = min(dat[2*i +1],dat[i*2+2]);
        }
    }

    T query(ll a, ll b){
        return query_sub(a,b,0,0,n);
    }

    T query_sub(ll a, ll b, ll k, ll l, ll r){
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

int main(){
    ll N;cin >> N;
    vector<ll> P(N);
    vector<ll> ordering_P(N);
    for (ll i=0;i<N;i++) {
        cin >> P[i];
        ordering_P[P[i]-1] = i;
    }
    RMQ<ll> low_low(N);
    RMQ<ll> low_high(N);
    RMQ<ll> high_low(N);
    RMQ<ll> high_high(N);
    for (ll i=0;i<N;i++){
        high_low.update(i,P[i] - i-1);
        high_high.update(i,P[i] + i + 1);
    }
    vector<ll> ans(N);
    for (ll i=0;i<N;i++){
        ll index = ordering_P[i];
        ll a,b,c,d;
        a = high_high.query(index + 1,N) - index -1 - i - 1;
        b = high_low.query(0,index) - i -1 + index + 1;
        c = low_low.query(0,index) + index +1 + i + 1;
        d = low_high.query(index+1, N) - index - 1 +i+ 1;
        ans[index] = min(a,min(b,min(c,d)));
        high_low.update(index, 1e+16);
        high_high.update(index, 1e+16);
        low_high.update(index, - i - 1 + index + 1);
        low_low.update(index, - i - 1 - index - 1);
    }
    for (ll i=0;i<N;i++){
        cout << ans[i] << " ";
    }
    cout << endl;

}