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

bool check_kaibun(ll n){
    string s = to_string(n);
    reverse(s.begin(),s.end());
    ll N = stoll(s);
    return n == N;
}

int main(){
    ll n;cin >> n;
    for (ll x=min(1000000LL,n);x>0;x--){
        if ((n >= x*x*x) & (check_kaibun(x*x*x))){
            cout << x*x*x << endl;
            return 0;
        }
    }

}