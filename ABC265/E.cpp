#include<iostream>
#include<vector>
#include <tuple>
#include <string>
#include <algorithm>
#include <stack>
#include <utility>
#include <queue>
#include <map>



using namespace std;
using ll = long long;
#define mod 998244353
using  vector2d = vector<vector<int> >;

int main(){
    int N,M;cin >> N >> M;
    ll A,B,C,D,E,F; cin >> A >> B >> C >> D >> E >> F;
    vector<ll> X(M);
    vector<ll> Y(M);
    for (int i=0;i<M;i++){
        cin >> X[i] >> Y[i];
    }

    vector<pair<ll,ll> >index2pair;
    map<pair<ll,ll>, int> mp;
    int index = 0;
    for (ll i=0;i<N+1;i++){
        for (ll j = 0;j<N + 1 -i;j++){
            for (ll k=0;k<N+1 -i -j;k++){
                ll x = A*i + C*j + E*k;
                ll y = B*i + D*j + F*k;
                auto itr = mp.find(make_pair(x,y));
                if (itr==mp.end()){
                    index2pair.push_back(make_pair(x,y));
                    mp.insert(make_pair(make_pair(x,y),index));
                    index++;
                }
            }
        }
    }

    for (int i=0;i<M;i++){
        ll x = X[i];
        ll y = Y[i];
        auto itr = mp.find(make_pair(x,y));
        if (itr==mp.end()){
            index2pair.push_back(make_pair(x,y));
            mp.insert(make_pair(make_pair(x,y),index));
            index++;
        }
    }

    vector<ll> dp(index2pair.size());
    dp[0] = 1;
    for (int n=0;n<N;n++){
        vector<ll> new_dp(index2pair.size());
        for (int j=0;j<dp.size();j++){
            pair<ll,ll> p = index2pair[j];
            ll x = p.first;
            ll y = p.second;

            ll next_x,next_y;
            int next_index;
            next_x = x + A;
            next_y = y + B;
            next_index = mp[make_pair(next_x,next_y)];
            new_dp[next_index] += dp[j];
            new_dp[next_index] %= mod;

            next_x = x + C;
            next_y = y + D;
            next_index = mp[make_pair(next_x,next_y)];
            new_dp[next_index] += dp[j];
            new_dp[next_index] %= mod;

            next_x = x + E;
            next_y = y + F;
            next_index = mp[make_pair(next_x,next_y)];
            new_dp[next_index] += dp[j];
            new_dp[next_index] %= mod;
        }

        for (int i=0;i<M;i++){
            index = mp[make_pair(X[i],Y[i])];
            new_dp[index] = 0;
        }
        dp = new_dp;
    }

    ll ans = 0;
    for (int i=0;i<dp.size();i++){
        ans += dp[i];
        ans %= mod;
    }
    cout << dp.size() << endl;

    cout << ans << endl;
}