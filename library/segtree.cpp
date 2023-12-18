// segment tree
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
#include <limits>

using namespace std;
using ll = long long;

// 点変更、区間最小値, 0-indexed
// update a[i]
// RMQ [a,b)
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

int interval_binary_search(RMQ<ll> solver, ll upper, ll l, ll r){
    // A[l],...A[r-1] の中で upper以下の最小のindexを返す.
    if (solver.query(l,r) > upper) return -1;
    while(r - l >1){
        ll m = (r+l)/2;
        if (solver.query(l,m) <= upper){
            r = m;
        }else{
            l = m;
        }
    }
    return l;
}





int main(){
    int n = 5;
    RMQ<ll> solver(n);
    solver.update(0,10);
    solver.update(1,8);
    solver.update(2,15);
    solver.update(3,0);
    solver.update(4,20);

    cout << solver.query(0,4) << endl;
}