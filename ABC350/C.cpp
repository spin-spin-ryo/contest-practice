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
    int n; cin >> n;
    vector<int> a(n);
    vector<int> place(n+1);
    rep(i,n){
        cin >> a[i];
        place[a[i]] = i;
    }
    vector<pair<int,int>> ans;
    rep(i,n){
        if (place[i+1] != i){
            int b = a[i];
            int chage_place = place[b];
            ans.push_back({i+1,place[i+1]+1});
            swap(a[i],a[place[i+1]]);
            place[b] = place[i+1];
            place[i+1] = chage_place;
        }
    }
    cout << ans.size() << endl;
    for(auto p:ans){
        cout << p.first << " " << p.second << endl;
    }
    
}