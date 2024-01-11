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

int main(){
    ll N,M,K; cin >> N >> M >> K;
    string S;
    cin >> S;
    ll l = 0;
    ll r = 0;
    ll k = 0;
    ll ans = 0;
    ll count_x = 0;
    rep(i,N){
        if (S[i] == 'x'){
            count_x ++;
        }
    }
    ll m = min(M,(ll)2);
    vector<ll> answers1(2*N+1,0);
    vector<ll> answers2(2*N+1,0);
    
    while (l<N & r <= m*N){
        while (k<=K & r <= m*N){
            if (r == m*N) break;
            r ++;
            if (S[(r-1)%N]== 'x'){
                if (k == K){
                    r--;
                    break;
                }
                k++;
            }
            ans ++;
            if (l < N & r >=N){
                if (answers2[k] < ans) answers2[k] = ans;
            }else{
                if (answers1[k] < ans) answers1[k] = ans;
            }
        }
        l++;
        if (S[l-1]== 'x'){
            k --;
        }
        ans --;
        if (l < N & r >=N){
            if (answers2[k] < ans) answers2[k] = ans;
        }else{
            if (answers1[k] < ans) answers1[k] = ans;
        }
    }
    ll max_ans = 0;
    for (ll k =1;k< 2*N+1 ;k++){
        max_ans = max(max_ans,answers1[k]);
        if (answers2[k] > 0){
            ll t = (K-k)/count_x;
            t = max(min(t,M-2),(ll)0);
            max_ans = max(max_ans,answers2[k] + N*t);
        }
    }
    cout << max_ans << endl;
    return 0;
}