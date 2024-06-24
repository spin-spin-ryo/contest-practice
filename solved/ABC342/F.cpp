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
#include <atcoder/lazysegtree>

using namespace std;
using ll = long long;
using ld = long double;
#define mod 998244353
#define INF 1e+16
#define rep(i, x) for(int i = 0; i < (x); i++)

using  vector2d = vector<vector<int> >;
using S = long double;
using F = long double;
S op(S a, S b){
  return a+b;
}
S e(){
  return 0;
}
S mapping(F f, S x){ return f+x; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

int main(){
    int n,l,d; cin >> n >> l >> d;
    vector<ld> ry(l + d+1,0);
    vector<ld> sum_ry(l+d,0);
    vector<ld> win_prob_at_x(n+2,0);
    vector<ld> sum_win_prob_at_x(n+1,0);
    vector<ld> rx(n+2,0);
    ld d_double = (double)d;
    ry[0] = 1;
    ry[1] = -1;
    rx[0] = 1;
    rx[1] = -1;
    rep(i,l+d){
        ry[i+1] += ry[i];
        ld now_prob = ry[i];
        if (i < l){
            ry[i] -= now_prob;
            ry[i+1] += now_prob/d_double;
            ry[i+1+d] -= now_prob/d_double;
        }
    }
    
    sum_ry[0] = ry[0];
    for(int i=1;i<l+d;i++){
        sum_ry[i] = sum_ry[i-1] + ry[i];
    }
    for(int x=1;x<n+1;x++){
        ld win_prob = 0;
        if (n+1 < l+d){
            win_prob += sum_ry[l+d-1] - sum_ry[n];
        }
        if (l< x){
            win_prob += sum_ry[x - 1] - sum_ry[l-1];
        }
        win_prob_at_x[x] = win_prob;
    }
    
    sum_win_prob_at_x[0] = win_prob_at_x[0];
    for (int x=1;x<n+1;x++){
        sum_win_prob_at_x[x]=sum_win_prob_at_x[x-1]+win_prob_at_x[x];
    }
    
    for(int x=0;x<n+1;x++){
        rx[x+1] += rx[x];
        ld now_prob = rx[x];
        ld now_win_rate = win_prob_at_x[x];
        ld next_win_rate = (sum_win_prob_at_x[min(x+d,n)] - sum_win_prob_at_x[x])/d_double;
        if (next_win_rate >= now_win_rate){
            rx[x] -= now_prob;
            rx[x+1] += now_prob/d_double;
            rx[min(x+1+d,n+1)] -= now_prob/d_double;
        }
        
    }
    ld ans = 0;
    rep(x,n+1){
        ans += rx[x]*win_prob_at_x[x];
    }
    cout << setprecision(16)<<ans << endl;
}