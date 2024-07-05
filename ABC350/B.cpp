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
    int n,q; cin >> n >> q;
    vector<int> tooth(n,1);
    rep(i,q){
        int a; cin >> a;
        a--;
        tooth[a] = (tooth[a] + 1)%2;
    }
    int ans = 0;
    rep(i,n){
        ans += tooth[i];
    }
    cout << ans << endl;
}