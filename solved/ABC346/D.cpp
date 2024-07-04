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
    int n; cin >> n;
    string s; cin >> s;
    vector<ll> c(n); rep(i,n) cin >> c[i];
    vector<int> swap(n,0);
    ll now_ans = 0;
    // 10101にするためのコスト
    rep(i,n){
        if (i%2 == 0){
            if (s[i] == '1'){
                continue;
            }else{
                swap[i] = 1;
                now_ans += c[i];
            }
        }else{
            if (s[i] == '0'){
                continue;
            }else{
                swap[i] = 1;
                now_ans += c[i];
            }
        }
    }

    // 最初の文字をswapを0にする
    // 01010にするためのコスト
    if (swap[0] == 0){
        now_ans +=c[0];
        swap[0] = 1;
    }else{
        swap[0] = 0;
        now_ans -=c[0]; 
    }
    ll ans = now_ans;
    for(int i=1;i<n-1;i+=1){
        if (swap[i] == 0){
            swap[i] = 1;
            now_ans += c[i];
        }else{
            swap[i] = 0;
            now_ans -= c[i];
        }
        ans = min(ans,now_ans);
    }
    rep(i,n) swap[i] = 0;
    now_ans = 0;
    // 01010101にするためのコスト
    rep(i,n){
        if (i%2 == 0){
            if (s[i] == '0'){
                continue;
            }else{
                swap[i] = 1;
                now_ans += c[i];
            }
        }else{
            if (s[i] == '1'){
                continue;
            }else{
                swap[i] = 1;
                now_ans += c[i];
            }
        }
    }

    // 最初の文字をswapを0にする
    // 1011010にするためのコスト
    if (swap[0] == 0){
        now_ans +=c[0];
        swap[0] = 1;
    }else{
        swap[0] = 0;
        now_ans -=c[0]; 
    }
    for(int i=1;i<n-1;i+=1){
        if (swap[i] == 0){
            swap[i] = 1;
            now_ans += c[i];
        }else{
            swap[i] = 0;
            now_ans -= c[i];
        }
        ans = min(ans,now_ans);
    }
    cout << ans << endl;
}