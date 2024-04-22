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
    ll x,y,a,b,c,d; cin >> x>> y>> a >>b >> c >> d;
    bool up = d >= b;
    bool right = c >= a;

    ll ans = INF;
    ll now = 0;
    if (up){
        now += abs(y -b +1);
        now += abs(x-a);
        if (x == a & b < y){
            now +=2;
        }
    }else{
        now += abs(y -b -1);
        now += abs(x-a);
        if (x == a & b > y){
            now +=2;
        }     
    }

    now += abs(a-c) + abs(b-d);
    if (a!=c) now +=2;
    ans = min(now,ans);

    now = 0;
    if (right){
        now += abs(y -b);
        now += abs(x-a+1);
        if (y == b & a < x){
            now +=2;
        }
    }else{
        now += abs(y -b );
        now += abs(x-a-1);
        if (y == b & x < a){
            now +=2;
        }
    }

    now += abs(a-c) + abs(b-d);
    if (b!=d) now +=2;
    ans = min(now,ans);
    cout << ans << endl;

}