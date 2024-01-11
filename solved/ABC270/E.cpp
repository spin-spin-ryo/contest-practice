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

using namespace std;
using ll = long long;
#define mod 998244353
using  vector2d = vector<vector<int> >;

int main(){
    ll N,K;cin >> N >> K;
    vector<ll> A(N);
    vector<ll> B(N);
    for (int i=0;i<N;i++){
        cin >> A[i];
        B[i] = A[i]; 
    }
    ll count = N;
    sort(B.begin(),B.end());
    ll now = 0;
    ll sub;
    for (int i=0;i<N;i++){
        if (now < B[i]){
            sub = B[i] - now;
            if (sub * count <= K){
                K -= sub*count;
            }else{
                sub = K/count;
                break;
            }
        }
        count -- ;
        now = B[i];
        if (K==0){
            sub = 0;
            break;
        }
    }

    if (K == 0){
        
        for (int i=0;i<N;i++){
            cout << max((ll)0,A[i]-now) << " ";
        }
        cout << endl;
    }else{
        now += sub;
        K-= count*sub;
        for (int i=0;i<N;i++){
            if (0>=A[i]-now){
                cout << 0 << " ";
            }else{
                if (K>0){
                    cout << A[i] - now -1 << " ";
                    K--;
                }else{
                    cout << A[i] - now << " "; 
                }
            }
        }
        cout << endl;
    }



}