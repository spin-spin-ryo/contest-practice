
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

using namespace std;
using ll = long long;
#define mod 998244353
#define INF 1e+16
using  vector2d = vector<vector<int> >;

int main(){
    int N;cin >> N;
    int l = 1;
    int r = 0;
    while (l <= N){
        r++;
        l*=2;
    }
    r--;
    int M = 0;
    l = 1;
    vector<vector<ll>> sp(r+1);
    for (int R = 0;R<=r;R++){
        for (int i=0;i<N;i++){
            if (i+l <=N){
                M++;
                sp[R].push_back(i);
            }
        }
        l*=2;
    }
    cout << M << endl;
    l = 1;
    for (int R = 0;R<=r;R++){
        for (int i=0;i<N;i++){
            if (i+l <=N){
                cout << i+1 << " " << i+l << endl;
            }
        }
        l*=2;
    }
    vector<int> sum(r+1,0);
    sum[0] = sp[0].size();
    for (int i=1;i<=r;i++){
        sum[i] = sum[i-1] + sp[i].size();
    }

    int Q;cin >> Q;
    for (int i=0;i<Q;i++){
        int L,R;cin >> L >> R;
        l = 1;
        r = 0;
        while (l<= (R-L+1)){
            l*=2;
            r++;
        }
        r--;
        l/=2;
        int index = 0;
        if (r>0){
            index = sum[r-1];
        }
        cout << index + L << " " << index + R - l +1 << endl;
    }
}