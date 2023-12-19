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

struct compressed_vector{
    public:
    map<ll,ll> org2com;
    vector<ll> com2org;
    vector<ll> original;
    vector<ll> compressed;

    compressed_vector() = default;

    explicit compressed_vector(vector<ll> _v){
        original.resize(_v.size());
        copy(_v.begin(), _v.end(), original.begin());
        com2org = _v;
        sort(com2org.begin(), com2org.end());
        com2org.erase(unique(com2org.begin(), com2org.end()), com2org.end());
        rep(i,com2org.size()){
            org2com[com2org[i]] = i;
        }
        rep(i,original.size()){
            compressed.push_back(org2com[original[i]]);
        }
    }

    ll& operator[](size_t index){
        return compressed[index];
    }
};
     