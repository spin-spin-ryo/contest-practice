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
#include <unordered_map>

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
    string t; cin >> t;
    int index = 0;
    rep(i,s.size()){
        if (s[i] == tolower(t[index])){
            index ++;
            if (index == 3){
                break;
            }
        }
    }
    if (index == 3){
        cout << "Yes" << endl;
    }else if (index == 2 & t[2] == 'X'){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}