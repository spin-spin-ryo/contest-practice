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
#define INF 1e+16
#define rep(i, x) for(ll i = 0; i < (x); i++)

using  vector2d = vector<vector<ll> >;

template <typename T>
void prll(vector<T> v){
    rep(i,v.size()){
        cout << v[i] << endl;
    }
    return;
}

int main(){
    ll N,M;cin >> N >> M;
    vector<ll> free_can;
    vector<ll> nonfree_can;
    vector<ll> cutter;
    rep(i,N){
        ll T,X;cin >> T >> X;
        if (T == 0){
            free_can.push_back(X);
        }
        if (T== 1){
            nonfree_can.push_back(X);
        }
        if (T==2){
            cutter.push_back(X);
        }
    }
    sort(free_can.begin(),free_can.end());
    sort(nonfree_can.begin(),nonfree_can.end());
    sort(cutter.begin(),cutter.end());
    reverse(free_can.begin(),free_can.end());
    reverse(nonfree_can.begin(),nonfree_can.end());
    reverse(cutter.begin(),cutter.end());

    vector<ll> can_sum(1,0);
    rep(i,free_can.size()){
        can_sum.push_back(can_sum[i] + free_can[i]);
    }

    ll X = 0;
    vector<ll> noncan_sum(1,0);
    ll index = 0;
    ll index1 = 0;

    rep(i,(ll)nonfree_can.size() + (ll)cutter.size()){
        if (X == 0){
            if (index < cutter.size()){
                X = cutter[index];
                index ++;
                noncan_sum.push_back(noncan_sum[i]);
            }
            
        }else{
            if (index1 < nonfree_can.size()){
                X --;
                noncan_sum.push_back(noncan_sum[i] + nonfree_can[index1]);
                index1++;
            }
        }
    }
    
    ll ans = 0;
    rep(i,M+1){
        int use = i;
        int nonuse = M-i;
        use = min(use, (int)can_sum.size() -1);
        nonuse = min(nonuse, (int)noncan_sum.size() -1 );
        ans = max(ans, can_sum[use] + noncan_sum[nonuse]);

    }
    cout << ans << endl;
    

}