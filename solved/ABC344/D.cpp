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
    string t; cin >> t;
    int n; cin >> n;
    int t_length = t.size();
    vector<int> a(n);
    vector<vector<string>> s(n);
    rep(i,n){
        cin >> a[i];
        string ss;
        rep(j,a[i]){
            cin >> ss;
            s[i].push_back(ss);
        }
    }
    vector<vector<ll>> dp(n+1,vector<ll> (t_length+1,INF));
    dp[0][0] = 0;
    rep(i,n){
        rep(j,t_length+1){  
            rep(k,a[i]){
                string ss = s[i][k];
                int l = ss.size();
                if (t.substr(j,l) == ss){
                    dp[i+1][j+l] = min(dp[i+1][j+l],dp[i][j] + 1);
                }
            }
            dp[i+1][j] = min(dp[i][j],dp[i+1][j]);
        }
    }
    if (dp[n][t_length] < INF){
        cout <<dp[n][t_length] << endl;
    }else{
        cout << -1 << endl;
    }
}