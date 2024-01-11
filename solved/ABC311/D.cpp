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

void dfs(int h, int w, vector<string> &S, int from, vector<vector<int>> &visited,vector<vector<bool>> &stop){
    visited[h][w] = 1;
    if (from == 0){
        stop[h][w] = true;
        if (S[h][w+1] == '.'){
            dfs(h,w+1,S,4,visited,stop);
        }
        if (S[h+1][w] == '.'){
            dfs(h+1,w,S,1,visited,stop);
        }
    }
    if (from == 1){
        // 上から
        if (S[h+1][w] == '#'){
            // 右と左に行く
            if (!stop[h][w]){
                stop[h][w] = true;
                if (S[h][w+1] == '.'){
                    dfs(h,w+1,S,4,visited,stop);
                }
                if (S[h][w-1] == '.'){
                    dfs(h,w-1,S,2,visited,stop);
                }
            }
            return;
            
        }else{
            dfs(h+1,w,S,from,visited,stop);
        }

    }
    if (from == 2){
        // 右から
        if (S[h][w-1] == '#'){
            // 上と下に行く
            if(!stop[h][w]){
                stop[h][w] = true;
                if (S[h+1][w] == '.'){
                    dfs(h+1,w,S,1,visited,stop);
                }
                if (S[h-1][w] == '.'){
                    dfs(h-1,w,S,3,visited,stop);
                }
            }
            
            
        }else{
            dfs(h,w-1,S,from,visited,stop);
        }

    }
    if (from == 3){
        // 下から
        if (S[h-1][w] == '#'){
            // 右と左に行く
            if(!stop[h][w]){
                stop[h][w] = true;
                if (S[h][w+1] == '.'){
                    dfs(h,w+1,S,4,visited,stop);
                }
                if (S[h][w-1] == '.'){
                    dfs(h,w-1,S,2,visited,stop);
                }
            }
            
            
        }else{
            dfs(h-1,w,S,from,visited,stop);
        }

    }
    if (from == 4){
        // 左から
        if (S[h][w+1] == '#'){
            // 上と下に行く
            if (!stop[h][w]){
                stop[h][w] = true;
                if (S[h+1][w] == '.'){
                    dfs(h+1,w,S,1,visited,stop);
                }
                if (S[h-1][w] == '.'){
                    dfs(h-1,w,S,3,visited,stop);
                }
            }
        }else{
            dfs(h,w+1,S,from,visited,stop);
        }

    }
}

int main(){
    int N,M;cin >> N >> M;
    vector<string> S(N);
    rep(i,N) cin >> S[i];
    vector<vector<int>> visited(N,vector<int>(M,0));
    vector<vector<bool>> stop(N,vector<bool>(M,false));
    dfs(1,1,S,0,visited,stop);
    int ans = 0;
    rep(i,N){
        rep(j,M){
            // cout << visited[i][j];
            ans += visited[i][j];
        }
        // cout << endl;
    }
    cout << ans << endl;
}