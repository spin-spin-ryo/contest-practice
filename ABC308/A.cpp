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
    vector<int> S(8);
    rep(i,8) cin >> S[i];
    bool flag = true;
    rep(i,8){
        if (i<7){
            if (S[i] > S[i+1]) flag = false;
        }
        if (S[i] < 100 | 675 < S[i]) flag = false;
        if (S[i]%25 !=0 ) flag = false;
    }
    if (flag) cout << "Yes"<< endl;
    else cout << "No" << endl;
}