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

using  vector2d = vector<vector<int> >;

// 解説AC 競プロで行列を使う発想がなかったな

// 正方行列
vector<vector<ll>> mat_add(vector<vector<ll>> a,vector<vector<ll>> b){
    int n = a.size();
    vector<vector<ll>> c(n,vector<ll>(n));
    rep(i,n){
        rep(j,n){
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    return c;
}

vector<vector<ll>> mat_mul(vector<vector<ll>> a,vector<vector<ll>> b,ll M){
    int n = a.size();
    vector<vector<ll>> c(n,vector<ll>(n));
    rep(i,n){
        rep(j,n){
            rep(k,n){
                c[i][j] += a[i][k]*b[k][j]%M;
                c[i][j]%= M;
            }
        }
    }
    return c;
}

vector<vector<ll>> mat_power(vector<vector<ll>> a,ll n,ll M){
    int N= a.size();
    vector<vector<ll>> c(N,vector<ll>(N));
    rep(i,N) c[i][i] = 1;
    vector<vector<ll>> d = a;
    for (int r=0;n>>r > 0;r++){
        if ((n>>r)&1){
            c = mat_mul(c,d,M);
        }
        d = mat_mul(d,d,M);
    }
    return c;
}

int main(){
    ll A,X,M; cin >> A >> X >> M;
    vector<vector<ll>> a(2,vector<ll>(2,0));
    a[0][0] = A;
    a[0][1] = 1;
    a[1][1] = 1;
    vector<vector<ll>> c = mat_power(a,X,M);
    cout << c[0][1] << endl;
}