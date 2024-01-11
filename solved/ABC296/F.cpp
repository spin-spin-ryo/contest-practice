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
#define rep(i, x) for(ll i = 0; i < (x); i++)

class BIT{
    // クエリは1-indexedで行う
    public:

    BIT() = default;
    // 入力するベクトルは0-indexed
    explicit BIT(size_t size): m_bit(size+1){}

    explicit BIT(const vector<long long>& v) : m_bit(v.size()+1){
        for (ll i=0;i<v.size();i++){
            add((i+1),v[i]);
        }
    }

    // a[1] + ... + a[r]
    long long sum(ll r) const{
        long long ret = 0;
        for (; 0< r;r-=(r& -r)){
            ret += m_bit[r];
        }

        return ret;
    }

    // a[r] +  ... + a[l]
    long long sum(ll l, ll r) const{
        return (sum(r) - sum(l-1));
    }

    void add(ll i, long long value){
        for (;i< m_bit.size();i+= (i& -i)){
            m_bit[i] += value; 
        }
    }

    private:
    
    vector<long long> m_bit;

};

ll get_inversion(vector<ll> A){
    ll N = A.size();
    vector<pair<ll,ll>> B;
    rep(i,N){
        B.push_back(make_pair(A[i],i));
    }
    sort(B.begin(),B.end());
    BIT solver(N);
    ll ans = 0;
    for (ll i = N-1;i>=0;i--){
        ll index = B[i].second;
        ans += solver.sum(index);
        solver.add(index+1,1);
    }
    return ans;
}

int main(){
    ll N;cin >> N;
    vector<ll> A(N);
    vector<ll> B(N);
    rep(i,N) cin >> A[i];
    rep(i,N) cin >> B[i];
    vector<ll> counter_A(200010,0);
    vector<ll> counter_B(200010,0);
    rep(i,N){
        counter_A[A[i]] ++;
        counter_B[B[i]] ++;
    }

    bool all_equal = true;
    bool one_element = true;
    rep(i,200010){
        if (counter_A[i]!= counter_B[i]){
            all_equal = false;
        }
        if (counter_A[i] > 1){
            one_element = false;
        }
    }
    if (all_equal){
        if (!one_element){
            cout << "Yes" << endl;
        }else{
            ll A_inversion = get_inversion(A);
            ll B_inversion = get_inversion(B);
            if ((A_inversion - B_inversion)%2 == 0){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;        
            }
        }
    }else{
        cout << "No" << endl;
    }

}

