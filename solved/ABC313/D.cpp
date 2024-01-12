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
    int N,K;cin >> N >> K;
    vector<int> A(N,-1);
    vector<int> results(N);
    rep(i,N-K+1){
        cout << "?" << " " << i+1 << " ";
        rep(j,K-1){
            cout << N-K + 2 + j << " ";
        }
        cout << endl;
        int T; cin >> T;
        results[i] = T;
    }
    rep(i,K-1){
        cout << "? 1 ";
        rep(j,K){
            if (N-K+1+j != N-K+i+2){
                cout << N-K+1+j << " ";
            }
        }
        cout << endl;
        int T; cin >> T;
        results[i+N-K+1] = T;
    }
    // 仮
    A[0] = 0;
    rep(i,N-K){
        A[i+1] = A[i] + results[i] + results[i+1];
        A[i+1]%= 2;
    }
    int sum = 0;
    sum += results[0];
    rep(i,K-1){
        sum += results[N-K+i+1];
        if (i==0){
            A[N-K+i+1] = A[N-K+i] + results[0] + results[i+N-K+1];
            A[N-K+i+1] %=2;
        }else{
            A[N-K+i+1] = A[N-K+i] + results[N-K+i] + results[i+N-K+1];
            A[N-K+i+1] %=2;
        }
    }
    cout << "! ";
    if (sum%2 == 0){
        rep(i,N){
            cout << A[i] << " ";
        }
        cout << endl;
    }else{
        rep(i,N){
            cout << (A[i]+1)%2 << " ";
        }
        cout << endl;
    }
    return 0;
}