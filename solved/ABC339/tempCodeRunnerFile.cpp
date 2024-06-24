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

void dfs(int p, int q, vector<int> &row_A, vector<int> &row_B, vector<int> &row_C, vector<int> &col_A, vector<int> &col_B, vector<int> &col_C, int &N, string &R, string &C){
    // check row
    // cout << p << " " << q << endl;
    if (p == N){
        bool allok = true;
        rep(i,N){
            if ((row_A[i]>=0) & (row_B[i] >=0) & (row_C[i] >=0) & (col_A[i]>=0) & (col_B[i] >=0) & (col_C[i] >=0)){
                continue;
            }else{
                allok =false;
            }
        }
        if (allok){
            cout << "Yes"<< endl;
            vector<string> ans(N);
            rep(i,N){
                ans[i] = string(N, '.'); 
            }
            rep(i,N){
                if (row_A[i] >= 0) ans[i][row_A[i]] = 'A';
                if (row_B[i] >= 0)ans[i][row_B[i]] = 'B';
                if (row_C[i] >= 0)ans[i][row_C[i]] = 'C';
            }
            rep(i,N){
                cout << ans[i] << endl;
            }
            exit(1);
        }
        return;
    }
    vector<char> row;
    vector<char> col;
    
    if (row_A[p] == -1){
        row.push_back('A');
    }
    if (row_B[p] == -1){
        row.push_back('B');
    }
    if (row_C[p] == -1){
        row.push_back('C');
    }
    if (col_A[q] == -1){
        col.push_back('A');
    }
    if (col_B[q] == -1){
        col.push_back('B');
    }
    if (col_C[q] == -1){
        col.push_back('C');
    }
    
    if (row.size() == 3 & col.size() == 3){
        if (R[p] == C[q]){
            if (R[p] == 'A'){
                col_A[q] = p;
                row_A[p] = q;
                dfs(p + ((q+1)%N == 0),(q+1)%N,row_A,row_B,row_C,col_A,col_B,col_C,N,R,C);
                col_A[q] = -1;
                row_A[p] = -1;
            }
            if (R[p] == 'B'){
                col_B[q] = p;
                row_B[p] = q;
                dfs(p + ((q+1)%N == 0),(q+1)%N,row_A,row_B,row_C,col_A,col_B,col_C,N,R,C);
                col_B[q] = -1;
                row_B[p] = -1;
            }
            if (R[p] == 'C'){
                col_C[q] = p;
                row_C[p] = q;
                dfs(p + ((q+1)%N == 0),(q+1)%N,row_A,row_B,row_C,col_A,col_B,col_C,N,R,C);
                col_C[q] = -1;
                row_C[p] = -1;
                
            }
            
            
        }
    }else{
        if (col.size() == 3){
            // use C[q]
            if (C[q] == 'A' & row_A[p] == -1){
                col_A[q] = p;
                row_A[p] = q;
                dfs(p + ((q+1)%N == 0),(q+1)%N,row_A,row_B,row_C,col_A,col_B,col_C,N,R,C);
                col_A[q] = -1;
                row_A[p] = -1;
            }
            if (C[q] == 'B' & row_B[p] == -1){
                col_B[q] = p;
                row_B[p] = q;
                dfs(p + ((q+1)%N == 0),(q+1)%N,row_A,row_B,row_C,col_A,col_B,col_C,N,R,C);
                col_B[q] = -1;
                row_B[p] = -1;
            }
            if (C[q] == 'C' & row_C[p] == -1){
                col_C[q] = p;
                row_C[p] = q;
                dfs(p + ((q+1)%N == 0),(q+1)%N,row_A,row_B,row_C,col_A,col_B,col_C,N,R,C);
                col_C[q] = -1;
                row_C[p] = -1;
            }
            
           
            
    
            dfs(p + ((q+1)%N == 0),(q+1)%N,row_A,row_B,row_C,col_A,col_B,col_C,N,R,C);
        }else{
            if (row.size() == 3){
                if (R[p] == 'A' & col_A[q] == -1){
                    col_A[q] = p;
                    row_A[p] = q;
                    dfs(p + ((q+1)%N == 0),(q+1)%N,row_A,row_B,row_C,col_A,col_B,col_C,N,R,C);
                    col_A[q] = -1;
                    row_A[p] = -1;
                }
                if (R[p] == 'B' & col_B[q] == -1){
                    col_B[q] = p;
                    row_B[p] = q;
                     dfs(p + ((q+1)%N == 0),(q+1)%N,row_A,row_B,row_C,col_A,col_B,col_C,N,R,C);
                    col_B[q] = -1;
                    row_B[p] = -1;
                }
                if (R[p] == 'C' & col_C[q] == -1){
                    col_C[q] = p;
                    row_C[p] = q;
                     dfs(p + ((q+1)%N == 0),(q+1)%N,row_A,row_B,row_C,col_A,col_B,col_C,N,R,C);
                    col_C[q] = -1;
                    row_C[p] = -1;
                }
                dfs(p + ((q+1)%N == 0),(q+1)%N,row_A,row_B,row_C,col_A,col_B,col_C,N,R,C);             
            }else{
                if (col_A[q] == -1 & row_A[p] == -1){
                    col_A[q] = p;
                    row_A[p] = q;
                    dfs(p + ((q+1)%N == 0),(q+1)%N,row_A,row_B,row_C,col_A,col_B,col_C,N,R,C);
                    col_A[q] = -1;
                    row_A[p] = -1;
                }
                if (col_B[q] == -1 & row_B[p] == -1){
                    col_B[q] = p;
                    row_B[p] = q;
                    dfs(p + ((q+1)%N == 0),(q+1)%N,row_A,row_B,row_C,col_A,col_B,col_C,N,R,C);
                    col_B[q] = -1;
                    row_B[p] = -1;
                }
                if (col_C[q] == -1 & row_C[p] == -1){
                    col_C[q] = p;
                    row_C[p] = q;
                    dfs(p + ((q+1)%N == 0),(q+1)%N,row_A,row_B,row_C,col_A,col_B,col_C,N,R,C);
                    col_C[q] = -1;
                    row_C[p] = -1;
                }
                dfs(p + ((q+1)%N == 0),(q+1)%N,row_A,row_B,row_C,col_A,col_B,col_C,N,R,C);
            }
        }
    }
    // cout << p << " " << q << endl;
}

int main(){
    int N;cin >> N;
    string R;cin >> R;
    string C; cin >> C;
    vector<int> row_A(N,-1);
    vector<int> row_B(N,-1);
    vector<int> row_C(N,-1);
    vector<int> col_A(N,-1);
    vector<int> col_B(N,-1);
    vector<int> col_C(N,-1);
    dfs(0,0,row_A,row_B,row_C,col_A,col_B,col_C,N,R,C);
    cout << "No" << endl;
}