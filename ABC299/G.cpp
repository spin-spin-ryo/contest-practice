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

using namespace std;
using ll = long long;
#define mod 998244353
#define INF 1e+16
#define rep(i, x) for(int i = 0; i < (x); i++)

int main(){
    ll N,M;cin >> N >> M;
    vector<ll> counter(M+1,0);
    vector<ll> A(N);
    rep(i,N){
        cin >> A[i];
        counter[A[i]]++;
    }
    vector<ll> used(M+1,0);
    vector<ll> ans;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> que;
    int now_index = 0;
    rep(i,N){
        que.push(make_pair(A[i],i));
        counter[A[i]]--;
        if (counter[A[i]] == 0 & used[A[i]] == 0){
            while (!que.empty()){
                auto p = que.top();
                que.pop();
                ll v = p.first;
                ll index = p.second;
                if (now_index <= index & used[v] == 0){
                    ans.push_back(v);
                    now_index = index;
                    used[v] = 1;
                    if (v==A[i]){
                        break;
                    }
                }
            }
        }
    }
    rep(i,M){
        cout << ans[i] << " ";
    }
    cout << endl;
    
}