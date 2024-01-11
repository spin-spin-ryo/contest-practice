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
#define rep(i, x) for(int i = 0; i < (x); i++)


ll power(ll n, ll r){
    ll ans = 1;
    for (int i=0;(r>>i) >0 ;i++){
        if ((r>>i)&1){
            ans *= n;
            ans %= mod;
        }
        n *= n;
        n %= mod;
    }
    return ans;
}

ll inv(ll n){
    return power(n, mod-2);
}

int get_pattern(vector<ll> A,ll m){
    int pattern = 2;
    rep(i,A.size()){
        if (A[i] > m){
            return 0;
        }else{
            if (A[i] == m){
                pattern = 1;
            }
        }
    }
    return pattern;
}

int main(){
    ll N,M,K;cin >> N >> M >> K;
    vector<ll> A(N);
    ll count = 0;
    rep(i,N){
        cin >> A[i];
        if (A[i] == 0) count++;
    }
    ll ans = 0;
    for(ll m = 1;m<M+1;m++){
        int pattern = get_pattern(A,m);
        if (pattern == 0){
            continue;
        }
        ll p =0;
        if (pattern == 1){
            p = power(m,count)%mod;
            p*= power(inv(M),count)%mod;
            p%= mod;
        }else{
            p = power(m,count)%mod;
            p*= power(inv(M),count)%mod;
            p%= mod;
            ll q = power(m-1,count)%mod;
            q*= power(inv(M),count)%mod;
            q%= mod;
            p -= q;
            p%=mod;
            if (p<0){
                p+=mod;
            }
        }
        ans += m*p%mod;
        ans %= mod;
    }
    cout << ans << endl;

}