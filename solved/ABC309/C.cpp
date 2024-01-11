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

int main(){
    ll N,K;cin >> N >> K;
    vector<ll> a(N);
    vector<ll> b(N);
    vector<ll> point;
    point.push_back(1);
    rep(i,N){
        cin >> a[i] >> b[i];
        point.push_back(a[i]+1);
    }
    compressed_vector v(point);

    vector<ll> interval(N+10,0);
    rep(i,N){
        int index_zero = v.org2com[1];
        int index_one = v.org2com[a[i] + 1];
        interval[index_zero] += b[i];
        interval[index_one] -= b[i];
    }
       
    for (int i=0;i<interval.size();i++){
        if (i == 0){
            if (interval[i] <= K){
                cout << v.com2org[i] << endl;
                return 0;
            }
        }else{
             interval[i] += interval[i-1];
            if (interval[i] <= K){
                cout << v.com2org[i] << endl;
                return 0;
            }
        }
       

    }
}