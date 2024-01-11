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

// 互換の最小値の求め方　サイクル検出みたいなもの
// 解説は直感的に思いつかなそうな量を考えているので厳しい。

int main(){
    ll N;cin >> N;
    vector<ll> A(N);
    vector<ll> count(4,0);
    rep(i,N){
        cin >> A[i];
        count[A[i]-1]++;
    }
    vector<ll> B(N,0);
    rep(i,N){
        ll num = 1;
        while (count[num -1] ==0 & num <= 4){
            num ++;
        }
        if (count[num-1]>0){
            B[i] =num;
            count[num-1]--;
        }
    }
    // rep(i,N) cout << B[i] << endl;

    vector<vector<int>> count_edge(4,vector<int>(4,0));
    rep(i,N){
        count_edge[A[i]-1][B[i]-1] ++;
    }
    int ans = 0;
    for (int i = 0;i<4;i++){
        for (int j =0;j<4;j++){
            if (i!= j){
                int count = min(count_edge[i][j],count_edge[j][i]);
                ans += count;
                count_edge[i][j] -= count;
                count_edge[j][i] -=count;
            }
        }
    }
    for (int i = 0;i<4;i++){
        for (int j =0;j<4;j++){
            for (int k=0;k<4;k++){
                if (i!= j & j!=k & i!=k){
                    int count = min(min(min(count_edge[i][j],count_edge[j][k]),count_edge[j][k]),count_edge[k][i]);
                    ans += 2*count;
                    count_edge[i][j] -= count;
                    count_edge[j][k] -= count;
                    count_edge[k][i] -= count;
                }
            }
        }
    }

    vector<int> v = {0,1, 2, 3};
    do {
        int i = v[0];
        int j = v[1];
        int k = v[2];
        int l = v[3]; 
        int count = min(min(min(min(count_edge[i][j],count_edge[j][k]),count_edge[j][k]),count_edge[k][l]),count_edge[l][i]);
        count_edge[i][j] -= count;
        count_edge[j][k] -= count;
        count_edge[k][l] -= count;
        count_edge[l][i] -= count;
        ans += 3*count;
    }while (std::next_permutation(v.begin(), v.end()));
    cout << ans << endl;
}

