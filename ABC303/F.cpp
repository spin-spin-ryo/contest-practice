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

using namespace std;
using ll = long long;
#define mod 998244353
#define rep(i, x) for(ll i = 0; i < (x); i++)

using  vector2d = vector<vector<ll> >;


// 点変更、区間最小値, 0-indexed
// update a[i]
// RMQ [a,b)
template <typename T>
struct RMQ{
    const T INF = numeric_limits<T>::max();
    ll n;
    vector<T> dat;
    RMQ(ll n_):n(), dat(n_*4 ,INF){
        ll x = 1;
        while (n_>x){
            x*= 2;
        }
        n = x;
    }

    void update(ll i, T x){
        i += n-1;
        dat[i] = x;
        while (i>0){
            i = (i-1)/2;
            dat[i] = min(dat[2*i +1],dat[i*2+2]);
        }
    }

    T query(ll a, ll b){
        return query_sub(a,b,0,0,n);
    }

    T query_sub(ll a, ll b, ll k, ll l, ll r){
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


ll damage(ll turn, vector<pair<ll,ll>> magic, vector<ll> order, vector<ll> last_turns){
    ll h = 0;
    rep(i,last_turns.size()){
        ll index = order[i];
        ll d = magic[index].first;
        ll t = magic[index].second;
        if (turn >= last_turns[i]){
            ll start;
            ll end = last_turns[i];
            
            if (i==0){
                start = turn;
            }else{
                start = last_turns[i-1] -1;
            }
            cout << start << " " << end << " " << t << endl;
            if (start >= t){
                h += d*t*(start - t) + (t*(t+1) - end*(end -1))/2*d;
            }else{
                h += (start*(start+1) - end*(end -1))/2*d;
            }
        }
        // cout << h << endl;
    }
    return h;
}

int main(){
    ll N,H; cin >> N >> H;
    vector<pair<ll,ll>> magic(N);
    rep(i,N){
        ll t,d; cin >> t >> d;
        magic[i] = make_pair(d,t);
    }
    sort(magic.begin(),magic.end());

    set<pair<ll,ll>> s;
    RMQ<ll> solver(N);
    rep(i,N){
        ll t,d;
        d = magic[i].first;
        t = magic[i].second;
        solver.update(i,-t*d);
        s.insert(make_pair(t*d,-i));
    }

    vector<ll> order;
    ll l = 0;
    ll r = N;
    while (r-l > 0){
        ll m = - solver.query(l,r);
        auto itr = s.lower_bound(make_pair(m,-1000000));
        ll index = (*itr).second;
        index = - index;
        l = index+1;
        order.push_back(index);
    }
    vector<ll> last_turns;

    rep(i,order.size() -1){
        ll index1 = order[i];
        ll index2 = order[i+1];
        ll last_turn = magic[index2].first*magic[index2].second;
        last_turn = (last_turn%magic[index1].first == 0? last_turn/magic[index1].first:last_turn/magic[index1].first +1 );
        last_turns.push_back(last_turn);
    }
    last_turns.push_back(0);
    
    l = 0;
    r = 1000000;
    // cout << damage(6,magic,order,last_turns) << endl;
    while (r - l > 1){

        ll m = (l+r)/2;
        ll h = damage(m,magic,order,last_turns);
        cout << h << endl;
        if (h>=H){
            r = m;
        }else{
            l = m;
        }
    }
    cout << r << endl;
}