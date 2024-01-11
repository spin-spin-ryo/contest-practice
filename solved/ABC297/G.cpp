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

using namespace std;
using ll = long long;
#define mod 998244353
#define INF 1e+16
#define rep(i, x) for(int i = 0; i < (x); i++)

// 知識不足
// Grundy数を初めて知った
int main(){
    ll N,L,R; cin >> N >> L >> R;
    vector<ll> A(N);
    rep(i,N){
        cin >> A[i];
    }
    vector<int> v(N);
    ll sum = 0;
    rep(i,N){
        if (A[i] < L){
            v[i] = 0;
        }else{
            ll n = (A[i] - L)/R;
            if (n%2 == 0){
                v[i] = 1;
            }else{
                v[i] = 0;
            }
        }
        sum += v[i];
    }
    if (sum % 2 == 1){
        cout << "First" << endl;
    }else{
        cout << "Second" << endl;
    }
}