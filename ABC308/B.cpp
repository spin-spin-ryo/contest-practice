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
    int N,M;cin >> N >> M;
    vector<string> eat(N);
    rep(i,N) cin >> eat[i];
    vector<string> name(M);
    vector<int> price(M);
    rep(i,M) cin >> name[i];
    int p0; cin >> p0;
    rep(i,M) cin >> price[i];
    int sum = 0;
    rep(i,N){
        bool done = false;
        rep(j,M){
            if (name[j] == eat[i]){
                sum += price[j];
                done = true;
                continue;
            }
        }
        if (!done){
            sum+= p0;
        }
    }
    cout << sum << endl;
}