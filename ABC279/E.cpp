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

using namespace std;
using ll = long long;
#define mod 998244353
#define INF 1e+16
using  vector2d = vector<vector<int> >;

int main(){
    int N,M;cin >> N >> M;
    vector<int> A(M);
    for (int i=0;i<M;i++) cin >> A[i];
    vector<int> a(N);
    for (int i=0;i<N;i++) a[i] = i;
    vector<pair<int,int> > m(M);
    for (int i=0;i<M;i++){
        int u = A[i];
        u--;
        m[i] = make_pair(a[u],a[u+1]);
        swap(a[u],a[u+1]);
    } 
    map<int,int> num2index;
    for (int i=0;i<N;i++) num2index[a[i]] = i;
    for (int i=0;i<M;i++){
        if (m[i].first != 0 & m[i].second != 0){
            cout << num2index[0]+1 << endl;
        }else{
            if (m[i].first == 0){
                cout << num2index[ m[i].second]+1 << endl;
            }else{
                cout << num2index[ m[i].first]+1 << endl;
            }
        }
    }
    return 0;
}