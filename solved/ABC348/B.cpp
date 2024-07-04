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
    ll n; cin >> n;
    vector<ll> x(n);
    vector<ll> y(n);
    rep(i,n){
        cin >> x[i] >> y[i];
    }
    rep(i,n){
        int index = i;
        ll max_ans = 0;
        rep(j,n){
            if (max_ans < (x[i] - x[j])*(x[i] - x[j]) +(y[i] - y[j])*(y[i] - y[j])){
                index = j;
                max_ans = (x[i] - x[j])*(x[i] - x[j]) +(y[i] - y[j])*(y[i] - y[j]);
            }
        }
        cout << index + 1 << endl;
    }
}