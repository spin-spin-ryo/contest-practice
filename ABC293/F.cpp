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

// どうやってもオーバーフローする

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
    ll r = pow(double(N),1/double(s)) +1;
    // ll r = N;
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

bool check_zeroone(ll N, ll b, ll d){
    if (b == 1){
        return false;
    }
    while (N!=1){
        if (N%b == 0){
            N/= b;
            d--;
        }else{
            if (N%b != 1){
                return false;
            }else{
                N = (N-1)/b;
                d--;
            }
        }
    }
    return (d==1?true:false);
}

int main(){
    int T;
    cin >>T;
    while(T > 0){
        T--;
        ll N;
        cin >> N;
        if (N==2){
            cout <<1 << endl;
            continue;
        }
        ll ans = 0;
        ll bit_num = 0;
        for (ll r =0; (N >> r) > 0;r++){
            bit_num++;
        }
        for (ll d = bit_num;d>1;d--){
            if (d == 2){
                ans += 2;
            }else{
                ll b = root_n(N,d-1);
                if (check_zeroone(N,b,d)){
                    
                    ans ++;
                }
            }
        }
        cout << ans << endl;
    }
}