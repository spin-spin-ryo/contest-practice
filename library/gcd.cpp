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

using namespace std;
using ll = long long;
#define mod 998244353
#define INF 1e+16
using  vector2d = vector<vector<int> >;

// 返り値: a と b の最大公約数
// ax + by = gcd(a, b) を満たす (x, y) が格納される
long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a%b, y, x);
    y -= a/b * x;
    return d;
}

ll gcd(ll a,ll b){
    if (a < b) return gcd(b,a);
    if (a%b == 0) return b;
    return gcd(b,a%b);
}

// ax-by = dとなる(x,y,d)を出力する
tuple<ll,ll,ll> ext_gcd(ll a,ll b){
    if (abs(a)< abs(b)){
        ll x,y,d;
        tuple<ll,ll,ll> t = ext_gcd(b,a);
        // b*x - a*y = d
        x = get<0>(t);
        y = get<1>(t);
        d = get<2>(t);
        return {y,x,-d};
    }
    if (b == 0){
        return {1,0,a};
    }
    ll r = a%b;
    if (r == 0){
        if (b == 1){
            return {1, a-1,1};
        }else if(b == -1){
            return {1,-a + 1,1};
        }else{
            ll d = gcd(a,b);
            tuple<ll,ll,ll> t = ext_gcd(a/d,b/d);
            ll x = get<0>(t);
            ll y = get<1>(t);
            return {d*x,d*y,d};
        }
    }
    if (b%r == 0){
        return {1,a/b,r};
    }else{
      ll x,y,d;
      tuple<ll,ll,ll> t =  ext_gcd(b,r);
      x = get<0>(t);
      y = get<1>(t);
      d = get<2>(t);
      return {-y, -(a/b)*y - x , d};
    }
}

ll lcm(ll a, ll b){
    return a*b/gcd(a,b);
}


int main(){
    ll a,b; cin >> a >> b;
    tuple<ll,ll,ll> t= ext_gcd(a,b);
    ll x = get<0>(t);
    ll y = get<1>(t);
    ll d = get<2>(t);
    if (d == 2 | d== -2){
        cout << y << " " << x << endl;
    }else if(d == 1 | d == -1){
        cout << 2*y << " " << 2*x << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;
}