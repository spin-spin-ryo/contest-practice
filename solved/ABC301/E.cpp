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


vector<vector<ll>> bfs(pair<int,int> start,vector<string> A){
    int H = A.size();
    int W = A[0].size();
    queue<pair<int,int>> que;
    vector<vector<bool>> visited(H,vector<bool> (W,false));
    vector<vector<ll>> dis(H,vector<ll> (W,INF));
    que.push(start);
    visited[start.first][start.second] = true;
    dis[start.first][start.second] = 0;
    while (!que.empty()){
        auto p = que.front();
        que.pop();
        int h = p.first;
        int w = p.second;
        vector<int> row = {h,h,h-1,h+1};
        vector<int> col = {w-1,w+1,w,w};
        rep(i,4){
            int u = row[i];
            int v = col[i];
            if (u<0 | H <= u | v <0 | W<= v){
                continue;
            }
            if (!visited[u][v] & A[u][v]!= '#'){
                dis[u][v] = dis[h][w] +1;
                visited[u][v] = true;
                que.push(make_pair(u,v));
            }
        }
    }
    return dis;
}

int main(){
    int H,W,T;cin >> H >> W >> T;
    vector<string> A(H);
    rep(i,H){
        cin >> A[i];
    }

    vector<pair<int,int>> sweet;
    pair<int,int> start;
    pair<int,int> goal;
    rep(h,H){
        rep(w,W){
            if (A[h][w] == 'S'){
                start = make_pair(h,w);
            }
            if (A[h][w] == 'G'){
                goal = make_pair(h,w);
            }
            if (A[h][w] == 'o'){
                sweet.push_back(make_pair(h,w));
            }
        }
    }

    int n = 2 + sweet.size();
    vector<vector<int>> dis(n);
    
    vector<vector<ll>> tmp_dis;
    tmp_dis = bfs(start,A);
    
    dis[0].push_back(tmp_dis[start.first][start.second]);
    rep(i,sweet.size()){
        dis[0].push_back(tmp_dis[sweet[i].first][sweet[i].second]);
    }
    dis[0].push_back(tmp_dis[goal.first][goal.second]);

    rep(i,sweet.size()){
        tmp_dis = bfs(sweet[i],A);
        dis[i+1].push_back(tmp_dis[start.first][start.second]);
        rep(j,sweet.size()){
            dis[i+1].push_back(tmp_dis[sweet[j].first][sweet[j].second]);
        }
        dis[i+1].push_back(tmp_dis[goal.first][goal.second]);
    }

    tmp_dis = bfs(goal,A);
    dis[n-1].push_back(tmp_dis[start.first][start.second]);
    rep(i,sweet.size()){
        dis[n-1].push_back(tmp_dis[sweet[i].first][sweet[i].second]);
    }
    dis[n-1].push_back(tmp_dis[goal.first][goal.second]);

    vector<vector<ll>> tour((1<<(n-2)),vector<ll>(n-1,INF));
    tour[0][0] = 0;
    for (ll x = 0;x<(1<<(n-2));x++){
        for (ll m = 0;m<n-1;m++){
            for (ll r =0;r<n-2;r++){
                 
                if ( ((x >> r)&1) == 0){
                    tour[x + (1<<r)][r+1] = min(tour[x][m] + dis[m][r+1],tour[x + (1<<r)][r+1]);
                }
            }
        }
    }

    ll count = -1;
    for (ll x =0;x<1<<(n-2);x++){
        for (ll m=0;m<n-1;m++){
            ll now = 0;
            if (tour[x][m] + dis[m][n-1] <= T){
                for (ll r =0;(x>>r)>0;r++){
                    if ((x>>r)&1){
                        now ++;
                    }
                }
                count = max(now,count);
            }
        }
    }
    cout << count << endl;
    return 0;
}