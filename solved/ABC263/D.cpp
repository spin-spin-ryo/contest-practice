#include<iostream>
#include<vector>

using namespace std;
using ll = long long;
#define mod 998244353

int main(){
    ll N,L,R; cin >> N >> L >> R;
    vector<ll> A(N);
    for (ll i=0;i<N;i++){
        cin >> A[i];
    }

    

    vector<ll> min_index(N+1,N);
    ll min_sub = 0;
    ll index = N;
    ll sum = 0;
    for (ll i=N-1;i>=0;i--){
        sum += A[i];
        if ((N-i)*R -sum < min_sub){
            min_sub = (N-i)*R -sum;
            min_index[i] = i;
            index = i;
        }else{
            min_index[i] = index;
        }
    }
    
    vector<ll> acu(N+1,0);
    for (ll i=0;i<N;i++){
        acu[i+1] = acu[i] + A[i];
    }

    ll ans = 1e+16;
    for (ll i=0;i<N+1;i++){
        ans =  min(ans, i*L + (N - min_index[i])*R + acu[min_index[i]] - acu[i]);
    }
    ans = min(ans,N*R);
    ans = min(ans, N*L);
    cout << ans << endl;
}