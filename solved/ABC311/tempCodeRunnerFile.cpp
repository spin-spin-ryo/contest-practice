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

vector<vector<int>> get_accumulate_sum2d(vector<vector<int>> A){
    int H = A.size();
    int W = A[0].size();
    vector<vector<int>> s(H+1,vector<int>(W+1,0));
    rep(i,H){
        rep(j,W){
            s[i+1][j+1] = A[i][j] + s[i+1][j] + s[i][j+1] - s[i][j];
        }
    }

    return s;
}

int main(){
    int H,W,N;cin >> H >> W >> N;
    vector<vector<int>> grid(H,vector<int>(W,0));
    rep(i,N){
        int a,b;cin >>a >> b;
        a--;b--;
        grid[a][b] = 1;
    }
    vector<vector<int>> s= get_accumulate_sum2d(grid);
    ll ans = 0;
    rep(i,H){
        rep(j,W){
            ll l = 0;
            ll r = min(H-i,W-j)+1;
            while (r-l>1){
                ll m = (l+r)/2;
                int count = s[i+m][j+m] - s[i][j+m] - s[i+m][j] + s[i][j];
                if (count >=1){
                    r = m;
                }else{
                    l = m;
                }
            }
            ans += l;

        }
    }
    cout << ans << endl;
}