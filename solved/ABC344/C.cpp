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
    int n,m,l;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    cin >> m;
    vector<int> b(m);
    rep(i,m) cin >> b[i];
    cin >> l;
    vector<int> c(l);
    rep(i,l) cin >> c[i];
    int q; cin >> q;
    vector<int> x(q);
    rep(i,q){
        cin >> x[i];
    }
    map<int,int> count;
    rep(i,n){
        rep(j,m){
            rep(k,l){
                count[a[i] + b[j] + c[k]]++;
            }
        }
    }
    rep(i,q){
        auto itr = count.find(x[i]);
        if (itr != count.end()){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }

}