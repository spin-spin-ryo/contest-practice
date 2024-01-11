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
#define INF 1e+16
using  vector2d = vector<vector<ll> >;

ll dfs(ll i, ll j, ll now, vector<vector<ll> >a){
    ll N = a.size();
    now ^=a[i][j];
    if (i == N-1 & j == N-1){
        if (now == 0){
            return 1;
        }else{
            return 0;
        }
    }
    if (i<N-1 & j<N-1){
        return dfs(i+1,j,now,a) + dfs(i,j+1,now,a);
    }
    if (j==N-1){
        return dfs(i+1,j,now,a);
    }else{
        return dfs(i,j+1,now,a);
    }
}

void dfs1(ll i, ll j, ll now, vector<vector<ll> >a, map<tuple<int,int,ll>, ll> memo, ll depth){
    ll N = a.size();
    now ^=a[i][j];
    if (depth == 0){
        memo[make_tuple(i,j,now)] += 1;
        return;
    }
    
    if (i<N-1 & j<N-1){
        dfs1(i+1,j,now,a,memo,depth-1);
        dfs1(i,j+1,now,a,memo,depth-1);
        return;
    }
    if (j==N-1){
        dfs1(i+1,j,now,a,memo,depth-1);
        return;
    }else{
        dfs1(i,j+1,now,a,memo,depth-1);
        return;
    }
}

void dfs2(ll i, ll j, ll now, vector<vector<ll> >a, map<tuple<int,int,ll>, ll> memo, ll depth){
    ll N = a.size();
    now ^=a[i][j];
    if (depth == 0){
        memo[make_tuple(i,j,now)] += 1;
        return;
    }
   
    
    if (i>0 & j>0){
        dfs2(i-1,j,now,a,memo,depth-1);
        dfs2(i,j-1,now,a,memo,depth-1);
        return;
    }
    if (j==0){
        dfs2(i-1,j,now,a,memo,depth-1);
        return;
    }else{
        dfs2(i,j-1,now,a,memo,depth-1);
        return;
    }
}


int main(){
    ll N;cin >> N;
    int ans = 0;
    vector<vector<ll> > a(N,vector<ll> (N));
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cin >> a[i][j];
        }
    }
    if (N<=10){
        cout << dfs(0,0,0,a) << endl;
    }else{
        map<tuple<int,int,ll>, ll> memo1;
        map<tuple<int,int,ll>, ll>  memo2;
        dfs1(0,0,0,a,memo1,9);
        dfs2(N-1,N-1,0,a,memo2,2*N-2-9);
        auto itr = memo1.begin();
        
        while (itr!= memo1.end()){
            tuple<int,int,ll> p = (*itr).first;
            ll n = (*itr).second;
            ans += n*memo2[p];
            itr++;
        }
        cout << ans << endl;
    }
    return 0;
}