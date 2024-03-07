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

ll gcd(ll a,ll b){
    if (a < b) return gcd(b,a);
    if (a%b == 0) return b;
    return gcd(b,a%b);
}

ll lcm(ll a, ll b){
    return a*b/gcd(a,b);
}

ll dp[64][10][10][10][2][2][2];

int main(){
    ll N,a1,a2,a3;cin >> N >> a1 >> a2 >> a3;
    ll digit=0;
    for(ll i=0;(N>>i) > 0;i++){
        digit++;
    }
    rep(i,64) rep(j,10) rep(k,10) rep(l,10) rep(a,2) rep(b,2) rep(c,2) dp[i][j][k][l][a][b][c] = 0;
    ll m = ((ll)1 << (digit-1));
    // cout << m << endl;
    dp[digit][0][0][0][0][0][0] = (ll)1;
    dp[digit][m%a1][m%a2][0][1][1][0] = (ll)1;
    dp[digit][m%a1][0][m%a3][1][0][1] = (ll)1;
    dp[digit][0][m%a2][m%a3][0][1][1] = (ll)1;
    for(ll d = digit-1;d>0;d--){
        // cout << d << endl;
        ll m = ((ll)1 << (d-1));
        // cout << m << endl;
        ll r = (N >> (d-1))&1;
        // cout << r << endl;
        for(ll r1 = 0;r1<a1;r1++){
            for(ll r2 = 0;r2<a2;r2++){
                for (ll r3 = 0;r3<a3;r3++){
                    ll R1 = (r1 + (m%a1))%a1;
                    ll R2 = (r2 + (m%a2))%a2;
                    ll R3 = (r3 + (m%a3))%a3;
                    if (r == 0){
                        // 0 0 0
                        rep(a,2){
                            rep(b,2){
                                rep(c,2){
                                    dp[d][r1][r2][r3][a][b][c] += dp[d+1][r1][r2][r3][a][b][c];
                                    dp[d][r1][r2][r3][a][b][c] %= mod;
                                }
                            }
                        }

                        // 1 1 0
                        dp[d][R1][R2][r3][0][0][1] += dp[d+1][r1][r2][r3][0][0][1];
                        dp[d][R1][R2][r3][0][0][1] %= mod;
                        dp[d][R1][R2][r3][0][0][0] += dp[d+1][r1][r2][r3][0][0][0];
                        dp[d][R1][R2][r3][0][0][0] %= mod;

                        // 1 0 1
                        dp[d][R1][r2][R3][0][1][0] += dp[d+1][r1][r2][r3][0][1][0];
                        dp[d][R1][r2][R3][0][1][0] %= mod;
                        dp[d][R1][r2][R3][0][0][0] += dp[d+1][r1][r2][r3][0][0][0];
                        dp[d][R1][r2][R3][0][0][0] %= mod;

                        // 0 1 1 
                        dp[d][r1][R2][R3][1][0][0] += dp[d+1][r1][r2][r3][1][0][0];
                        dp[d][r1][R2][R3][1][0][0] %= mod;
                        dp[d][r1][R2][R3][0][0][0] += dp[d+1][r1][r2][r3][0][0][0];
                        dp[d][r1][R2][R3][0][0][0] %= mod;
                    }else{
                        // 0 0 0
                        rep(a,2){
                            rep(b,2){
                                rep(c,2){
                                    dp[d][r1][r2][r3][0][0][0] += dp[d+1][r1][r2][r3][a][b][c];
                                    dp[d][r1][r2][r3][0][0][0] %= mod;
                                }
                            }
                        }

                        // 1 1 0
                        dp[d][R1][R2][r3][0][0][0] += dp[d+1][r1][r2][r3][0][0][1];
                        dp[d][R1][R2][r3][0][0][0] %= mod;
                        dp[d][R1][R2][r3][0][0][0] += dp[d+1][r1][r2][r3][0][0][0];
                        dp[d][R1][R2][r3][0][0][0] %= mod;
                        dp[d][R1][R2][r3][1][1][0] += dp[d+1][r1][r2][r3][1][1][1];
                        dp[d][R1][R2][r3][1][1][0] %= mod;
                        dp[d][R1][R2][r3][1][1][0] += dp[d+1][r1][r2][r3][1][1][0];
                        dp[d][R1][R2][r3][1][1][0] %= mod;

                        dp[d][R1][R2][r3][0][1][0] += dp[d+1][r1][r2][r3][0][1][0];
                        dp[d][R1][R2][r3][0][1][0] %= mod;

                        dp[d][R1][R2][r3][0][1][0] += dp[d+1][r1][r2][r3][0][1][1];
                        dp[d][R1][R2][r3][0][1][0] %= mod;

                        dp[d][R1][R2][r3][1][0][0] += dp[d+1][r1][r2][r3][1][0][0];
                        dp[d][R1][R2][r3][1][0][0] %= mod;

                        dp[d][R1][R2][r3][1][0][0] += dp[d+1][r1][r2][r3][1][0][1];
                        dp[d][R1][R2][r3][1][0][0] %= mod;


                        // 1 0 1
                        dp[d][R1][r2][R3][0][0][0] += dp[d+1][r1][r2][r3][0][1][0];
                        dp[d][R1][r2][R3][0][0][0] %= mod;
                        dp[d][R1][r2][R3][0][0][0] += dp[d+1][r1][r2][r3][0][0][0];
                        dp[d][R1][r2][R3][0][0][0] %= mod;
                        dp[d][R1][r2][R3][1][0][1] += dp[d+1][r1][r2][r3][1][1][1];
                        dp[d][R1][r2][R3][1][0][1] %= mod;
                        dp[d][R1][r2][R3][1][0][1] += dp[d+1][r1][r2][r3][1][0][1];
                        dp[d][R1][r2][R3][1][0][1] %= mod;

                        dp[d][R1][r2][R3][0][0][1] += dp[d+1][r1][r2][r3][0][1][1];
                        dp[d][R1][r2][R3][0][0][1] %= mod;
                        dp[d][R1][r2][R3][1][0][0] += dp[d+1][r1][r2][r3][1][0][0];
                        dp[d][R1][r2][R3][1][0][0] %= mod;
                        dp[d][R1][r2][R3][1][0][0] += dp[d+1][r1][r2][r3][1][1][0];
                        dp[d][R1][r2][R3][1][0][0] %= mod;
                        dp[d][R1][r2][R3][0][0][1] += dp[d+1][r1][r2][r3][0][0][1];
                        dp[d][R1][r2][R3][0][0][1] %= mod;

                        // 0 1 1 
                        dp[d][r1][R2][R3][0][0][0] += dp[d+1][r1][r2][r3][1][0][0];
                        dp[d][r1][R2][R3][0][0][0] %= mod;
                        dp[d][r1][R2][R3][0][0][0] += dp[d+1][r1][r2][r3][0][0][0];
                        dp[d][r1][R2][R3][0][0][0] %= mod;
                        dp[d][r1][R2][R3][0][1][1] += dp[d+1][r1][r2][r3][1][1][1];
                        dp[d][r1][R2][R3][0][1][1] %= mod;
                        dp[d][r1][R2][R3][0][1][1] += dp[d+1][r1][r2][r3][0][1][1];
                        dp[d][r1][R2][R3][0][1][1] %= mod;
                        dp[d][r1][R2][R3][0][0][1] += dp[d+1][r1][r2][r3][0][0][1];
                        dp[d][r1][R2][R3][0][0][1] %= mod;
                        dp[d][r1][R2][R3][0][1][0] += dp[d+1][r1][r2][r3][0][1][0];
                        dp[d][r1][R2][R3][0][1][0] %= mod;
                        dp[d][r1][R2][R3][0][0][1] += dp[d+1][r1][r2][r3][1][0][1];
                        dp[d][r1][R2][R3][0][0][1] %= mod;
                        dp[d][r1][R2][R3][0][1][0] += dp[d+1][r1][r2][r3][1][1][0];
                        dp[d][r1][R2][R3][0][1][0] %= mod;
                    }
                }
            }
        }
    }
    ll ans = 0;
    rep(a,2){
        rep(b,2){
            rep(c,2){
                ans += dp[1][0][0][0][a][b][c];
                ans %= mod;
            }
        }
    }
    // a1a2の倍数である1~Nまでの整数の個数
    ll count = 0;
    count += N/lcm(a1,a2);
    count %= mod;
    count += N/lcm(a3,a2);
    count %= mod;
    count += N/lcm(a1,a3);
    count %= mod;
    ans -=count;
    ans %= mod;
    ans --;
    ans %= mod;
    ans += mod;
    ans %= mod;
    cout << ans  << endl;

}