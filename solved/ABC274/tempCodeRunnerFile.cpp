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

using namespace std;
using ll = long long;
using ld = long double;
#define mod 998244353
#define INF 1e+16
using  vector2d = vector<vector<int> >;

int main(){
    int N,M;cin >> N >> M;
    vector<int> nodes;
    vector<ld> X(N+M);
    vector<ld> Y(N+M);
    for (int i=0;i<N;i++){
        nodes.push_back(i);
        cin >> X[i] >> Y[i];
    }
    for (int i=0;i<M;i++){
        cin >> X[i+N] >> Y[i+N];
        nodes.push_back(N+i);
    }

    ld ans = INF;
    vector<vector<ld> > dp(1<<(N+M),vector<ld>(N+M+1,INF));
    dp[0][0] = 0;
    for (ll j =0;j<N+M;j++){
        dp[1<<j][j+1] = pow(pow(X[j],2) + pow(Y[j],2),0.5);
    }

    for (ll i=0;i<(1<<(N+M));i++){
        vector<int> next_v;
        vector<int> visited_v;
        ld treasure = 1;
        int count =  0;
        for (ll j=0;j<N+M;j++){
            if ((i>>j)&1){
               if (j<N){
                count ++;
               }else{
                treasure*=2;
               }
               visited_v.push_back(j);
            }else{
                next_v.push_back(j);
            }
        }
            

        if (count == N){
            for (int v=1;v<N+M+1;v++){
                
                ld dis =  pow(pow(X[v-1],2) + pow(Y[v-1],2),0.5);
                ans = min(ans,dp[i][v]+ dis/treasure);
            }
        }

        for (auto now_v:visited_v){
            for (auto v:next_v){
                ld dis = sqrt((X[now_v] - X[v])*(X[now_v] - X[v]) + (Y[now_v] - Y[v])*(Y[now_v] - Y[v]));
                dp[i + (1<<v)][v+1] = min(dp[i + (1<<v)][v+1],dp[i][now_v+1] + dis/treasure);
            }
        }
        
    }
    cout << setprecision(10) <<ans << endl;
}