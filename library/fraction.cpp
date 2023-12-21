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

    bool operator< (Fraction &other){
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
    Fraction f1 = make_fraction(3,5);
    Fraction f2 = make_fraction(3,8);
    Fraction f3 = f1+f2;
    f3.test();
}