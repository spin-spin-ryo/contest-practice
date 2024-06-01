#include <iostream>
#include <vector>
#include <atcoder/lazysegtree>

using namespace std;
using ll = long long;
#define MOD 998244353
#define INF 1e+16
#define rep(i, x) for(int i = 0; i < (x); i++)

using vector2d = vector<vector<int>>;

ll power(ll n, ll r) {
    ll ans = 1;
    while (r > 0) {
        if (r & 1) {
            ans = ans * n % MOD;
        }
        n = n * n % MOD;
        r >>= 1;
    }
    return ans;
}

ll inv(ll n) {
    return power(n, MOD - 2);
}

struct object {
    ll lambda, x;
};

using S = ll;
S op(S a, S b) {
    return (a + b) % MOD;
}

S e() {
    return 0;
}

using F = object;
S mapping(F f, S x) {
    if (f.lambda == INF) {
        return x;
    } else {
        ll inv_lambda = inv(f.lambda);
        return (((f.lambda - 1) * x % MOD) * inv_lambda % MOD + inv_lambda * f.x % MOD) % MOD;
    }
}

F composition(F f, F g) {
    if (f.lambda == INF) return g;
    if (g.lambda == INF) return f;
    F h;
    ll inv_comb = inv((f.lambda + g.lambda) % MOD - 1);
    h.lambda = (f.lambda * g.lambda % MOD) * inv_comb % MOD;
    h.x = (((f.lambda - 1) * g.x % MOD + g.lambda * f.x % MOD) % MOD) * inv_comb % MOD;
    return h;
}

F id() {
    object o;
    o.lambda = INF;
    return o;
}

template <typename T>
void print(const vector<T>& v) {
    for (const auto& val : v) {
        cout << val << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(a);
    rep(i, m) {
        ll l, r, x;
        cin >> l >> r >> x;
        l--;
        F f = {r - l, x};
        seg.apply(l, r, f);
    }

    rep(i, n) {
        cout << seg.get(i)%MOD << " ";
    }
    cout << endl;

    return 0;
}

