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
#include <unordered_map>

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
    ll l,r; cin >> l >> r;
    ll now = l;
    vector<pair<ll,ll>> ans;
    while (now != r){
        ll count_2 = 0;
        ll tmp = now;
        ll power_2 = 1;
        while (tmp%2 == 0){
            ll j = now/(power_2*2);
            if ((j+1)*power_2*2 <= r){
                power_2*= 2;
                tmp/=2;
            }else{
                break;
            }
        }
        ll j = now/power_2;
        ans.push_back({now,power_2*(j+1)});
        now = power_2*(j+1);
    }
    cout << ans.size() << endl;
    rep(i,ans.size()){
        cout << ans[i].first << " " << ans[i].second << endl;
    }
}