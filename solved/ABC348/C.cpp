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
    ll n; cin >> n;
    unordered_map<ll,ll> color2min_a;
    rep(i,n){
        ll a,c; cin >> a >> c;
        auto itr = color2min_a.find(c);
        if (itr != color2min_a.end()){
            color2min_a[c] = min(color2min_a[c],a);
        }else{
            color2min_a[c] = a;
        }
    }
    ll max_value = 0;
    int color = -1;
    auto itr = color2min_a.begin();
    while (itr != color2min_a.end()){
        if (max_value < (*itr).second){
            color = (*itr).first;
            max_value = (*itr).second;
        }
        itr++;
    }
    cout << max_value << endl;
}