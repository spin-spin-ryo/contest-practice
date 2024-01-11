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
    return *m.rbegin();
}

ll get_min(multiset<ll> &m){
    if (m.empty()) return 0;
    return *m.begin();
}


int main(){
    ll N,K,Q; cin >> N >> K >> Q;
    multiset<ll> upper;
    multiset<ll> lower;
    rep(i,K){
        upper.insert(0);
    }
    rep(i,N-K+10){
        lower.insert(0);
    }
    ll sum =  0;
    vector<ll> A(N,0);
    while(Q>0){
        Q--;
        ll X,Y;cin >> X >> Y;
        X--;
        ll old_value = A[X];
        A[X] = Y;
        ll upper_min = get_min(upper);
        ll lower_max = get_max(lower);
        if (lower_max >= old_value){
            lower.erase(lower.find(old_value));
            sum += Y;
            upper.insert(Y);
            upper_min = get_min(upper);
            upper.erase(upper.find(upper_min));
            lower.insert(upper_min);
            sum -= upper_min;
        }else{
            upper.erase(upper.find(old_value));
            sum -= old_value;
            lower.insert(Y);
            lower_max = get_max(lower);
            sum += lower_max;
            lower.erase(lower.find(lower_max));
            upper.insert(lower_max);
        }
        cout << sum << endl;
    }
}