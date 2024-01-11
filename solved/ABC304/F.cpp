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
#define rep(i, x) for(ll i = 0; i < (x); i++)

vector<ll> enumerate_factor(ll N){
    ll d = 1;
    vector<ll> factors;
    while (d*d <= N){
        if (N%d == 0){
            factors.push_back(d);
            if (N/d != d){
                factors.push_back(N/d);
            }
        }
        d++;
    }
    sort(factors.begin(),factors.end());
    return factors;
} 

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


int main(){
    ll N;
    cin >> N;
    string S;
    cin >> S;
    vector<ll> must;
    rep(i,S.size()){
        if (S[i] == '.') must.push_back(i);
    }
    vector<ll> factors = enumerate_factor(N);
    map<ll,bool> done;
    int n = factors.size();
    ll ans = 0;
    for (int i = n-2;i>=0;i--){
        ll m = factors[i];
        if (done[m]) continue;
        vector<ll> counter(m,0);
        rep(j,must.size()){
            counter[must[j]%m] = 1;
        }
        
        ll cnt = 0;
        rep(j,m){
            if (counter[j] == 0) cnt++;
        }
        vector<ll> temp_factors = enumerate_factor(m);
        rep(j,temp_factors.size()) done[temp_factors[j]] = true;
        ans += power(2,cnt) -1;
        // ans %= mod;
    }
    ans += 1;
    // ans %= mod;
    cout << ans << endl;

}