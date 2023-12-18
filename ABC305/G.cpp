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

template <typename T>
void print(vector<T> v){
    rep(i,v.size()){
        cout << v[i] << endl;
    }
    return;
}

vector<string> generate_ab(ll length){
    vector<string> t;
    for(ll i=0;i<(1<<length);i++){
        string s = "";
        for (ll r = 0;r<length;r++){
            if ((i>>r)&1){
                s += "a";
            }else{
                s+= "b";
            }
        }
        t.push_back(s);
    }
    return t;
}

bool check_substring(string t, string s){
    ll T = t.size();
    ll S = s.size();
    rep(i,T-S+1){
        if (t.substr(i,S) == s){
            return true;
        }
    }
    return false;
}


vector<vector<ll>> mat_mul(vector<vector<ll>> a,vector<vector<ll>> b){
    ll n = a.size();
    vector<vector<ll>> c(n,vector<ll>(n));
    rep(i,n){
        rep(j,n){
            rep(k,n){
                c[i][j] += a[i][k]*b[k][j]%mod;
                c[i][j] %= mod;
            }
        }
    }
    return c;
}

vector<vector<ll>> mat_power(vector<vector<ll>> a,ll n){
    ll N = a.size();
    vector<vector<ll>> c(N,vector<ll>(N,0));
    rep(i,N) c[i][i] = 1;
    vector<vector<ll>> d = a;
    for (ll r=0;n>>r > 0;r++){
        if ((n>>r)&1){
            c = mat_mul(c,d);
        }
        d = mat_mul(d,d);
    }
    return c;
}

vector<string> generate_use_t(vector<string> s, ll length){
    vector<string> t = generate_ab(length);
    vector<bool> canuse(t.size(),true);
    rep(i,t.size()){
        rep(j,s.size()){
            if (check_substring(t[i],s[j])){
                canuse[i] = false;
            }
        }
    }

    vector<string> tt;
    rep(i,t.size()){
        if (canuse[i]) tt.push_back(t[i]);
    }
    return tt;
}

int main(){
    ll N,M; cin >> N >> M;
    vector<string> s(M);
    rep(i,M) cin >> s[i];
    ll r = N%6;
    ll n = N -r;
    if (n>0){
        vector<string> t = generate_use_t(s,6);
        vector<vector<ll>> graph(t.size(),vector<ll>(t.size(),0));
        rep(i,t.size()){
            rep(j,t.size()){
                string tt = t[i] + t[j];
                bool flag = true;
                rep(k,s.size()){
                    if (check_substring(tt,s[k])){
                        flag = false;
                    }
                }
                if (flag){
                    graph[i][j] = 1;
                }
            }
        }
        vector<vector<ll>> M = mat_power(graph,n/6 -1);
        if (r == 0){
            ll ans = 0;
            rep(i,M.size()){
                rep(j,M.size()){
                    ans += M[i][j];
                    ans %= mod;
                }
            }
            cout << ans << endl;
        }else{
            vector<string> tt = generate_use_t(s,r);
            vector<vector<ll>> graph2(t.size(),vector<ll>(tt.size(),0));
            rep(i,t.size()){
                rep(j,tt.size()){
                    string ttt = t[i] + tt[j];
                    bool flag = true;
                    rep(k,s.size()){
                        if (check_substring(ttt,s[k])){
                            flag = false;
                        }
                    }
                    if (flag){
                        graph2[i][j] = 1;
                    }
                }
            }
            vector<ll> counter(t.size(),0);
            rep(i,M.size()){
                rep(j,M.size()){
                    counter[j] += M[i][j];
                }
            }
            ll ans = 0;
            rep(i,graph2.size()){
                rep(j,graph2[i].size()){
                    ans += counter[i]*graph2[i][j]%mod;
                    ans %= mod;
                }
            }
            cout << ans << endl;
        }


        return 0;
    }else{
        vector<string> t = generate_use_t(s,r);
        cout << t.size() << endl;
    }
    return 0;
}