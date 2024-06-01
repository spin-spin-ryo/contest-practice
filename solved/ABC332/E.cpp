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
using ld = long double;
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
    ll n,d; cin >> n >> d;
    vector<ld> w(n);
    ld w_ave = 0;
    rep(i,n){
        cin >> w[i];
        w_ave += w[i];
    }
    w_ave /= (ld)d;
    vector<vector<ld>> dp(1<<n,vector<ld>(d+1,INF));
    for (ll m = 0;m<(1<<n);m++){
        ld sum = 0;
        for (ll r = 0;r<n;r++ ){
            if ((m>>r)&1){
                sum += w[r];
            }
        }
        dp[m][1] = (sum - w_ave)*(sum - w_ave)/d;
    }

    for (ll m = 1;m<(1<<n);m++){
        for (ll dd = 2;dd<=d;dd++){
            for (ll z = m;z>0;z = (z-1)&m){
                dp[m][dd] = min(dp[m][dd], dp[m - z][dd-1] + dp[z][1]);
            }
        }
    }
    cout << setprecision(18)<<dp[(1 << n) -1][d] << endl;

}