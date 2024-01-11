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

ll power(ll n, ll r){
    ll ans = 1;
    for (int i=0;(r>>i) >0 ;i++){
        if ((r>>i)&1){
            ans *= n;
        }
        n *= n;
    }
    return ans;
}



ll root_n(ll N, ll s){
    ll l = 1;
    ll r = pow(double(N),1/double(s)) + 10;
    while (r - l > 1){
        ll m = (r+l)/2;
        if (power(m,s) <= N){
            l = m;
        }else{
            r = m;
        }
    }
    return l;
}

bool check_zeroone(ll N, ll b){
    if (b == 1){
        return false;
    }
    while (N!=1){
        if (N%b == 0){
            N/= b;
        }else{
            if (N%b != 1){
                return false;
            }else{
                N = (N-1)/b;
            }
        }
    }
    return true;
}

int main(){
    int T;
    cin >>T;
    while(T > 0){
        T--;
        ll N;
        cin >> N;
        ll ans = 0;
        ll bit_num = 0;
        for (ll r =0; (N >> r) > 0;r++){
            bit_num++;
        }
        for (ll d = bit_num;d>0;d--){
            if (d == 2){
                ans += 2;
            }else{
                ll b = root_n(N,d);
                if (check_zeroone(N,b)){
                    ans ++;
                }
            }
        }
        cout << ans << endl;
    }
}