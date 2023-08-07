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

using namespace std;
using ll = long long;
#define mod 998244353
#define INF 1e+16
using  vector2d = vector<vector<int> >;

int main(){
    ll N,M,K;cin >> N >> M >> K;
    vector<ll> A(M);
    vector<ll> B(M);
    vector<ll> C(M);
    for (ll i=0;i<M;i++){
        cin >> A[i] >> B[i] >> C[i];
    }
    vector<ll> E(K);
    for (ll i=0;i<K;i++) cin >> E[i];
    vector<ll> dp(N,INF);
    dp[0] = 0;
    for (int i=0;i<K;i++){
        int u = A[E[i]-1];
        int v = B[E[i]-1];
        u--;v--;
        dp[v] = min(dp[v],dp[u] + C[E[i]-1]);
    }
    if (dp[N-1]==INF){
        cout << -1 << endl;
    }else{
        cout << dp[N-1] << endl;
    }
    return 0;
}