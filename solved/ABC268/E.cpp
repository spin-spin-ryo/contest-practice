#include<iostream>
#include<vector>
#include <tuple>
#include <string>
#include <algorithm>
#include <stack>
#include <utility>
#include <queue>
using namespace std;
using ll = long long;
#define mod 998244353
using  vector2d = vector<vector<ll> >;


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

class BIT_RAQ{
    public:
    BIT_RAQ() = default;

    explicit BIT_RAQ(size_t size): m_bit0(size),m_bit1(size) {}

    explicit BIT_RAQ(const vector<long long>& v): m_bit0(v), m_bit1(v.size()) {}

    long long sum(ll r) const{
        return (m_bit0.sum(r) + m_bit1.sum(r)*r);
    }

    long long sum(ll l, ll r) const{
        return (sum(r) - sum(l-1));
    }

    void add(ll i, long long value){
        m_bit0.add(i,value);
    }

    void add(ll l, ll r, long long value){
        m_bit0.add(l ,(-value*(l-1)));
        m_bit0.add((r+1),(value*r));
        m_bit1.add(l,value);
        m_bit1.add((r+1),-value);
        
    }

    private:

    BIT m_bit0;
    BIT m_bit1;

};



int main(){
    ll N;cin >> N;
    vector<ll> p(N);
    for (ll i=0;i<N;i++) cin >> p[i];
    BIT_RAQ incline(N);
    
    ll now_cost = 0;
    for (ll i=0;i<N;i++){
        now_cost += min((p[i] - i + N)%N,(i - p[i] + N)%N);
        ll k = min((p[i] - i + N)%N,(i - p[i] + N)%N);
        if (p[i] == (i+k)%N){
            p[i] = k;
        }else{
            p[i] = (N - k)%N  ;
        }
        if (p[i] + N/2 <=N){
            incline.add(p[i]+1,p[i]+N/2 ,1);
            if (p[i] - N/2 +1 < 1){
                incline.add(1,p[i],-1);
                incline.add(N - N/2  + p[i] +1 ,N,-1);
            }else{
                incline.add(p[i] - N/2 +1,p[i],-1);
            }
            
        }else{
            incline.add(p[i]+1 - N/2,p[i],-1);
            if (p[i] + N/2 >N){
                incline.add(p[i]+1,N,1);
                incline.add(1,N/2 - N + p[i],1);
            }else{
                incline.add(p[i]+1,p[i] + N/2,1);
            }   
        }
        // for (int j = 0;j<N;j++){
        //     cout << incline.sum(j+1,j+1);
        // }
    }

    ll ans = now_cost;
    for (ll i=0;i<N;i++){
        ans = min(ans,now_cost + (ll)incline.sum(i+1,i+1));
        now_cost += (ll)incline.sum(i+1,i+1);
    }
    cout << ans << endl;
}