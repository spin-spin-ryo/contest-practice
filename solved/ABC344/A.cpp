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
    string s;
    string out;
    cin >> s;
    int flag =0;
    rep(i,s.size()){
        if (s[i] == '|'){
            flag ++;
        }else{
            if (flag%2 == 0){
                out += s[i];
            }
        }
    }
    cout << out << endl;
    
}