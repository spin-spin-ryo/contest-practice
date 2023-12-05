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

// update a[i]
// RMQ [a,b)
template <typename T>
struct RMQ{
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


int main(){
    ll N;cin >> N;
    vector<ll> index2row;
    vector<ll> index2col;
    map<ll,ll> row2index;
    map<ll,ll> col2index;
    vector<ll> r(N);
    vector<ll> c(N);
    vector<ll> x(N);
    rep (i,N){
        cin >> r[i] >> c[i] >> x[i];
        index2col.push_back(c[i]);
        index2row.push_back(r[i]);
    }

    index2col.erase(unique(index2col.begin(), index2col.end()), index2col.end());
    index2row.erase(unique(index2row.begin(), index2row.end()), index2row.end());
    rep(i,index2col.size()){
        col2index[index2col[i]] = i;
    }
    rep (i,index2row.size()){
        row2index[index2row[i]] = i;
    }
    ll row_size = index2row.size();
    ll col_size = index2col.size();
    vector<vector<pair<ll,ll>>> row2element(row_size);
    vector<ll> row_sum(row_size,0);
    vector<ll> col_sum(col_size,0);
    rep(i,N){
        ll index_row = row2index[r[i]];
        ll index_col = col2index[c[i]];
        row2element[index_row].push_back(make_pair(index_col,x[i]));
        row_sum[index_row] += x[i];
        col_sum[index_col] -= x[i];
    }

    RMQ<ll> rmq(col_size);
    rep (i,col_size){
        rmq.update(i,col_sum[i]);
    }


    ll max_ans = 0;
    rep(i,row_size){
        ll now = row_sum[i];
        for (auto p:row2element[i]){
            ll index_col = p.first;
            ll cost = p.second;
            rmq.update(index_col,col_sum[index_col] + cost);
        }
        ll c = rmq.query(0,col_size);
        now -= c;
        max_ans = max(max_ans,now);
        for (auto p:row2element[i]){
            ll index_col = p.first;
            rmq.update(index_col,col_sum[index_col]);
        }
        
    }
    
    cout << max_ans << endl;

}