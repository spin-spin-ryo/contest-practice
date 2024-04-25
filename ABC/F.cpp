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
    ll N,X,Y; cin >> N >> X >> Y;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];
    vector<ll> A2(N/2);
    vector<ll> A1(N - N/2);
    rep(i,N){
        if (i%2 == 0) A1[i/2] = A[i];
        else A2[i/2] = A[i]; 
    }

    ll n1,n2,n3,n4;
    n1 = A1.size()/2;
    n2 = A1.size() - n1;
    n3 = A2.size()/2;
    n4 = A2.size() - n3;


    vector<ll> sum1(1<<n1);
    vector<ll> sum2(1<<n2);
    vector<ll> sum3(1<<n3);
    vector<ll> sum4(1<<n4);
    map<ll,ll> inverse_sum2;
    map<ll,ll> inverse_sum4;

    for(ll n = 0;n < (1 << n1);n++){
        // 0は＋
        ll sum_num = 0;
        for (int i=0;i<n1;i++){
            
            if (((n >> i)&1) == 0){
                sum_num += A1[i];
            }else{
                sum_num -= A1[i];
            }
        }
        sum1[n] = sum_num;
    }
    for(ll n = 0;n < (1 << n2);n++){
        // 0は＋
        ll sum_num = 0;
        for (int i=0;i<n2;i++){
            
            if (((n >> i)&1) == 0){
                sum_num += A1[i+n1];
            }else{
                sum_num -= A1[i+n1];
            }
        }
        sum2[n] = sum_num;
        inverse_sum2[sum_num] = n+1;
    }
    for(ll n = 0;n < (1 << n3);n++){
        // 0は＋
        ll sum_num = 0;
        for (int i=0;i<n3;i++){
            
            if (((n >> i)&1) == 0){
                sum_num += A2[i];
            }else{
                sum_num -= A2[i];
            }
        }
        sum3[n] = sum_num;
    }
    for(ll n = 0;n < (1 << n4);n++){
        // 0は＋
        ll sum_num = 0;
        for (int i=0;i<n4;i++){
            
            if (((n >> i)&1) == 0){
                sum_num += A2[i+n3];
            }else{
                sum_num -= A2[i+n3];
            }
        }
        sum4[n] = sum_num;
        inverse_sum4[sum_num] = n+1;
    }

    // X check
    ll n1y=-1,n2y=-1,n1x=-1,n2x=-1;
    for(ll n = 0;n<(1<<n1);n++){
        if (inverse_sum2[Y - sum1[n]] > 0){
            n2y = inverse_sum2[Y - sum1[n]] -1;
            n1y = n;
            break;
        }
    }
    for(ll n = 0;n<(1<<n3);n++){
        if (inverse_sum4[X - sum3[n]] > 0){
            n2x = inverse_sum4[X - sum3[n]] -1;
            n1x = n;
            break;
        }
    }
    if (n1x == -1 | n2x == -1| n1y == -1|n2y == -1){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    string ans = "";
    int now = 0;
    rep(i,N){
        ll I = i/2;
        // cout << ans << endl;
        if (i%2 == 0){
            if (I<n1){
                if( ((n1y >> I)&1) == 0){
                    if (now == 0){
                        ans += 'L';
                    }else{
                        ans += 'R';
                    }
                    now = 1;
                }else{
                    if (now == 0){
                        ans += 'R';
                    }else{
                        ans += 'L';
                    }
                    now = 3;
                }
            }else{
                I-=n1;
                if( ((n2y >> I)&1) == 0){
                    if (now == 0){
                        ans += 'L';
                    }else{
                        ans += 'R';
                    }
                    now = 1;
                }else{
                    if (now == 0){
                        ans += 'R';
                    }else{
                        ans += 'L';
                    }
                    now = 3;
                }
            }

        }else{
            if (I<n3){
                if( ((n1x >> I)&1) == 0){
                    if (now == 1){
                        ans += 'R';
                    }else{
                        ans += 'L';
                    }
                    now = 0;
                }else{
                    if (now == 1){
                        ans += 'L';
                    }else{
                        ans += 'R';
                    }
                    now = 2;
                }
            }else{
                I -= n3;
                if( ((n2x >> I)&1) == 0){
                    if (now == 1){
                        ans += 'R';
                    }else{
                        ans += 'L';
                    }
                    now = 0;
                }else{
                    if (now == 1){
                        ans += 'L';
                    }else{
                        ans += 'R';
                    }
                    now = 2;
                }
            }

        }
    }
    cout << ans << endl;
}