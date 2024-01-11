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
#define rep(i, x) for(ll i = 0; i < (x); i++)

using  vector2d = vector<vector<ll> >;

template <typename T>
void prll(vector<T> v){
    rep(i,v.size()){
        cout << v[i] << endl;
    }
    return;
}

template <typename T>
struct RMQ{
    const T INF = numeric_limits<T>::max();
    int n;
    vector<T> dat;
    RMQ(int n_):n(), dat(n_*4 ,INF){
        int x = 1;
        while (n_>x){
            x*= 2;
        }
        n = x;
    }

    void update(int i, T x){
        i += n-1;
        dat[i] = x;
        while (i>0){
            i = (i-1)/2;
            dat[i] = min(dat[2*i +1],dat[i*2+2]);
        }
    }

    T query(int a, int b){
        return query_sub(a,b,0,0,n);
    }

    T query_sub(int a, int b, int k, int l, int r){
        if (r <= a || b <= l){
            return INF;
        }else{
            if (a <= l && r <= b){
                return dat[k];
            }
        }
        T vl = query_sub(a,b,k*2 +1 ,l, (l+r)/2);
        T vr = query_sub(a,b,k*2+2,(l+r)/2,r);
        return min(vl,vr);
    }

};


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
    ll N;cin >> N;
    vector<vector<ll>> box(N);
    vector<tuple<ll,ll,ll>> boxes(N);
    vector<ll> H(N);
    vector<ll> W(N);
    vector<ll> D(N);
    rep(i,N){
        ll h,w,d;
        cin >> h >> w >> d;
        box[i] = {h,w,d};
        sort(box[i].begin(),box[i].end());
        H[i] = box[i][0];
        W[i] = box[i][1];
        D[i] = box[i][2];
    }
    
    compressed_vector compressed_h(H);
    compressed_vector compressed_w(W);
    compressed_vector compressed_d(D);
    rep(i,N){
        boxes[i] = make_tuple(compressed_h[i],-compressed_w[i],compressed_d[i]);
    }

    sort(boxes.begin(),boxes.end());
    RMQ<ll> solver(N);
    rep(i,N){
        ll h,w,d;
        h = get<0>(boxes[i]);
        w = -get<1>(boxes[i]);
        d = get<2>(boxes[i]);
        ll d_min = solver.query(0,w);
        if (d_min < d){
            cout << "Yes" << endl;
            return 0;
        }
        ll d1 = solver.query(w,w+1);
        solver.update(w,min(d1,d));
    }
    cout << "No" << endl;
    return 0;
}