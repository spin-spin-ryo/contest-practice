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

using namespace std;
using ll = long long;
#define mod 998244353
#define INF 1e+16
using  vector2d = vector<vector<int> >;

int main(){
    int N,M;cin >> N >> M;
    vector<int> A(N);
    vector<pair<int,int> > counter;
    for (int i=0;i<N;i++){
        cin >> A[i];
        if (A[i] >=0){
            counter.push_back(make_pair(1,i));
        }else{
            int c = -A[i]/(i+1);
            if (-A[i]%(i+1)!=0) c++;
            counter.push_back(make_pair(c,i));
        }
    }
    sort(counter.begin(),counter.end());
    int index = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>,greater<pair<int,int>>()>> que;
    for (int i=0;i<M;i++){
        if (counter[index].first == i+1){
            while (counter[index].first == i+1){
                int index2 = counter[index].second;
                int a = A[index2] + (index2+1)*(i+1);
                que.push(make_pair(a,index2));
                index++;
            }
            int min_a = 0;
            while (!que.emptyw)
            if (min_a == positives[j]){
                    
                    min_a++;
                }else{
                    cout << min_a << endl;
                    break;
                }
            }
            cout << min_a << endl;
        }else{
            cout << 0 << endl;
        }
        
    }
}
    