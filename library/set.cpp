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
#define rep(i, x) for(int i = 0; i < (x); i++)

using  vector2d = vector<vector<int> >;

template <typename T>
void print(vector<T> v){
    rep(i,v.size()){
        cout << v[i] << endl;
    }
    return;
}

ll get_max(multiset<ll> &m){
    if (m.empty()) return 0;
    auto itr = m.rbegin();
    return *itr;
}

ll get_min(multiset<ll> &m){
    if (m.empty()) return 0;
    auto itr = m.begin();
    return *itr;
}

ll erase_one_element(ll n,multiset<ll> &m){
    // 要素がないか空だとバグるので注意
    m.erase(m.find(n));
}

int main(){
    multiset<ll> m;
    m.insert(10);
    m.insert(5);
    m.insert(15);
    m.insert(12);
    cout << get_max(m) << endl;
    cout << get_min(m) << endl;
}