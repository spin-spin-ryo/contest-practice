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
    int N,M; cin >> N >> M;
    vector<long double> cost(N);
    vector<vector<int>> S(N);
    rep(i,N){
        cin >> cost[i];
        int P;cin >> P;
        int s;
        rep(j,P){
            cin >> s;
            S[i].push_back(s);
        }
    }
    vector<long double> f(M+1,0);
    rep(m,M){
        long double p = 10000000;
        rep(n,N){
            long double c = cost[n];
            long double s = S[n].size();
            long double coef = 1;
            rep(p,S[n].size()){
                if (S[n][p] == 0){
                    coef -= 1/s;
                }else{
                    c += f[max(0,m+1 - S[n][p])]/s;    
                }
            }
            p = min(p,c/coef);
        }
        f[m+1] = p;
    }
    cout << setprecision(20)<<f[M] << endl;
}