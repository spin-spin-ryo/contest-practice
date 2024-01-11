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
    map<string,int> counter;
    int N; cin >> N;
    rep(i,N){
        string S; cin >> S;
        string s = S;
        reverse(s.begin(), s.end());
        if (s < S){
            counter.insert(make_pair(s,1));
        }else{
            counter.insert(make_pair(S,1));
        }
    }
    int n = counter.size();
    cout << n << endl;
}