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
    ll N; cin >> N;
    string S;cin >> S;
    rep(i,N-1){
        if (S[i]!='1' & S[i+1] != '1'){
            cout << -1 << endl;
            return 0;
        }
    }
    ll sub = 0;
    if (S[0]=='1' & S[1]!= '1'){
        sub ++;
        string T = "";
        rep(i,S.size() -1){
            char s = S[i];
            int count = (int)(S[i+1] - '0');
            rep(j,count) T+= s;
        }
        S = T;
    }
    vector<ll> x;
    vector<ll> y;
    x.push_back(S[0]-'0');
    ll one_counter=0;
    rep(i,S.size()-1){
        if (S[i+1] =='1'){
            one_counter ++;
        }else{
            y.push_back(one_counter);
            x.push_back(S[i+1]-'0');
            one_counter = 0;
        }
    }
    ll now = 0;
    
    if (one_counter != 0){
        now += one_counter;
    }
    for(int i = y.size() -1 ;i>=0;--i){
        now += x[i+1] + (y[i] - now)%mod + now*x[i+1]%mod;
        now %= mod;
    }
    cout << (now + sub)%mod << endl;
    
}