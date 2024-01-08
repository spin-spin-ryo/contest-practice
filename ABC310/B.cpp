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
    int N,M;cin >> N >> M;
    vector<int> P(N);
    vector<vector<int>> function(N,vector<int>(M,0));
    rep(i,N){
        cin >> P[i];
        int c; cin >> c;
        int f;
        rep(j,c){
            cin >> f;
            f--;
            function[i][f] = 1;
        }
    }
    rep(i,N){
        for (int j = i+1;j<N;j++){
            bool ok = true;
            int index1;
            int index2;
            if (P[i] <= P[j]){
                index1 = i;
                index2 = j;
            }else{
                index1 = j;
                index2 = i;
            }
            int sum1=0;
            int sum2 = 0;
            rep(k,M){
                if (function[index2][k] == 1){
                    if (function[index1][k]!= 1){
                        ok = false;
                        continue;
                    }
                }
                sum1 += function[index1][k];
                sum2 += function[index2][k];
            }
            if (!ok) continue;

            if (P[index1] < P[index2] | sum1 > sum2){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}