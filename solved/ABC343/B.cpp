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
    int n;cin >> n;
    vector<vector<int>> a(n,vector<int>(n,0));
    rep(i,n){
        rep(j,n){
            cin >> a[i][j];
            if (a[i][j] == 1){
                cout << j + 1 << " ";
            }
        }
        cout << endl;
    }
}