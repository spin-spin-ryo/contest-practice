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
#define rep(i, x) for(ll i = 0; i < (x); i++)

using  vector2d = vector<vector<ll> >;

template <typename T>
void prll(vector<T> v){
    rep(i,v.size()){
        cout << v[i] << endl;
    }
    return;
}



int main(){
    ll h,w,m; cin >> h >> w >> m;
    vector<pair<ll,ll>> row_color(h,{0,0});
    vector<pair<ll,ll>> column_color(w,{0,0});
    vector<pair<ll,ll>> queries(m+1,{0,0});
    rep(i,m){
        ll t,a,x; cin >> t >> a >> x;
        a--;
        if (t == 1){
            row_color[a] = {x,i+1};
        }else{
            column_color[a] = {x,i+1};
        }
    }
    ll row_color_counter = 0;
    ll column_color_counter = 0;
    vector<ll> ans(200001,0);

    rep(i,h){
        auto p = row_color[i];
        if (p.second > 0){
            row_color_counter ++;
            queries[p.second] = {1,p.first};
        }
    }
    rep(i,w){
        auto p = column_color[i];
        if (p.second > 0){
            column_color_counter ++;
            queries[p.second] = {2,p.first};
        }
    }
    rep(i,m+1){
        auto p =queries[i];
        ll t = p.first;
        ll x = p.second;
        if (t > 0){
            if (t == 1){
                ans[x] += w - column_color_counter;
                row_color_counter --;
            }else{
                ans[x] += h - row_color_counter;
                column_color_counter --;
            }
        }
    }
    ll color_count = 0;
    rep(i,200001){
        color_count += ans[i];
    }
    ans[0] += h*w - color_count;
    int color_num = 0;
    rep(i,200001){
        if (ans[i] > 0) color_num++;
    }
    cout << color_num << endl;
    rep(i,200001){
        if (ans[i] > 0){
            cout << i << " " << ans[i] << endl;
        }
    }
}