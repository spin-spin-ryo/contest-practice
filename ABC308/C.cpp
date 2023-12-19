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
#include <cassert>

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

struct Fraction{
    public:
    ll r;
    ll n;
    
    Fraction() = default;
    Fraction(ll _a, ll _b){
        r = _a;
        assert(_b!= 0);
        n = _b;
        if (n < 0){
            r*= -1;
            n*= -1;
        }
    }

    Fraction operator+ (Fraction &other){
        Fraction f(r*other.n + n*other.r,n*other.n);
        return f;
    }
    
    Fraction operator- (Fraction &other){
        Fraction f(r*other.n - n*other.r,n*other.n);
        return f;
    }

    Fraction operator* (Fraction &other){
        Fraction f(r*other.r,n*other.n);
        return f;
    }

    Fraction operator/ (Fraction &other){
        Fraction f(r*other.n,n*other.r);
        return f;
    }

    bool operator < (const Fraction &other) const{
        return r*other.n < n*other.r;
    }

    void test(){
        cout << r << "/" << n << endl;
    }
};

Fraction make_fraction(ll a,ll b){
    Fraction f(a,b);
    return f;
}

int main(){
    ll N;cin >> N;
    vector<pair<Fraction,int>> v;
    rep(i,N){
        ll A,B;
        cin >> A >> B;
        v.push_back(make_pair(make_fraction(A,A+B),-i));
    }
    sort(v.begin(),v.end());
    rep(i,N){
        cout << -v[N-1-i].second + 1<< " ";
    }
    cout << endl;
}