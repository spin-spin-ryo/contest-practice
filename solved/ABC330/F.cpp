#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long;
const ll MOD = 998244353;
const ll INF = 1e16;
const ll MAX_XY = 1e9;
// Efficient reading of integers.
void read(ll &x) {
    cin >> x;
}
// Compute the cost function more efficiently.
inline ll sum_cost(ll x1, ll x2, const vector<ll> &X) {
    ll sum = 0;
    for (ll x : X) {
        if (x < x1) sum += x1 - x;
        else if (x > x2) sum += x - x2;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N, K;
    read(N); read(K);
    vector<ll> X(N), Y(N);
    for (int i = 0; i < N; ++i) {
        read(X[i]); read(Y[i]);
    }
    ll min_length = -1, max_length = MAX_XY;
    while (max_length - min_length > 1) {
        ll m = (min_length + max_length) / 2;
        vector<ll> X_tmp(2*N),Y_tmp(2*N);
        for (int i=0;i<N;i++){
            X_tmp[2*i] = X[i];
            X_tmp[2*i+1] = -m + X[i];
            Y_tmp[2*i] = Y[i];
            Y_tmp[2*i+1] = -m + Y[i]; 
        }
        sort(X_tmp.begin(),X_tmp.end());
        sort(Y_tmp.begin(),Y_tmp.end());
        ll min_x = X_tmp[N];
        ll min_y = Y_tmp[N];
        ll sum = sum_cost(min_x, min_x + m, X) + sum_cost(min_y, min_y + m, Y);
        if (sum <= K)
            max_length = m;
        else
            min_length = m;
    }
    cout << max_length << endl;
    return 0;
}