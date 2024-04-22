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

// 区間加算, 区間func
struct LazySegmentTree{
    private:
        int n;
        vector<ll> node,lazy;

    public:
        LazySegmentTree(vector<ll> v){
            int sz = (int)v.size();
            n = 1;
            while(n<sz) n*=2;
            node.resize(2*n-1);
            lazy.resize(2*n-1);

            rep(i,sz) node[i+n-1] = v[i];
            for (int i=n-2;i>=0;i--) node[i] = func(node[i*2+1],node[2*i+2]);

        }
    
    ll func(ll x,ll y){
        return x+y;
    }

    ll func_inv(ll x){
        // x = func(y,y)となるyを出力する
        return x/2;
    }

    ll func_power(ll x, ll r){
        return x*r;
    }

    void eval(int k, int l, int r){
        if (lazy[k]!= 0){
            node[k] += lazy[k];

            if (r-l > 1){
                lazy[2*k+1] += func_inv(lazy[k]);
                lazy[2*k+2] += func_inv(lazy[k]);
            }
            lazy[k]=0;
        }
    }

    void add(int a, int b, ll x, int k=0, int l = 0, int r = -1){
        if (r < 0) r = n;

        eval(k,l,r);

        if (b <= l || r<= a) return ;

        if ( a<= l && r <= b){
            lazy[k] += func_power(x,r-l);
            eval(k,l,r);
        }else{
            add(a,b,x,2*k+1,l,(l+r)/2);
            add(a,b,x,2*k+2,(l+r)/2,r);
            node[k] = func(node[2*k+1],node[2*k+2]);
        }
    }

    ll getsum(int a, int b, int k=0,int l=0, int r = -1){
        if(r < 0) r = n;
        if (b<= l || r <= a) return 0;

        eval(k,l,r);
        if (a <= l && r <=b) return node[k];

        ll vl = getsum(a,b,2*k+1,l,(l+r)/2);
        ll vr = getsum(a,b,2*k+2,(l+r)/2,r);
        return func(vl,vr);
    }


};