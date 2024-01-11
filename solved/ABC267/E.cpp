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

using namespace std;
using ll = long long;
#define mod 998244353
using  vector2d = vector<vector<ll> >;

int main(){
    ll N,M;cin >> N >> M;
    vector<ll> A(N);
    vector<ll> cost(N);
    for (ll i=0;i<N;i++){
        cin >> A[i];
    } 
    vector<vector<ll> > graph(N);
    ll u,v;
    for (ll i=0;i<M;i++){
        cin >> u >> v;
        u--;v--;
        graph[u].push_back(v);
        cost[u] += A[v];
        graph[v].push_back(u);
        cost[v] += A[u];
    }
    
    ll l = -1;
    ll r = 1e+16;
    

    while (r-l >1){
        ll count = N;
        ll m = (l+r)/2;
        queue<ll> que;
        vector<ll> now_cost(N);
        for (ll i=0;i<N;i++){
            now_cost[i] = cost[i];
            if (now_cost[i] <= m){
                que.push(i);
            }
        }

        while(!que.empty()){
            u = que.front();
            que.pop();
            count -- ;
            for (ll i=0;i<graph[u].size();i++){
                v = graph[u][i];
                if (now_cost[v]>m){
                    now_cost[v]-=A[u];
                    if (now_cost[v] <= m){
                        que.push(v);
                    }
                }
            }
        }

        if (count == 0){
            r = m;
        }else{
            l = m;
        }

        
    }
    cout << r << endl;


}