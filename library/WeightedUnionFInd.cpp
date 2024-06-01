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

class WeightedUnionFind{
    vector<int> parent;
    vector<int> rank;
    vector<int> diff_weight;
    // diff_weightは親に対する枝での重みを累積したもの


    public:
    vector<int> connection_size;
    explicit WeightedUnionFind(size_t size):parent(size){
        connection_size.resize(size,1);
        diff_weight.resize(size,0);
        rank.resize(size,0);
        for (int i=0;i<size;i++) parent[i] = i;
    }

    int root(int x){
        if (parent[x] == x) return x;
        int r = root(parent[x]);
        diff_weight[x] += diff_weight[parent[x]];
        return parent[x] = r;
    }

    void unite(int x,int y, int w){
        w+= weigth(x);
        w-= weigth(y);
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        parent[ry] = rx;
        diff_weight[ry] = w;
        connection_size[rx] += connection_size[ry];
        connection_size[ry] = 0;
    }

    int weigth(int x){
        root(x);
        return diff_weight[x];
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

    int diff(int x, int y){
        return weigth(y) - weigth(x);
    }

};

int main(){
    cout << "Hello World" << endl;
    return 0;
}