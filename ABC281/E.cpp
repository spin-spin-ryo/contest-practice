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
using  vector2d = vector<vector<int> >;

//　BITを使わなくてもsetとpriority queueだけで行けそう

int main(){
    ll N,M,K;cin >> N >> M >> K;
    vector<ll> A(N);
    set<pair<ll,ll> > used;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > que;
    for (int i=0;i<N;i++){
        cin >> A[i];
     }
    ll sum = 0;
    for (int i=0;i<M;i++){
        que.push(make_pair(A[i],i));
    }

    for (int i=0;i<K;i++){
        used.insert(que.top());
        sum += que.top().first;
        que.pop();
    }
    

    for (int i=0;i<N-M+1;i++){
        cout << sum << " ";
        auto itr = used.find(make_pair(A[i],i));
        int count = 0;
        if (itr != used.end()){
            used.erase(itr);
            sum -= A[i];
        }else{
            count = 1;
        }

        pair<ll,ll> p = make_pair(A[i+M],i+M);
        if (count == 1){
            //あたらしいものがusedより大きいか確認
            auto itr1 = used.upper_bound(p);
            if (itr1 == used.end()){
                que.push(p);
            }else{
                auto max_itr = used.rbegin();
                que.push(*max_itr);
                sum -= (*max_itr).first;
                used.erase(*max_itr);
                
                used.insert(p);
                sum += p.first;
            }
        }else{
            que.push(p);
        }
        

        
        while (count < 1){
            pair<ll,ll> p = que.top();
            if (p.second > i){
                count ++ ;
                used.insert(p);
                sum += p.first;
            }
            que.pop();
        }
    }
    

    return 0;
}