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
    int n,q; cin >> n >> q;
    vector<int> count(q);
    vector<ll> magnitude(q);
    vector<ll> accumulate(q+1,0);
    ll now = 0;
    vector<vector<int>> indexes(n);
    rep(i,q){
        int x; cin >> x;
        x--;
        indexes[x].push_back(i+1);
        if (count[x] == 0){
            count[x] = 1;
            now++;
        }else{
            count[x] = 0;
            now--;
        }
        magnitude[i] = now;
        accumulate[i+1] = magnitude[i] + accumulate[i];
    }
    rep(i,n){
        indexes[i].push_back(q+1);
    }
    vector<ll> ans(n,0);
    rep(i,n){
        int l =  indexes[i].size();
        rep(j, l-1){
            if (j%2 == 0){
                ans[i] += accumulate[indexes[i][j+1]-1] - accumulate[indexes[i][j]-1];
            }
        }
    }
    rep(i,n){
        cout << ans[i] << " ";
    }
    cout << endl;
}