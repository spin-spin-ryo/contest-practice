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
    ll Q,K; cin >> Q >> K;
    vector<ll> dp(K+1,0);
    dp[0] = 1;
    for (int i=0;i<Q;i++){
        char s;
        int x;
        cin >> s >> x;
        vector<ll> after_dp(K+1,0);
        if (s == '+'){
            for (int j=0;j<K+1;j++){
                if (j-x >= 0){
                    after_dp[j] = (dp[j] + dp[j-x])%mod;
                }else{
                    after_dp[j] = dp[j];
                }
            }
        }else{
            for (int j=0;j<K+1;j++){
                if (j-x < 0){
                    after_dp[j] = dp[j];
                }else{
                    after_dp[j] = (dp[j] - after_dp[j-x])%mod;
                }
            }
        }
        rep(j,dp.size()){
            dp[j] = after_dp[j];
        }
        cout << (dp[K]+mod)%mod << endl;
    }
}