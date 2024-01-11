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

class UnionFind{
    vector<int> parent;


    public:
    vector<int> connection_size;
    explicit UnionFind(size_t size):parent(size){
        connection_size.resize(size,1);
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
        parent[rx] = ry;
        connection_size[ry] += connection_size[rx];
        connection_size[rx] = 0;
    }

    bool same(int x, int y){
        int rx = root(x);
        int ry = root(y);
        return rx==ry;
    }

    int get_size(int x){
        int rx = root(x);
        return connection_size[rx];
    }

};

int main(){
    cout << "Hello World" << endl;
    return 0;
}