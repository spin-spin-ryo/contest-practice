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
#define rep(i, x) for(int i = 0; i < (x); i++)

using  vector2d = vector<vector<int> >;

template <typename T>
void print(vector<T> v){
    rep(i,v.size()){
        cout << v[i] << endl;
    }
    return;
}

int main(){
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>> > que;
    priority_queue<ll,vector<ll>,greater<ll>> wait;
    ll N,M; cin >> N >> M;
    vector<ll> T(M);
    vector<ll> S(M);
    vector<ll> W(M);
    rep(i,M){
        cin >> T[i] >> W[i] >> S[i];
    }
    vector<ll> ans(N,0);

    rep(i,N){
        wait.push(i);
    }
    ll now_time = 0;
    rep(i,M){
        now_time = T[i];
        while(!que.empty()){
            auto p = que.top();
            if (p.first <= now_time){
                que.pop();
                wait.push(p.second);
            }else{
                break;
            }
        }
        if (!wait.empty()){
            ll index = wait.top();
            wait.pop();
            ans[index] += W[i];
            que.push(make_pair(T[i] + S[i],index));
        }
    }

    rep(i,N){
        cout << ans[i] << endl;
    }
}