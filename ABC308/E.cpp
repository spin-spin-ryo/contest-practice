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

ll mex(ll a,ll b, ll c){
    rep(i,4){
        if (i != a & i != b & i!= c){
            return i;
        }
    }
}

int main(){
    ll N; cin >> N;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];
    string S;cin >> S;
    vector<ll> counter1(3,0);
    map<pair<ll,ll>,ll> counter2;
    ll ans = 0;
    
    rep(i,N){
        int j = N-1-i;
        if (S[j] == 'X'){
            counter1[A[j]] ++ ;
        }
        if (S[j]=='E'){
            rep(k,3){
                int a = A[j];
                int b = k;
                if (b<a) swap(a,b);
                counter2[make_pair(a,b)] += counter1[k];
            }
        }
        if (S[j] == 'M'){
            rep(k,3){
                ans += mex(A[j],k,k)*counter2[make_pair(k,k)];
            }
            ans += mex(A[j],0,1)*counter2[make_pair(0,1)];
            ans += mex(A[j],1,2)*counter2[make_pair(1,2)];
            ans += mex(A[j],0,2)*counter2[make_pair(0,2)];
        }
    }
    cout << ans << endl;
}