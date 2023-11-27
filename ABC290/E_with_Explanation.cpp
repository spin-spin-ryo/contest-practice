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
// 解説AC
// 逆を考えた方がシンプルになる。部分問題の解放は思いつくか微妙だな

ll solve_subproblem(ll N, vector<ll> P){
    int r = P.size()-1;
    int l = 0;
    ll ans = 0;
    while (r>l){
        if (P[l] <= N+1-P[r]){
            ans += P[l]*(r-l);
            l++;
        }else{
            ans += ( N+1-P[r])*(r-l);
            r--;
        }
    }
    return ans;
}

int main(){
    ll N;cin >> N;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];
    ll sum = 0;
    rep(i,N){
        sum += ((i+1)/2)*(N-i);
    }
    vector<vector<ll>> g(N);
    rep(i,N){
        g[A[i]-1].push_back(i+1);
    }

    rep(x,N){
        sum -= solve_subproblem(N,g[x]);
    }
    cout << sum << endl;

}