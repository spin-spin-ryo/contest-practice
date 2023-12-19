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

using namespace std;
using ll = long long;
#define mod 998244353
#define INF 1e+16
using  vector2d = vector<vector<int> >;

template<typename T>
struct SparseTable{
    vector<vector<T> >st;
    vector<int> lookup;

    SparseTable(const vector<T> &v){
        int b = 0;
        while ((1<<b) <= v.size()) ++b;
        st.assign(b,vector<T>(1<<b));
        for (int i=0;i<v.size();i++){
            st[0][i] = v[i];
        }

        for (int i=1;i<b;i++){
            for (int j=0;j+(1 << i) <= (1<<b);j++){
                st[i][j] = min(st[i-1][j],st[i-1][j + (1 << (i-1))]);
            }
        }
        lookup.resize(v.size() + 1);

        for (int i=2;i < lookup.size();i++){
            lookup[i] = lookup[i >> 1] + 1;
        }
    }
    // [l,r)
    inline T rmq(int l, int r){
        if (r-l == 0) return INF;
        int b = lookup[r-l];
        return min(st[b][l],st[b][r - (1<<b)]);
    }
};

int interval_binary_search(SparseTable<ll> &solver, ll upper, ll l, ll r){
    // A[l],...A[r-1] の中で upper以下の最小のindexを返す.
    if (solver.rmq(l,r) > upper) return -1;
    while(r - l >1){
        ll m = (r+l)/2;
        if (solver.rmq(l,m) <= upper){
            r = m;
        }else{
            l = m;
        }
    }
    return l;
}

int main(){
    vector<int> v = {10,9,8,11,15,20};
    SparseTable<int> sp(v);
    cout << sp.rmq(3,5) << endl;
    return 0;
}