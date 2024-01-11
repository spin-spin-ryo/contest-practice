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
#include <cassert>

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

vector<vector<int>> get_accumulate_sum2d(vector<vector<int>> A){
    int H = A.size();
    int W = A[0].size();
    vector<vector<int>> s(H+1,vector<int>(W+1,0));
    rep(i,H){
        rep(j,W){
            s[i+1][j+1] = A[i][j] + s[i+1][j] + s[i][j+1] - s[i][j];
        }
    }

    return s;
}

// 0-indexedで [x1, x2) × [y1, y2)
// cout << s[x2][y2] - s[x1][y2] - s[x2][y1] + s[x1][y1] << endl;

