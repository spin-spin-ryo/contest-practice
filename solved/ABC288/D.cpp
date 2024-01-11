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
using  vector2d = vector<vector<int> >;

int main(){
    int N,K;cin >> N >> K;
    vector<int>x(N+1);
    vector<int>y(N);
    for (int i=0;i<N;i++){
        cin >> x[i];
    }
    for (int i=0;i<N-1;i++){
        y[i] = x[i+1] - x[i];
    }
    int l = N/K + 1;
    vector<vector<int>> z(K,vector<int>(l));
    for (int k=0;k<K;k++){
        z[k][0] = 0;
        z[k][1] = y[k];
        for (int i=2;i<l;i++){
            if (K*(i-1) + k < N) z[k][i] = y[K*(i-1) + k] + z[k][i-1];
        } 
    }

    int Q; cin >> Q;
    for (int i=0;i<Q;i++){
        int l,r;cin >> l >> r;
        l--;r--;
        bool flag = true;
        for (int k=0;k<K;k++){
            int min_index,max_index;
            if (l==0){
                min_index = 0;
            }else{
                min_index = (l-1)/K;
                if ((l-1)%K > k) min_index++;
            }
            max_index = r/K;
            if (r%K < k){
                max_index --;
            }

            int min_l = K*min_index + k;
            if ((l == 0) & (k == K-1)){
                min_l = -1;
                min_index = -1;
            }
            int max_r = K*max_index + k;
            if (min_l > r || max_r < l){
                continue;
            }
            // cout << min_l << " " << max_r << endl;
            // cout << min_index << " " << max_index << endl;
            if (min_l == l-1 & max_r == r){
                if (x[l] + z[k][max_index] - z[k][max(min_index+1,0)] -x[r] != 0){
                    // cout << x[l] + z[k][max_index+1] - z[k][max(min_index+1,0)] -x[r];
                    flag = false;
                    // cout << "ok" << endl;
                }
            }
            if (min_l == l-1 & max_r != r){
                if (x[l] + z[k][max_index+1] - z[k][min_index+1] != 0){
                    flag = false;
                    // cout << "ok";
                }
            }
            if (max_r == r & min_l != l-1){
                if (-x[r] + z[k][max_index] - z[k][min_index]!=0){
                    flag = false;
                    // cout << "ok";
                }
            }
            if (max_r != r & min_l != l-1){
                if (z[k][max_index+1] - z[k][min_index] != 0){
                    flag = false;
                    // cout << "ok";
                }
            }
        }
        if (flag){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    
    
    
}