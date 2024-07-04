#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <algorithm>
#include <stack>
#include <utility>
#include <queue>
#include <map>
#include <unordered_map>
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
    int n; cin >> n;
    vector<int> a(n);
    unordered_map<int,int> forward;
    unordered_map<int,int> prev;
    rep(i,n){
        cin >> a[i];
    }
    rep(i,n){
        if (n == 1){
            prev[a[i]] = -1;
            forward[a[i]] = -1;
            continue;
        }
        if (i==0){
            prev[a[i]] = -1;
            forward[a[i]] = a[i+1];
        }else if(i == n-1){
            prev[a[i]] = a[i-1];
            forward[a[i]] = -1;
        }else{
            prev[a[i]] = a[i-1];
            forward[a[i]] = a[i+1];
        }
    }
    int Q; cin >> Q;
    while(Q>0){
        Q--;
        int q; cin >> q;
        if(q == 1){
            int x,y; cin >> x >> y;
            int z = forward[x];
            forward[x] = y;
            prev[y] = x;
            if (z!=-1){
                prev[z] = y;
            }
            forward[y] = z;
        }else{
            int x; cin >> x;
            int y = forward[x];
            int z = prev[x];
            if (y!=-1){
                prev[y] = z;
            }
            if (z!=-1){
                forward[z] = y;
            }
            forward.erase(forward.find(x));
            prev.erase(prev.find(x));
        }
    }
    auto itr = prev.begin();
    int key = (*itr).first;
    while(prev[key] != -1){
        key = prev[key];
    }
    while(forward[key] != -1){
        cout << key << " ";
        key = forward[key];
    }
    cout << key << endl;
}