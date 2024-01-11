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

using namespace std;
using ll = long long;
#define mod 998244353
#define INF 1e+16
using  vector2d = vector<vector<ll> >;

ll power(ll n, ll r){
    ll ans = 1;
    for (ll i=0;(r>>i) >0 ;i++){
        if ((r>>i)&1){
            ans *= n;
            ans %= mod;
        }
        n *= n;
        n %= mod;
    }
    return ans;
}

ll inv(ll n){
    return power(n, mod-2);
}

class BIT{
    // 1-indexed
    public:

    BIT() = default;
    // 入力は0-indexed
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
            ret %= mod;
        }

        return ret;
    }

    // a[r] +  ... + a[l]
    long long sum(ll l, ll r) const{
        if (l <= r){
            return (sum(r) - sum(l-1));
        }else{
            return 0;
        }
        
    }

    void add(ll i, long long value){
        for (;i< m_bit.size();i+= (i& -i)){
            m_bit[i] += value; 
            m_bit[i] %=mod;
        }
    }

    private:
    
    vector<long long> m_bit;

};


int main(){
    ll N;cin >> N;
    vector<ll> A(N);
    vector<ll> B(N);
    for (ll i=0;i<N;i++){
        cin >> A[i];
        B[i] = A[i];
    } 
    sort(B.begin(),B.end());
    auto itr = unique(B.begin(),B.end());
    B.erase(itr,B.end());
    map<ll,ll> value2key;
    for (ll i=0;i<B.size();i++){
        value2key[B[i]] = i;
    }
    ll sum_A = 0;
    ll sub_sum = 0;
    BIT keys(B.size());
    BIT values_BIT(B.size());
    for (ll k=0;k<N;k++){
        sum_A += A[k];
        sum_A %=mod;
        ll index = value2key[A[k]];
        keys.add(index+1,1);
        values_BIT.add(index+1,A[k]);
        sub_sum += keys.sum(index)*A[k]%mod-values_BIT.sum(index);
        sub_sum %= mod;
        sub_sum += values_BIT.sum(index +2 , B.size())%mod - keys.sum(index +2 , B.size())*A[k]%mod;
        sub_sum %= mod;
        ll ans = 0;
        ans += (sum_A*inv(k+1)%mod + sub_sum*inv((k+1)*(k+1)%mod)%mod)%mod;
        ans %= mod;
        if (ans<0){
            ans += mod;
            ans %= mod;
        }
        cout << ans << endl;
    }
    return 0;
}