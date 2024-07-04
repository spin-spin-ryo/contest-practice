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
#include <unordered_map>

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
    int h,w; cin >> h >>w;
    vector<string> grid(h);
    rep(i,h) cin >> grid[i];
    pair<int,int> start;
    pair<int,int> goal;
    rep(i,h){
        rep(j,w){
            if (grid[i][j] == 'S'){
                start = {i,j};
            }else if (grid[i][j] == 'T'){
                goal = {i,j};
            }
        }
    }
    int n; cin >> n;
    vector<int> r(n);
    vector<int> c(n);
    vector<int> e(n);
    vector<vector<int>> energy(h,vector<int> (w,0));
    rep(i,n){
        cin >> r[i] >> c[i] >> e[i];
        r[i]--;c[i]--;
        energy[r[i]][c[i]] = e[i];
    }
    if (energy[start.first][start.second] ==0){
        cout << "No" << endl;
        return 0;
    }
    int N = n;
    int start_index,goal_index;
    if (energy[goal.first][goal.second] == 0){
        N++;
        r.push_back(goal.first);
        c.push_back(goal.second);
        e.push_back(0);
    }
    rep(i,N){
        if (r[i] == start.first & c[i] == start.second){
            start_index = i;
        }
        if (r[i] == goal.first & c[i] == goal.second){
            goal_index = i;
        }
    }

    vector<vector<int>> min_dis(N,vector<int>(N,10000000));
    rep(i,N){
        queue<pair<int,int>> que;
        que.push({r[i],c[i]});
        vector<vector<bool>> visited(h,vector<bool> (w,false));
        visited[r[i]][c[i]] = true;
        vector<vector<int>> dis(h,vector<int> (w,1000000));
        dis[r[i]][c[i]] = 0;
        while (!que.empty()){
            auto p = que.front();
            que.pop();
            int x,y;
            x= p.first;
            y = p.second;
            
            vector<pair<int,int>> arround = {{x+1,y},{x-1,y},{x,y+1},{x,y-1}};
            rep(i,4){
                auto next_p = arround[i];
                if (0 <= next_p.first & next_p.first < h){
                    if (0<= next_p.second & next_p.second < w){
                        if (!visited[next_p.first][next_p.second]){
                            if (grid[next_p.first][next_p.second] != '#'){
                                dis[next_p.first][next_p.second] = dis[x][y] + 1;
                                visited[next_p.first][next_p.second] = true;
                                que.push(next_p);
                            }
                        }
                    }
                }
            }
        }
        rep(j,N){
            min_dis[i][j] = dis[r[j]][c[j]];
        }
    }
    vector<vector<int>> graph(N,vector<int>(N,0));

    rep(i,N){
        rep(j,N){
            if (min_dis[i][j] <= e[i]){
                graph[i].push_back(j);
            }
        }
    }
    queue<int> que;
    que.push(start_index);
    vector<bool> visited(N,false);
    visited[start_index] = true;
    while (!que.empty()){
        int u = que.front();que.pop();
        for (int v:graph[u]){
            if (!visited[v]){
                que.push(v);
                visited[v] = true;
            }
        }
    }
    if (visited[goal_index]){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }



}