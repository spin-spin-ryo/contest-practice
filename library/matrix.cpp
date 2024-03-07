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

using namespace std;
using ll = long long;
#define mod 998244353
#define INF 1e+16
#define rep(i, x) for(int i = 0; i < (x); i++)

using  vector2d = vector<vector<int> >;

// 正方行列
vector<vector<ll>> mat_add(vector<vector<ll>> a,vector<vector<ll>> b){
    int n = a.size();
    vector<vector<ll>> c(n,vector<ll>(n));
    rep(i,n){
        rep(j,n){
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    return c;
}

vector<vector<ll>> mat_mul(vector<vector<ll>> a,vector<vector<ll>> b){
    int n = a.size();
    vector<vector<ll>> c(n,vector<ll>(n));
    rep(i,n){
        rep(j,n){
            rep(k,n){
                c[i][j] += a[i][k]*b[k][j];
            }
        }
    }
    return c;
}

vector<vector<ll>> mat_power(vector<vector<ll>> a,ll s){
    int n= a.size();
    vector<vector<ll>> c(n,vector<ll>(n));
    rep(i,n) c[i][i] = 1;
    vector<vector<ll>> d = a;
    for (int r=0;s>>r > 0;r++){
        if ((s>>r)&1){
            c = mat_mul(c,d);
        }
        d = mat_mul(d,d);
    }
    return c;
}

// 01ベクトルの吐き出し法
vector<vector<ll>> sweeping_zeroone(vector<vector<ll>> A){
    int n = A.size();
    int m = A[0].size();
    int l = 0;
    rep(i,m){
        if (A[i][l] == 1){
            for(int j= i+1;j<n;j++){
                if (A[j][l] == 1){
                    for(int k=l;k<m;k++){
                        A[j][k] -= A[i][k];
                    }
                }
            }
            l++;
        }else{
            bool find = false;
            for(int j=i+1;j<n;j++){
                if (A[j][l] == 1){
                    // j行目とi行目を交換
                    rep(k,m){
                        swap(A[i][k],A[j][k]);
                    }
                    i--;
                    find = true;
                    break;
                }
            }
            if (!find){
                l++;
                i--;
                if (l==m){
                    break;
                }
            }
            
        }
    }
    return A;
}



bool solve_linear(vector<vector<ll>> A, vector<ll> b){
    int n = A.size();
    int m = A[0].size();
    int l = 0;
    rep(i,m){
        if (A[i][l] == 1){
            for(int j= i+1;j<n;j++){
                if (A[j][l] == 1){
                    for(int k=l;k<m;k++){
                        A[j][k] -= A[i][k];
                    }
                    b[j]-=b[i];
                }
            }
            l++;
            if (l==m){
                break;
            }
        }else{
            bool find = false;
            for(int j=i+1;j<n;j++){
                if (A[j][l] == 1){
                    // j行目とi行目を交換
                    rep(k,m){
                        swap(A[i][k],A[j][k]);
                    }
                    swap(b[i],b[j]);
                    i--;
                    find = true;
                    break;
                }
            }
            if (!find){
                l++;
                i--;
                if (l==m){
                    break;
                }
            }
            
        }
    }
    for(int i=n-1;i>=0;i--){
        bool all_zero = true;
        rep(j,m){
            cout << A[i][j] << " ";
            if (A[i][j]!= 0) all_zero = false;
        }
        cout << b[i] << endl;
        if (all_zero == b[i]){
            return false;
        }
    }
    return true;
}


int main(){
    vector<vector<ll>> A = {{1,1,1},{1,1,1},{0,0,1}};
    vector<ll> b ={1,1,1};
    cout << solve_linear(A,b) << endl;;
}