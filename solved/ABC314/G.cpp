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
    ll N,M,H; cin >> N >> M >> H;
    vector<ll> sum_type(M,0);
    vector<pair<ll,ll>> monsters(N);
    set<pair<ll,ll>> nonused;
    set<pair<ll,ll>> used;
    ll now_ans = N;
    vector<bool> used_flag(M,true);
    rep(i,N){
        ll A,B; cin >> A >> B;
        B--;
        monsters[i] = make_pair(A,B);
        sum_type[B] += A;
    }
    rep(i,M){
        used.insert(make_pair(sum_type[i],i));
    }
    ll damage = 0;
    vector<ll> ans(M+1,0);
    for (ll k = M;k>=0;k--){
        
        if (used.size() == k){
            if (damage <= H){
                ans[k] = now_ans;
            }
        }else{
            auto itr = used.begin();
            ll type = (*itr).second;
            ll now_damage = (*itr).first;
            used.erase(itr);
            used_flag[type] = false;
            damage += now_damage;
            nonused.insert(make_pair(now_damage,type));
            if (damage < H){
                ans[k] = now_ans;
            }else{
                while (damage >= H){
                    now_ans --;
                    // cout << now_ans << endl;
                    ll remove_type = monsters[now_ans].second;
                    ll remove_damage = monsters[now_ans].first;
                    if (used_flag[remove_type]){
                        auto itr = used.lower_bound(make_pair(sum_type[remove_type],remove_type));
                        sum_type[remove_type] -= remove_damage;
                        used.erase(itr);
                        used.insert(make_pair(sum_type[remove_type],remove_type));
                    }else{
                        auto itr = nonused.lower_bound(make_pair(sum_type[remove_type],remove_type));
                        sum_type[remove_type] -= remove_damage;
                        nonused.erase(itr);
                        nonused.insert(make_pair(sum_type[remove_type],remove_type));
                        damage -= remove_damage;
                    }
                    // 交換が起きるか確認
                    if (used.size() != 0 & nonused.size() != 0){
                        auto itr_upper = used.begin();
                        auto itr_lower = nonused.end();
                        itr_lower --;
                        ll damage1 = (*itr_upper).first;
                        ll damage2 = (*itr_lower).first;
                        if (damage1 < damage2){
                            ll upper_type = (*itr_upper).second;
                            ll lower_type = (*itr_lower).second;
                            used.erase(itr_upper);
                            nonused.erase(itr_lower);

                            used_flag[upper_type] = false;
                            used_flag[lower_type] = true;
                            used.insert(make_pair(damage2,lower_type));
                            nonused.insert(make_pair(damage1,upper_type));
                            damage += damage1 - damage2;
                        }
                    }
                
                }
                ans[k] = now_ans;
            }
        }


    }
    rep(i,M+1){
        cout << ans[i] << " ";
    }
    cout << endl;
    
}