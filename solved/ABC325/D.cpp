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
    ll N; cin >> N;
    map<ll,vector<ll>> goods;
    priority_queue<ll,vector<ll>,greater<ll>> que;
    vector<ll> index;
    rep(i,N){
        ll T,D; cin >> T >> D;
        goods[T].push_back(T+D);
        index.push_back(T);
    }

    sort(index.begin(),index.end());

    index.erase(unique(index.begin(), index.end()), index.end());
    ll now = 0;
    int ans = 0;
    rep(i,index.size()){
        now = index[i];
        rep(j,goods[index[i]].size()){
            que.push(goods[index[i]][j]);
        }
        if (i < index.size() -1){
            while(!que.empty()){
                if (now < index[i+1]){
                    if (now <= que.top()){
                        // cout << now <<  " " << que.top()<< endl;
                        now +=1;
                        ans ++;
                        que.pop();
                    }else{
                        que.pop();
                    }
                }else{
                    break;
                }
            }
        }else{
            while(!que.empty()){
                if (now <= que.top()){
                    // cout << "ok"<<now <<  " " << que.top()<< endl;
                    now +=1;
                    ans ++;
                    que.pop();
                }else{
                    que.pop();
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}