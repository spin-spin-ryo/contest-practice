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
#include <atcoder/segtree>

using namespace std;
using ll = long long;
#define mod 998244353
#define INF 1e+16
#define rep(i, x) for(int i = 0; i < (x); ++i)

using  vector2d = vector<vector<int> >;

template <typename T>
void print(vector<T> v){
    rep(i,v.size()){
        cout << v[i] << endl;
    }
    return;
}

using S = long long;
S op(S a, S b){
    return (a+b)%mod;
}

S e(){
    return 0;
}


const ll BASE = 1999;

ll power(ll n, ll r){
  ll ans = 1;
  for (ll i=0;(r>>i) > 0;i++){
    if ((r>>i)&1){
      ans *= n;
      ans %= mod;
    }
    n*=n;
    n%= mod;
  }
  return ans;
}

int main(){
  ll N,Q; cin >> N >> Q;
  string s; cin>> s;
  vector<ll> v1(N);
  vector<ll> v2(N);
  string S2(s.rbegin(),s.rend());
  ll m = 1;
  rep(i,N){
    ll s1 = (s[i] - 'a');
    ll s2 = (S2[i] - 'a');
    v1[i] = s1*m%mod;
    v2[i] = s2*m%mod;
    //  << v1[i] << " " << v2[i] << endl;
    m*= BASE;
    m%= mod;
  }

  atcoder::segtree<S,op,e> seg1(v1);
  atcoder::segtree<S,op,e> seg2(v2);


  while (Q > 0){
    Q--;
    int q; cin >> q;
    if (q == 1){
      ll x; cin >> x;
      char c; cin >> c;
      x--;
      ll index2 = N-1-x;
      ll cc = (c - 'a');
      seg1.set(x,cc*power(BASE,x)%mod);
      seg2.set(index2,cc*power(BASE,index2)%mod);
    }else{
      ll L,R; cin >> L >> R;
      L--;R--;
      ll r= N-1- L,l = N-1- R;
      ll sum1 = seg1.prod(L,R+1);
      ll sum2 = seg2.prod(l,r+1);
      if (l < L){
        sum2 *= power(BASE, L-l);
        sum2 %= mod;
      }else{
        sum1 *= power(BASE, l -L );
        sum1 %= mod;
      }
      if (sum1 == sum2){
        cout << "Yes" << endl;
      }else{
        cout << "No" << endl;
      }
    }
  }  
}