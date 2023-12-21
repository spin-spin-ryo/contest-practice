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

template <typename T>
struct RMQ{
    const T INF = numeric_limits<T>::max();
    int n;
    vector<T> dat;
    RMQ(int n_):n(), dat(n_*4 ,INF){
        int x = 1;
        while (n_>x){
            x*= 2;
        }
        n = x;
    }

    void update(int i, T x){
        i += n-1;
        dat[i] = x;
        while (i>0){
            i = (i-1)/2;
            dat[i] = min(dat[2*i +1],dat[i*2+2]);
        }
    }

    T query(int a, int b){
        return query_sub(a,b,0,0,n);
    }

    T query_sub(int a, int b, int k, int l, int r){
        if (r <= a || b <= l){
            return INF;
        }else{
            if (a <= l && r <= b){
                return dat[k];
            }
        }
        T vl = query_sub(a,b,k*2 +1 ,l, (l+r)/2);
        T vr = query_sub(a,b,k*2+2,(l+r)/2,r);
        return min(vl,vr);
    }

};

// 0以上のmex 配列が動的に変更するときのmex
void mex(vector<ll> v,RMQ<ll> &solver){
    // [0,1,2,3,4,...]を入力して solver.update(v[i],INF)にする
}

// 0以上のmex
struct mex{
    public:
    set<pair<ll,ll>> m;

    mex() = default;
    // vはソート済み    
    mex(vector<ll> v){
        m.insert(make_pair(INF,INF));
        m.insert(make_pair(-INF,-INF));
        ll start = -1;
        ll now = -1;
        rep(i,v.size()){
            if (start == -1){
                start = v[i];
                now = v[i];
            }else{
                if (v[i]-now == 1){
                    now ++;
                }else{
                    m.insert(make_pair(start,now));
                    start = v[i];
                    now = v[i];
                }

                if (i== (int)v.size() -1){
                    m.insert(make_pair(start,now))
                }
            }
        }
    }

    ll get(){
        if (!m.empty()){
            auto itr = m.begin();
            if ((*itr).first != 0){
                return (ll)0;
            }else{
                return (*itr).second + 1;
            }
        }else{
            return (ll)0;
        }
    }

    void insert(ll x){
        if (!m.empty()){
            auto itr = m.upper_bound(make_pair(x,x));
            ll n1 = (*itr).first;
            ll n2 = (*itr).second;
            itr--;
            ll m2 =  (*itr).second;
            ll m1 = (*itr).first;
            // (x,y)
            if (n1 == x) return;
            //(z,x-1) (x+1,y)
            if (m2 == x-1 & n1 == x+1){
                auto itr1 = m.lower_bound(make_pair(m1,m2));
                m.erase(itr1); 
                auto itr2 = m.lower_bound(make_pair(n1,n2));
                m.erase(itr2);
                m.insert(make_pair(m1,n2));
                return;
            }
            // (z,x-n) (x+1,y)
            if (n1 == x+1){
                auto itr2 = m.lower_bound(make_pair(n1,n2));
                m.erase(itr2);
                m.insert(make_pair(x,n2));
                return;
            }
            
            // (z,x-1) (x+n,y);
            if (m2 == x-1){
                auto itr1 = m.lower_bound(make_pair(m1,m2));
                m.erase(itr1); 
                m.insert(make_pair(m1,x));
                return;
            }
            // (z,x-m) (x+n,y)
            if (m2 < x & x < n1){
                m.insert(make_pair(x,x));
                return;
            }

            //  (x-m,x+n)
            // 何もしない
        }else{
            m.insert(make_pair(x,x));
        }
    }

    void remove(ll x){
        // xがあることが保証されているものとする
        assert(!m.empty());
        auto itr = m.upper_bound(make_pair(x,x));
        ll n1 = (*itr).first;
        ll n2 = (*itr).second;
        itr--;
        ll m2 =  (*itr).second;
        ll m1 = (*itr).first;
        // (x,y)
        if (n1 == x){
            auto itr1 = m.lower_bound(make_pair(n1,n2));
            m.erase(itr1);
            m.insert(make_pair(x+1,n2));
            return;
        }
        // (x,x)
        if (m1 == x & m2 == x){
            auto itr1 = m.lower_bound(make_pair(m1,m2));
            m.erase(itr1);
            return;
        }

        // (z,x)
        if (m2 == x){
            auto itr1 = m.lower_bound(make_pair(m1,m2));
            m.erase(itr1);
            m.insert(make_pair(m1,x-1));
            return;
        }
        // (x-n,x+m)
        if (m1 < x & x < m2){
            auto itr1 = m.lower_bound(make_pair(m1,m2));
            m.erase(itr1);
            m.insert(make_pair(m1,x-1));
            m.insert(make_pair(x+1,m2));
            return;
        }    
    }

};

