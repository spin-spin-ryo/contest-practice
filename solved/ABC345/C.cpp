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
    string s;cin >> s;
    vector<int> count(26,0);
    rep(i,s.size()){
        count[s[i] - 'a']++;
    }
    ll ans = 0;
    int n = s.size();
    bool isSame = false;
    rep(i,s.size()){
        ans += (n - count[s[i] - 'a']);
        if (count[s[i] - 'a'] > 1){
            isSame = true;
        }
        n--;
        count[s[i] - 'a']--;
    }
    if (isSame) ans++;
    cout << ans << endl;
}