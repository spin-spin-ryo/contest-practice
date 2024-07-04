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
    cin >> s;
    vector<int> counter(26,0);
    rep(i,s.size()){
        int index = s[i] - 'a';
        counter[index]++;
    }
    vector<int> two_zero_checker(101,0);
    rep(i,26){
        two_zero_checker[counter[i]] ++;
    }
    for(int i=1;i<101;i++){
        if (two_zero_checker[i] != 0 & two_zero_checker[i] != 2){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}