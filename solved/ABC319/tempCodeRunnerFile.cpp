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

int main(){
    ll N;cin >> N;
    vector<vector<ll>> graph(N);
    vector<ll> t(N);
    vector<ll> s(N);
    vector<ll> g(N);
    ll count = 0;
    vector<pair<ll,ll>> medicine;
    rep(i,N-1){
        ll p;
        cin >> p >> t[i+1] >> s[i+1] >> g[i+1];
        p--;
        graph[p].push_back(i+1);
        if (t[i+1] ==2){
            count++;
            medicine.push_back(make_pair(i+1,g[i+1]));
        }
    }
    do {
        bool stop = false;
        vector<bool> visited(N,false);
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> que;
        ll strength = 1;
        int sum = 1;
        visited[0] = true;
        for (ll i=0;i<graph[0].size();i++){
            ll u = graph[0][i];
            if (t[u] == 1){
                que.push(make_pair(s[u],u));
            }else{
                visited[u] = true;
            } 
        }
        ll used = 0;
        while(sum != N){
            if (!que.empty()){
                auto p = que.top();
                ll m = p.first;
                ll v = p.second;
                if (m<= strength){
                    que.pop();
                    visited[v]=true;
                    sum++;
                    if (strength <= 1e+9){
                        strength += g[v];
                    }
                    
                    for (ll i=0;i<graph[v].size();i++){
                        ll u = graph[v][i];
                        if (t[u] == 1){
                            que.push(make_pair(s[u],u));
                        }else{
                            visited[u] = true;
                        } 
                    }
                }
            }else{
                if (used < count){
                    ll node = medicine[used].first;
                    ll rate = medicine[used].second;
                    if (visited[node]){
                        sum ++;
                        if (strength <= 10e+9){
                            strength *= rate;
                        }
                        for (ll i=0;i<graph[node].size();i++){
                            ll u = graph[node][i];
                            if (t[u] == 1){
                                que.push(make_pair(s[u],u));
                            }else{
                                visited[u] = true;
                            } 
                        }
                        used++;
                    }else{
                        stop=true;
                        break;
                    }
                }else{
                    stop=true;
                    break;
                }
            }
        }
        if (!stop){
            cout << "Yes" << endl;
            return 0;
        }
    } while (next_permutation(medicine.begin(), medicine.end()));
    cout << "No" << endl;
    return 0;
}
    