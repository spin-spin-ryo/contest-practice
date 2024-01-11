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
using  vector2d = vector<vector<int> >;


long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a%b, y, x);
    y -= a/b * x;
    return d;
}



ll get_min_val(ll a, ll r1,ll b, ll r2){
    ll x,y;
    extGCD(a,b,x,y);
    // ax + by = 1
    x*= (r2-r1);
    y*= (r2-r1);
    ll tmp = a*x + r1;
    return (tmp%(a*b)+a*b)%(a*b);
}

int main(){
    ll M = 108;
    cout << M << endl;
    vector<ll> cycle = {4,9,5,7,11,13,17,19,23};
    vector<ll> mods;
    vector<ll> A;
    ll now_index = 1;
    for (ll i = 0;i<cycle.size();i++){
        ll r = cycle[i];
        for (int j=0;j<r;j++){
            if (j != r-1){
                A.push_back(now_index + j+1);
            }else{
                A.push_back(now_index );
            }
        }
        now_index += r;
    }
    for (int i=0;i<A.size();i++){
        cout << A[i] << " ";
    }
    cout << endl;

    // ll N = 1000000200;
    vector<ll> B(M);

    // for (int i=0;i<M;i++){
    //     ll _N = N;
    //     while (_N>0){
    //         if (_N == N){
    //             B[i] = A[i];
    //         }else{
    //             B[i] = A[B[i]-1];
    //         }
    //         _N--;
    //     }
    // }

    


    
    for (int i=0;i<M;i++){
        cin >> B[i];
    }

    // for (int i=0;i<M;i++){
    //     cout << B[i] << endl;
    // }

    now_index = 1;
    for (int i=0;i<cycle.size();i++){
        ll r = cycle[i];
        mods.push_back((B[now_index -1] - now_index  +r)%r);
        now_index += r;
    }

    ll now_mod = mods[0];
    ll now_pro = cycle[0];
    for (int i=1;i<cycle.size();i++){
        ll next_mod = get_min_val(now_pro, now_mod, cycle[i], mods[i]);
        now_pro*= cycle[i];
        now_mod = next_mod;
    }
    cout << now_mod << endl;
    return 0;
}