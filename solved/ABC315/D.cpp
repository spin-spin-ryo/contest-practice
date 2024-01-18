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

int main(){
    int H,W; cin >> H >> W;
    vector<string> cookies(H);
    vector<vector<bool>> clear(H,vector<bool>(W,false));
    rep(i,H){
        cin >> cookies[i];
    }
    vector<vector<int>> h_sum(H,vector<int>(26,0));
    vector<vector<int>> w_sum(W,vector<int>(26,0));
    rep(i,H){
        rep(j,W){
            int index = (int)(cookies[i][j] - 'a');
            h_sum[i][index] ++;
            w_sum[j][index] ++;
        }
    }
    while(true){
        vector<vector<int>> w_remove(W,vector<int>(26,0));
        vector<vector<int>> h_remove(H,vector<int>(26,0));
        rep(i,H){
            int count = 0;
            rep(j,26){
                count += h_sum[i][j];
            }
            rep(j,26){
                if (count == h_sum[i][j] & count >=2){
                    // cout << i << " " << j << endl;
                    h_sum[i][j] = 0;
                    rep(w,W){
                        if (cookies[i][w] - 'a' == j){
                            if (!clear[i][w]){
                                w_remove[w][j] ++;
                                clear[i][w] = true;
                            }
                            
                        } 
                    }
                    break;
                }
            }
        }
        rep(i,W){
            int count = 0;
            rep(j,26){
                count += w_sum[i][j];
            }
            rep(j,26){
                if (count == w_sum[i][j] & count >=2){
                    // cout << i << " " << j << endl;
                    w_sum[i][j] = 0;
                    rep(h,H){
                        if (cookies[h][i] - 'a' == j){
                            if (!clear[h][i]){
                                h_remove[h][j] ++;
                                clear[h][i] = true;
                            }
                        } 
                    }
                    break;
                }
            }
        }
        int count = 0;
        rep(i,H){
            rep(j,26){
                if (h_remove[i][j] > 0){
                    count ++;
                    h_sum[i][j] -= h_remove[i][j];
                }
            }
        }
        rep(i,W){
            rep(j,26){
                if (w_remove[i][j] > 0){
                    count ++;
                    w_sum[i][j] -= w_remove[i][j];
                }
            }
        }
        if (count == 0){
            break;
        }
    }
    int ans = 0;
    rep(i,H){
        rep(j,26){
            ans += h_sum[i][j];
        }
    }
    cout << ans << endl;
}