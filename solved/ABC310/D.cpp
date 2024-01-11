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

int N,T,M;
vector<int> teams;
vector<int> ng;

int dfs(int now){
    int ans = 0;
    if (now == N){
        if (teams.size() == T){
            return 1;
        }else{
            return 0;
        }
        
    }

    // 既存のチームに追加
    for (auto &team:teams){
        // ngがないか確認
        if ( (team & ng[now]) ==0){
            team += (1<<now);
            ans += dfs(now+1);
            team -= (1<<now);
        }
    }

    //　新しいチームを追加
    if (teams.size() < T){
        teams.emplace_back((1<<now));
        ans += dfs(now+1);
        teams.pop_back();
    } 
    
    return ans;
}

int main(){
    cin >> N >> T >> M;
    ng.resize(N,0);
    rep(i,M){
        int a,b; cin >> a >> b;
        a--;b--;
        ng[a] += (1<<b);
        ng[b] += (1<<a);
    }
    teams.reserve(T);
    cout << dfs(0) << endl;

}