#include<iostream>
#include<vector>

using namespace std;
using ll = long long;
#define mod 998244353

ll factorial[300000];
ll factorial_inv[300000];

ll power(ll n, ll r){
    ll ans = 1;
    for (int i=0;(r>>i) >0 ;i++){
        if ((r>>i)&1){
            ans *= n;
            ans %= mod;
        }
        n *= n;
        n %= mod;
    }
    return ans;
}

ll inv(ll n){
    return power(n, mod-2);
}

void initialize_factor(){
    factorial[0] = 1;
    factorial_inv[0] = 1;
    for (ll i=1;i<300000;i++){
        factorial[i] = (factorial[i-1]*i)%mod;
        factorial_inv[i] = inv(factorial[i]);
    }
}

ll cmb(ll n, ll r){
    return factorial[n]*factorial_inv[n-r]%mod * factorial_inv[r] % mod;
}




int main(){
    initialize_factor();
    ll N,M,K;cin >> N >> M >> K;
    vector<vector<int> > graph(N);
    int U,V;
    for (int i=0;i<M;i++){
        cin >> U >> V;
        U--;V--;
        graph[U].push_back(V);
        graph[V].push_back(U);
    }

    ll even_num = 0;
    ll odd_num = 0;
    for (int i=0;i<N;i++){
        if ((int)graph[i].size()%2 == 0){
            even_num +=1;
        }else{
            odd_num+=1;
        }
    }

    ll ans = 0;
    for (ll i=0;i<=K;i+=2){
        if ((i<=odd_num) & (K-i <= even_num)){
            ans += cmb(odd_num,i)*cmb(even_num,K-i)%mod;
            ans %= mod;
        }
        
    }
    cout << ans << endl;
}