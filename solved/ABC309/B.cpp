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

int main(){
    int N;cin >> N;
    vector<string> S(N);
    rep(i,N) cin >> S[i];
    rep(i,N){
        rep(j,N){
            if (i==0 & j == 0){
                cout << S[i+1][j];
                continue;
            }
            if(i==0 & j == N-1){
                cout << S[i][j-1] << endl;
                continue;
            }
            if (i== N-1 & j == 0){
                cout << S[i][j+1];
                continue;
            }
            if (i==N-1 & j == N-1){
                cout << S[i-1][j] << endl;
                continue;
            }
            if (i== 0){
                cout << S[i][j-1];
                continue;
            }
            if (i == N-1){
                cout << S[i][j+1];
                continue;
            }
            if (j== 0){
                cout << S[i+1][j];
                continue;
            }
            if (j == N-1){
                cout << S[i-1][j] << endl;
                continue;
            }
            cout << S[i][j];
        }
    }
}