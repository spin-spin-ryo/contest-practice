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
#define rep(i, x) for(ll i = 0; i < (x); i++)

ll count(vector<long double> A,vector<long double> B,vector<long double> C,vector<long double> D,long double r){
    ll N = A.size();
    ll M = C.size();
    vector<long double> x(N);
    vector<long double> y(M);
    rep(i,N){
        x[i] = (long double)(100.0)*A[i] - r*(A[i] + B[i]);
    }
    rep(i,M){
        y[i] = r*(C[i] + D[i]) - (long double)(100.0)*C[i];
    }
    sort(x.begin(), x.end());
    ll k =0;
    rep(i,M){
        auto index = lower_bound(x.begin(),x.end(),y[i]);
        ll index_num = (ll)(index - x.begin());
        k+= (N - index_num );
    }
    return k;
    
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N,M,K;cin >> N >> M >> K;
    long double l = 0.0;
    long double r = 100.0;
    vector<long double> A(N);
    vector<long double> B(N);
    vector<long double> C(M);
    vector<long double> D(M);
    rep(i,N){
        cin >> A[i] >> B[i];
    }
    rep(i,M){
        cin >> C[i] >> D[i];
    }
    while (abs(r-l) > 1e-13){
        long double m = (r+l)/2;
        ll k = count(A,B,C,D,m);
        if (k >= K){
            l = m;
        }else{
            r = m;
        }
    }
    cout << fixed << setprecision(10)<< l << endl;
}

