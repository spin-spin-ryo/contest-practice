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
using  vector2d = vector<vector<ll> >;

bool check_element(vector<vector<ll>> &A, ll i, ll j){
    ll H = A.size();
    ll W = A[0].size();
    bool check_flag = false;
    vector<pair<ll,ll>> surround = {make_pair(i-1,j),make_pair(i,j-1),make_pair(i+1,j),make_pair(i,j+1)};
    for (auto p:surround){
        if (0<= p.first & p.first < H){
            if (0<= p.second & p.second < W){
                if (A[i][j] == A[p.first][p.second]){
                    check_flag = true;
                }
            }
        }
    }
    return check_flag;
}

bool check_isolate(vector<vector<ll>> &A,ll h, ll h_label, ll now_label){
    // h 行目の孤立をチェック
    ll W = A[0].size();
    ll H = A.size();
    if (h == 0){
        if (h_label == 2 |h_label == 3){
            for (ll i=0;i<W;i++){
                A[0][i] = 1 - A[0][i]; 
            }
        }
        if (now_label == 2 | now_label == 3){
            for (ll i=0;i<W;i++){
                A[h+1][i] = 1 - A[h+1][i]; 
            }
        }
    }else{
        if (h_label == 1){
            for (ll i=0;i<W;i++){
                A[h-1][i] = 1 - A[h-1][i]; 
            }
        }
        if (h_label == 2){
            for (ll i=0;i<W;i++){
                A[h][i] = 1 - A[h][i]; 
            }
        }
        if (h_label == 3){
            for (ll i=0;i<W;i++){
                A[h][i] = 1 - A[h][i]; 
                A[h-1][i] = 1 - A[h-1][i]; 
            }
        }
        if (now_label == 2 | now_label == 3){
            if (h<H-1){
                for (ll i=0;i<W;i++){
                    A[h+1][i] = 1 - A[h+1][i]; 
                }
            } 
   
        }

    }
    bool all_ok = true;
    for (ll i=0;i<W;i++){
        all_ok &= check_element(A,h,i);
    }
    if (h == 0){
        if (h_label == 2 | h_label == 3){
            for (ll i=0;i<W;i++){
                A[0][i] = 1 - A[0][i]; 
            }
        }
        if (now_label == 2 | now_label == 3){
            for (ll i=0;i<W;i++){
                A[h+1][i] = 1 - A[h+1][i]; 
            }
        }
    }else{
        if (h_label == 1){
            for (ll i=0;i<W;i++){
                A[h-1][i] = 1 - A[h-1][i]; 
            }
        }
        if (h_label == 2){
            for (ll i=0;i<W;i++){
                A[h][i] = 1 - A[h][i]; 
            }
        }
        if (h_label == 3){
            for (ll i=0;i<W;i++){
                A[h][i] = 1 - A[h][i]; 
                A[h-1][i] = 1 - A[h-1][i]; 
            }
        }
        if (now_label == 2 | now_label == 3){
            if (h<H-1){
                for (ll i=0;i<W;i++){
                    A[h+1][i] = 1 - A[h+1][i]; 
                }
            } 
        }

    }
    return all_ok;
}


int main(){
    ll H,W;cin >> H >> W;
    vector<vector<ll> > A(H,vector<ll>(W));
    for (ll i=0;i<H;i++){
        for (ll j=0;j<W;j++){
            cin >> A[i][j];
        }
    }

    vector<vector<ll>> dp(H,vector<ll>(4,INF));
    dp[0][0] = 0; //00
    dp[0][1] = 0; //01
    dp[0][2] = 1; //10
    dp[0][3] = 1; //11

    for (ll h=1;h<H;h++){
        // 0のチェック dp[h-1][0] とdp[h-1][1]を調べる
    
            if (check_isolate(A,h-1,0,0)){
                dp[h][0] = min(dp[h][0],dp[h-1][0]);
            }
            if (check_isolate(A,h-1,1,0)){
                dp[h][0] = min(dp[h][0],dp[h-1][1]);
            }
            if (check_isolate(A,h-1,2,1)){
                dp[h][1] = min(dp[h][1],dp[h-1][2]);
            }
            if (check_isolate(A,h-1,3,1)){
                dp[h][1] = min(dp[h][1],dp[h-1][3]);
            }
            if (check_isolate(A,h-1,0,2)){
                dp[h][2] = min(dp[h][2],dp[h-1][0]+1);
            }
            if (check_isolate(A,h-1,1,2)){
                dp[h][2] = min(dp[h][2],dp[h-1][1]+1);
            }
            if (check_isolate(A,h-1,2,3)){
                dp[h][3] = min(dp[h][3],dp[h-1][2]+1);
            }
            if (check_isolate(A,h-1,3,3)){
                dp[h][3] = min(dp[h][3],dp[h-1][3]+1);
            }
    } 
    ll ans = INF;
    for (int i=0;i<4;i++){
        if (check_isolate(A,H-1,i,0)){
            ans = min(ans,dp[H-1][i]);
        }
        
    }
    if (ans >= INF){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
}