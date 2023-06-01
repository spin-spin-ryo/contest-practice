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
            lookup[i] = lookup[i>> 1] + 1;
        }
    }
    // [l,r)
    inline T rmq(int l, int r){
        int b = lookup[r-l];
        return min(st[b][l],st[b][r - (1<<b)]);
    }
};

int main(){
    vector<int> v = {10,9,8};
    SparseTable<int> sp(v);
    cout << sp.rmq(0,1) << endl;
    return 0;
}