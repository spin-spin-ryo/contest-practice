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

using namespace std;
using ll = long long;
#define mod 998244353
#define INF 1e+16


int main(){
    ll N,Q;cin >> N >> Q;
    vector<ll> A(N);
    for (ll i=0;i<N;i++){
        cin >> A[i];
    }
    vector<ll> L(Q);
    vector<ll> R(Q);
    ll n = sqrt(Q);
    ll block_length = N/n;
    if (N%n != 0){
        n++;
    }

    if (block_length == 0){
        block_length = N;
        n = 1;
    }
    vector<vector<pair<ll,ll>>> G(n);
    for (ll i=0;i<Q;i++){
        cin >> L[i] >> R[i];
        ll block_num = (L[i]-1)/block_length;
        G[block_num].push_back(make_pair(R[i],L[i]));
    }
    for (ll i=0;i<n;i++){
        sort(G[i].begin(),G[i].end());
    }
    ll now_ans = -1;
    map<pair<ll,ll>,ll> ans;
    vector<ll> counter(200100,0);
    ll now_l,now_r;
    for (ll i=0;i<n;i++){
        for (ll j=0;j<G[i].size();j++){
            pair<ll,ll> p = G[i][j];
            ll r,l;
            r = p.first;
            l = p.second;
            r--;l--;
            if (now_ans == -1){
                for (ll index = l;index <= r;index++){
                    counter[A[index]] ++ ;
                }
                now_ans = 0;
                for (ll index = 0;index < counter.size();index++){
                    ll count = counter[index];
                    now_ans += count*(count-1)*(count-2)/6;
                }
                ans.insert(make_pair(make_pair(l,r),now_ans));
            }else{
                if (now_l < l){
                    while (now_l != l){
                        counter[A[now_l]]--;
                        ll count = counter[A[now_l]];
                        now_ans = now_ans - count*(count-1)*(count+1)/6 +count*(count-1)*(count-2)/6;
                        now_l ++;
                    }
                }else{
                    while (now_l != l){
                        now_l -- ;
                        counter[A[now_l]]++;
                        ll count = counter[A[now_l]];
                        now_ans = now_ans -(count-1)*(count-2)*(count-3)/6 + count*(count-1)*(count-2)/6;
                    }
                }

                if (now_r < r){
                    while (now_r != r){
                        now_r ++;
                        counter[A[now_r]]++;
                        ll count = counter[A[now_r]];
                        now_ans = now_ans - (count-1)*(count-2)*(count-3)/6 +count*(count-1)*(count-2)/6;
                    }
                }else{
                    while (now_r != r){
                        counter[A[now_r]]--;
                        ll count = counter[A[now_r]];
                        now_ans = now_ans - count*(count-1)*(count+1)/6 +count*(count-1)*(count-2)/6;
                        now_r -- ;
                    }
                }
                ans.insert(make_pair(make_pair(l,r),now_ans));
            }
            now_l = l;
            now_r = r;
        }
    }
    for (ll i=0;i<Q;i++){
        cout << ans[make_pair(L[i]-1,R[i]-1)] << endl;
    }

}