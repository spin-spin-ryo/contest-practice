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
#include <cassert>

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


struct xor_num{
    public:
    xor_num() = default;

    xor_num(ll _n){
        n = _n;
    } 


    bool operator<(const xor_num &other) const{
        ll w1 = 0;
        ll w2 = 0;
        while ( (n >> w1) > 0){
            w1++;
        }

        while ((other.n >> w2) > 0 ){
            w2++;
        }

        if (w1 > w2) return false;
        if (w1 < w2) return true;
        if (w1 == w2){
            rep(i,w1){
                if ( ((n >> i)&1) !=  ((other.n >> i)&1)){
                    return ((n >> i)&1) <  ((other.n >> i)&1);
                }
            }
            return false;
        }

    }
    private:
    ll n;
};

xor_num make_xor_num(ll n){
    xor_num f(n);
    return f;
}

