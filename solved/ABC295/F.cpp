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

using  vector2d = vector<vector<ll> >;

ll ctoi(char c){
    if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;
}

ll get_substring(string R, string S){
    int r = R.size();
    int s = S.size();
    ll ans = 0;
    for (int i=0;i<r-s + 1;i++){
        if (R.substr(i,s) == S){
            ans ++ ;
        }
    }
    return ans;
}

ll power(ll n, ll r){
    ll ans = 1;
    if (r < 0)return 0;
    for (ll i=0;(r>>i) >0 ;i++){
        if ((r>>i)&1){
            ans *= n;
            // ans %= mod;
        }
        n *= n;
        // n %= mod;
    }
    return ans;
}

ll count(ll R, string S){
    string R_string =  to_string(R);
    ll r = R_string.size();
    ll s = S.size();
    ll ans = 0;
    if (R == 0) return 0;
    rep(i,r){
        // iは少し制限して変動できる
        // i-1までは固定
        rep(k,r -s+1){
            // ｋは部分列の開始位置
            bool exist = true;
            for (ll l = k;l< k+ s;l++){
                if (l < i){
                    if (R_string[l] != S[l-k]){
                        exist = false;
                    }
                }
                if (l==i){
                    ll rl = ctoi(R_string[l]);
                    ll sl = ctoi(S[l-k]);
                    if (sl > rl - 1 | sl < 0 ){
                        exist = false;
                    }
                }
            }
            if (!exist){
                continue;
            }else{
                // 自由な桁
                ll free_num = r - (k+s);
                ll now;
                if (i == 0 & S[0] == '0'){
                    if (k==0) continue;
                }
                if (k>i){
                    ll rl = (ll)ctoi(R_string[i]);
                    // 前のほうの自由な桁がすべて可変でかつSの戦闘が0の時はまずい
                    if (i==0 & S[0] == '0'){
                        now = rl*power(10,k-i-1) -1;
                    }else{
                        now = rl*power(10,k-i-1);                        
                    }
                    now *= power(10,free_num);    
                }else{
                    if (i>= k+s)
                    {
                        ll rl = (ll)ctoi(R_string[i]);
                        now = rl*power(10,r - i-1);
                    }else{
                        if (k==i & i==0 & S[0] == '0'){
                            now = 0;
                        }else{
                            now = power(10,free_num);
                        }
                    }
                    
                }
                ans += now;
            }
        }
         
    }
    ans += get_substring(R_string,S);
    return ans;
}

int main(){
    ll T; cin >> T;
    while (T>0){
        T--;
        string S;
        ll L,R;
        cin >> S >> L >> R;
        // cout << count(L-1,S) << endl;
        cout << count(R, S) - count(L-1,S) << endl;
    }
}