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


class BIT{
    // クエリは1-indexedで行う
    public:

    BIT() = default;
    // 入力するベクトルは0-indexed
    explicit BIT(size_t size): m_bit(size+1){}

    explicit BIT(const vector<long long>& v) : m_bit(v.size()+1){
        for (int i=0;i<v.size();i++){
            add((i+1),v[i]);
        }
    }

    // a[1] + ... + a[r]
    long long sum(int r) const{
        long long ret = 0;
        for (; 0< r;r-=(r& -r)){
            ret += m_bit[r];
        }

        return ret;
    }

    // a[r] +  ... + a[l]
    long long sum(int l, int r) const{
        return (sum(r) - sum(l-1));
    }

    void add(int i, long long value){
        for (;i< m_bit.size();i+= (i& -i)){
            m_bit[i] += value; 
        }
    }

    private:
    
    vector<long long> m_bit;

};



int main(){
    ll N,M; cin >> N >> M;
    vector<pair<ll,ll>> A;
    rep(i,N){
        rep(j,M){
            ll a;cin >> a;
            A.push_back(make_pair(a,i));
        }
    }
    sort(A.begin(),A.end());
    BIT solver(N);
    ll ans = 0;
    rep(i,A.size()){
        int index = A[i].second;
        index ++ ;
        ll n = N - index ;
        ll same_index = solver.sum(index,index);
        ll above_index = solver.sum(index+1,N);
        ans += above_index + n*(same_index+1);
        solver.add(index,1);
    }
    cout << ans << endl;
}