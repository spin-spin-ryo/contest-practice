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
    int N,K,Q;cin >> N >> K >> Q;
    vector<int> all_num;
    rep(i,N){
        all_num.push_back(0);
    }
    vector<int> X(Q);
    vector<int> Y(Q);
    rep(i,Q){
        cin >> X[i] >> Y[i];
        X[i]--;
        all_num.push_back(Y[i]);
    }
    sort(all_num.begin(),all_num.end());
    map<int,queue<int>> counter;
    rep(i,all_num.size()){
        counter[all_num[i]].push(i);
    }
    vector<pair<int,int>> A(N);
    vector<ll> zeroone(N+Q,0);
    rep(i,N){
        int n = counter[0].front();
        A[i] = make_pair(0,n);
        zeroone[n] = 1;
        counter[0].pop();
    }
    vector<ll> Z(Q);
    rep(i,Q){
        Z[i] = counter[Y[i]].front();
        counter[Y[i]].pop();
    }
    BIT solver(zeroone);
    vector<ll> AA(N+Q,0);
    BIT solver2(AA);


    rep(i,Q){
        int old_index = X[i];
        int new_index1 = Z[i];
        int new_index2 = A[old_index].second;
        solver.add(new_index2+1,-1);
        solver.add(new_index1+1,1);
        solver2.add(new_index2+1,-A[old_index].first);
        solver2.add(new_index1+1,Y[i]);
        A[old_index] = make_pair(Y[i],new_index1);
        int r = N+Q+1;
        int l = 1;
        while (r - l > 1){
            int m = (r+l)/2;
            int k = solver.sum(m,N+Q);
            if (k>=K){
                l = m;
            }else{
                r = m;
            }
        }
        cout << solver2.sum(l,N+Q) << endl;


    }
}