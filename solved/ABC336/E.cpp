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

int get_digits(string n, int index){
    return (int)(n[index] - '0');
}

int main(){
    string n; cin >> n;
    ll ans = 0;
    for (int M = 1;M<= 9*n.size() ;M++){
        vector<vector<vector<vector<ll>>>> dp(n.size() +1,vector<vector<vector<ll>>>(M+1,vector<vector<ll>> (M+1,vector<ll>(2,0))));
        dp[0][0][0][1] = 1;
        rep(i,n.size()){
            rep(j,M+1){
                rep(k,M+1){
                    rep(d,10){
                        if (j+d <= M){
                            dp[i+1][j+d][(10*k+d)%M][0] += dp[i][j][k][0];
                        }
                    }
                    int D = get_digits(n,i);
                    rep(d,D+1){
                        if (d == D){
                            if (j+d <= M){
                                dp[i+1][j+d][(10*k+d)%M][1] += dp[i][j][k][1];
                            }
                        }else{
                            if (j+d <= M){
                                dp[i+1][j+d][(10*k+d)%M][0] += dp[i][j][k][1];
                            }
                        }
                    }
                }
            }
        }
        ans += dp[n.size()][M][0][0];
        ans += dp[n.size()][M][0][1];  
    }
    cout << ans << endl;
}