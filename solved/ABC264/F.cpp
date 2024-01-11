#include<iostream>
#include<vector>
#include <tuple>
#include <string>
#include <algorithm>
#include <stack>
#include <utility>
#include <queue>



using namespace std;
using ll = long long;
#define mod 998244353
#define INF 1e+16
using  vector2d = vector<vector<int> >;

char changecolor(char s){
    if (s=='0'){
        return '1';
    }else{
        return '0';
    }
}

int main(){
    ll H,W;cin >> H >> W;
    vector<ll> R(H);
    vector<ll> C(W);
    for (int i=0;i<H;i++) cin >> R[i];
    for (int i=0;i<W;i++) cin >> C[i];

    vector<string> A(H);
    for (int i=0;i<H;i++){        
        cin >> A[i];
    }

   
    //何も買えない時
    vector<vector<vector<ll> > > dp(H,vector<vector<ll> >(W,vector<ll>(4,INF)));

    dp[0][0][0] = 0;
    dp[0][0][1] = R[0];
    dp[0][0][2] = C[0];
    dp[0][0][3] = R[0] + C[0];
    // 0 : non change 1 :row change 2: col change 3 : both
    char nowcolor = A[0][0];
    for (int i=0;i<H;i++){
        for (int j=0;j<W;j++){
            if (i+1 < H){
                if (A[i+1][j] != A[i][j]){
                    dp[i+1][j][0] = min(dp[i+1][j][0],dp[i][j][1]);
                    dp[i+1][j][1] = min(dp[i+1][j][1],dp[i][j][0] + R[i+1]);
                    dp[i+1][j][2] = min(dp[i+1][j][2],dp[i][j][3]);
                    dp[i+1][j][3] = min(dp[i+1][j][3],dp[i][j][2] + R[i+1]);
                }else{
                    dp[i+1][j][0] = min(dp[i+1][j][0],dp[i][j][0]);
                    dp[i+1][j][1] = min(dp[i+1][j][1],dp[i][j][1] + R[i+1]);
                    dp[i+1][j][2] = min(dp[i+1][j][2],dp[i][j][2]);
                    dp[i+1][j][3] = min(dp[i+1][j][3],dp[i][j][3] + R[i+1]);
                }
            }
            if (j+1 < W){
                if (A[i][j+1] != A[i][j]){
                    dp[i][j+1][0] = min(dp[i][j+1][0],dp[i][j][2]);
                    dp[i][j+1][1] = min(dp[i][j+1][1],dp[i][j][3]);
                    dp[i][j+1][2] = min(dp[i][j+1][2],dp[i][j][0] + C[j+1]);
                    dp[i][j+1][3] = min(dp[i][j+1][3],dp[i][j][1] + C[j+1]);
                }else{
                    dp[i][j+1][0] = min(dp[i][j+1][0],dp[i][j][0]);
                    dp[i][j+1][1] = min(dp[i][j+1][1],dp[i][j][1]);
                    dp[i][j+1][2] = min(dp[i][j+1][2],dp[i][j][2] + C[j+1]);
                    dp[i][j+1][3] = min(dp[i][j+1][3],dp[i][j][3] + C[j+1]);
                }
            }
        }
    }

    ll ans = INF;
    for (int i=0;i<4;i++){
        ans = min(ans,dp[H-1][W-1][i]);
    }
    cout << ans << endl;
}