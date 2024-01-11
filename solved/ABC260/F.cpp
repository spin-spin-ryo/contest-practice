#include<iostream>
#include<vector>
#include <tuple>
#include <string>
#include <algorithm>
#include <stack>
#include <utility>
#include <queue>



using namespace std;
using ll = long long;
#define mod 998244353
using  vector2d = vector<vector<int> >;

int main(){
    // unsolved
    int S,T,M;cin >> S >> T >> M;
    vector<vector<int> > u2v(T);
    int u,v;
    for (int i=0;i<M;i++){
        cin >> u >> v;
        u2v[v-S-1].push_back(u);
    }
    for (int i=0;i<T;i++){
        sort(u2v[i].begin(),u2v[i].end());
    }
    for (int i=0;i<T;i++){
        for (int j=i+1;j<T;j++){
            int index1 = 0;
            int index2 = 0;
            
            int count = 0;
            int ans1 = -1;
            int ans2 = -1;
            while ( (index1 < u2v[i].size()) & (index2 < u2v[j].size()) ){
                u = u2v[i][index1];
                v = u2v[j][index2];
                if (u<v){
                    index1 ++;
                }
                if (u==v){
                    count ++;
                    if (count == 1){
                        ans1 = u;
                    }
                    if (count == 2){
                        ans2 = u;
                        cout << ans1 << " " << ans2 << " " << i+S+1 <<" " << j+S+1<< endl;
                        return 0;
                    }
                    index1++;
                    index2++;
                }
                if (u>v){
                    index2++;
                }
            }
        }
    }
    cout << -1 << endl;
}