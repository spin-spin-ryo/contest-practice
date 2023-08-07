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
#define mod 998244353
#define INF 1e+16
using  vector2d = vector<vector<int> >;

ll power(ll n, ll r,ll MOD){
    ll ans = 1;
    for (int i=0;(r>>i) >0 ;i++){
        if ((r>>i)&1){
            ans *= n;
            ans %= MOD;
        }
        n *= n;
        n %= MOD;
    }
    return ans;
}

int main(){
    int N,M;cin >> N >> M;
    vector<ll> A(N);
    for (int i=0;i<N;i++) cin >> A[i];
    priority_queue<pair<ll,pair<ll,ll>>> que;
    for (int i=0;i<N;i++){
        for (int j=i+1;j<N;j++){
            ll s = power(A[i],A[j],M) + power(A[j],A[i],M);
            s %= M;
            que.push()
        }
    }

}