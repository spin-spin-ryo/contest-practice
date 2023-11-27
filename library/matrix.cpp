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

vector<vector<ll>> mat_mul(vector<vector<ll>> a,vector<vector<ll>> b){
    int n = a.size();
    vector<vector<ll>> c(n,vector<ll>(n));
    rep(i,n){
        rep(j,n){
            rep(k,n){
                c[i][j] += a[i][k]*b[k][j];
            }
        }
    }
    return c;
}

vector<vector<ll>> mat_power(vector<vector<ll>> a,ll n){
    int n= a.size();
    vector<vector<ll>> c(n,vector<ll>(n));
    rep(i,n) c[i][i] = 1;
    vector<vector<ll>> d = a;
    for (int r=0;n>>r > 0;r++){
        if ((n>>r)&1){
            c = mat_mul(c,d);
        }
        d = mat_mul(d,d);
    }
    return c;
}