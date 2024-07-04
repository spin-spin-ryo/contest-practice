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
#include <unordered_map>

using namespace std;
using ll = long long;
#define mod 998244353
#define INF 1e+16
#define rep(i, x) for(ll i = 0; i < (x); i++)

using  vector2d = vector<vector<ll> >;

template <typename T>
void prll(vector<T> v){
    rep(i,v.size()){
        cout << v[i] << endl;
    }
    return;
}

ll a[3][3];
ll b[3][3];

ll dfs(ll now){
    // 終了チェック
    bool isEmpty = false;
    rep(i,3){
        rep(j,3){
            if (b[i][j] == 0){
                isEmpty = true;
            }
        }
    }
    if (!isEmpty){
        ll scoreT = 0;
        ll scoreA = 0;
        rep(i,3){
            rep(j,3){
                if (b[i][j] == 1){
                    scoreT += a[i][j];
                }else{
                    scoreA += a[i][j];
                }
            }
        }
        if (scoreT > scoreA){
            return 1;
        }else{
            return -1;
        }
    }

    // 縦横斜め判定
    rep(i,3){
        if (b[i][0] != 0 & b[i][0] == b[i][1] & b[i][0] == b[i][2]){
            return b[i][0];
        }
    }
    rep(i,3){
        if (b[0][i] != 0 & b[0][i] == b[1][i] & b[0][i] == b[2][i]){
            return b[0][i];
        }
    }

    if (b[1][1] != 0 & b[0][0] == b[1][1] & b[0][0]== b[2][2]){
        return b[1][1];
    }

    if (b[1][1] != 0 & b[0][2] == b[1][1] & b[1][1]== b[2][0]){
        return b[1][1];
    }

    vector<ll> ans;
    rep(i,3){
        rep(j,3){
            if (b[i][j] == 0){
                if (now % 2 == 0){
                    b[i][j] = 1;
                    ll win = dfs(now+1);
                    ans.push_back(win);
                    b[i][j] = 0;
                }else{
                    b[i][j] = -1;
                    ll win = dfs(now+1);
                    ans.push_back(win);
                    b[i][j] = 0;
                }
            }
        }
    }
    if (now%2 == 0){
        bool canWin = false;
        rep(i,ans.size()){
            canWin |= (ans[i] == 1);
        }
        if (canWin){
            return 1;
        }else{
            return -1;
        }
    }else{
        bool canWin = false;
        rep(i,ans.size()){
            canWin |= (ans[i] == -1);
        }
        if (canWin){
            return -1;
        }else{
            return 1;
        }
    }
}


int main(){
    rep(i,3){
        rep(j,3){
            cin >> a[i][j];
            b[i][j] = 0;
        }
    }
    ll ans = dfs(0);
    if (ans == 1){
        cout << "Takahashi" << endl;
    }else{
        cout << "Aoki" << endl;
    }
}