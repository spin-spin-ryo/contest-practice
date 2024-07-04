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
    string s; cin >> s;
    bool flag = true;
    rep(i,s.size()){
        if (i==0){
            flag &= (s[i] == '<');
        }else if (i == s.size() -1){
            flag &= (s[i] == '>');
        }else{
            flag &= (s[i] == '=');
        }
    }
    if (flag){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}