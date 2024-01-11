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

using  vector2d = vector<vector<int> >;

template <typename T>
void print(vector<T> v){
    rep(i,v.size()){
        cout << v[i] << endl;
    }
    return;
}


int main(){
    ll Q; cin >> Q;
    multiset<ll> s;
    multiset<ll> min_set;
    while(Q>0){
        Q--;
        int q; cin >> q;
        if (q == 1){
            ll x; cin >> x;
            s.insert(x);
            if (s.size() > 1){
                auto itr = s.lower_bound(x);
                auto itr_last = s.end();
                itr_last --;
                bool flag1 = false;
                bool flag2 = false;
                if (itr != s.begin()){
                    itr -- ;
                    ll y = (*itr);
                    ll z = y^x;
                    itr ++;
                    min_set.insert(z);
                    flag1 = true;
                }

                if (itr != itr_last & itr != s.end()){
                    itr ++ ;
                    ll y = (*itr);
                    ll z = y^x;
                    itr --;
                    min_set.insert(z);
                    flag2 = true;
                }
                if (flag1 & flag2){
                    itr ++ ;
                    ll y1 = (*itr);
                    itr--;
                    itr--;
                    ll y2 = (*itr);
                    min_set.erase(min_set.find(y1^y2));
                    itr++;
                }
            }
        }
        if (q == 2){
            ll x; cin >> x;
            auto itr = s.lower_bound(x);
            auto itr_last = s.end();
            itr_last --;
            bool flag1 = false;
            bool flag2 = false;
            if (itr != s.begin()){
                itr -- ;
                ll y = (*itr);
                ll z = y^x;
                itr ++;
                min_set.erase(min_set.find(z));
                flag1 = true;
            }

            if (itr != itr_last & itr != s.end()){
                itr ++ ;
                ll y = (*itr);
                ll z = y^x;
                itr --;
                min_set.erase(min_set.find(z));
                flag2 = true;
            }

            if (flag1 & flag2){
                itr ++ ;
                ll y1 = (*itr);
                itr--;
                itr--;
                ll y2 = (*itr);
                min_set.insert(y1^y2);
                itr++;
            }
            s.erase(itr);
        }
        if (q == 3){
            auto itr = min_set.begin();
            cout << (*itr) << endl;
        }
    }
}
