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

class UnionFind{
    vector<int> parent;


    public:
    explicit UnionFind(size_t size):parent(size){
        for (int i=0;i<size;i++) parent[i] = i;
    }

    int root(int x){
        if (parent[x] == x) return x;
        return parent[x] = root(parent[x]);
    }

    void unite(int x,int y){
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        parent[ry] = rx;
    }

    bool same(int x, int y){
        int rx = root(x);
        int ry = root(y);
        return rx==ry;
    }

};


int main(){
    int N,Q; cin >> N >> Q;
    UnionFind solver(N+2*Q);
    int count = N;
    int count2 = N+Q;
    map<int,int> Nodes;
    map<int,int> BoxtoNowNode;
    map<int,int> BoxtoNode;
    for (int i=0;i<N;i++){
        Nodes[i] = i;
        BoxtoNowNode[i] = i;
        BoxtoNode[i] = i;
    }
    for (int i=0;i<Q;i++){
        int q;cin >> q;
        int x,y;

        if (q == 1){
            cin >> x >> y;
            x--;y--;
            if (BoxtoNowNode[x] != -1 & BoxtoNowNode[y] != -1){
                solver.unite(BoxtoNowNode[x],BoxtoNowNode[y]);
                BoxtoNowNode[y] = -1;
                count2++;
                continue;
            }
            if (BoxtoNowNode[x] == -1 & BoxtoNowNode[y] != -1){
                BoxtoNowNode[x] = count2;
                BoxtoNode[x] = count2;
                Nodes[count2] = x;
                solver.unite(BoxtoNowNode[x],BoxtoNowNode[y]);
                BoxtoNowNode[y] = -1;
                count2++;
                continue;
            }

            if (BoxtoNowNode[y] != -1){
                continue;
            }
            
        }
        if (q == 2){
            cin >> x;
            x--;
            if (BoxtoNowNode[x]==-1){
                BoxtoNowNode[x] = count;
                BoxtoNode[x] = count;
                Nodes[count] = x;
            }else{
                solver.unite(BoxtoNowNode[x],count);
            }
            count ++;
        }
        if (q == 3){
            cin >> x;
            x--;
            cout << Nodes[solver.root(x)]+1 << endl;
        }
    }
}