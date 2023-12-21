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

pair<int,int> get_point(int n, int H,int W){
    return make_pair(n/W,n%W);
}

bool bfs(int start,vector<string> graph,string S,int H, int W){
    int N = graph.size();
    map<pair<int,int>,bool> visited;
    queue<pair<int,int>> que;
    char s = graph[0][0];
    if (s!= S[0]) return false;
    int l = S.size();
    visited[make_pair(start,0)] = true;
    que.push(make_pair(start,0));
    while (!que.empty()){
        auto p = que.front();
        que.pop();
        int u = p.first;
        int index = p.second;
        auto point = get_point(u,H,W);
        int h = point.first;
        int w = point.second;
        vector<int> h_array = {h,h,h-1,h+1};
        vector<int> w_array = {w-1,w+1,w,w};
        rep(i,4){
            int now_h = h_array[i];
            int now_w = w_array[i];
            if (0<= now_h & now_h < H & 0<= now_w & now_w < W){
                if (graph[now_h][now_w] == S[(index+1)%l]){
                    if (!visited[make_pair(now_h*W + now_w,(index+1)%l)]){
                        visited[make_pair(now_h*W + now_w,(index+1)%l)] = true;
                        que.push(make_pair(now_h*W + now_w,(index+1)%l));
                    }
                }
            }
        }
    }
    bool ans = false;
    rep(i,S.size()){
        ans |= visited[make_pair(H*W-1,i)];
    }
    return ans;
}

int main(){
    int H,W;cin >> H >> W;
    vector<string> grid(H);
    rep(i,H) cin >> grid[i];
    string S = "snuke";
    if (bfs(0,grid,S,H,W)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

}