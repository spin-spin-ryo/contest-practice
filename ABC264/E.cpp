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
    vector<int> count_city;
    explicit UnionFind(size_t size):parent(size){
        for (int i=0;i<size;i++){
            parent[i] =i;
        }
    }

    void set_city(int N, int M){
        count_city.resize(N+M);
        for (int i=0;i<N;i++){
            count_city[i] = 1;
        }
    }

    int root(int x){
        if (parent[x] == x) return x;
        return parent[x] = root(parent[x]);
    }

    void unite(int x,int y){
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        if (ry < rx){
            swap(rx,ry);
        }
        parent[rx] = ry;
        count_city[ry] += count_city[rx];
        count_city[rx] = 0;
    }

    bool same(int x, int y){
        int rx = root(x);
        int ry = root(y);
        return rx==ry;
    }

};

int main(){
    int N,M,E;cin >> N >> M >> E;
    vector<int> u(E);
    vector<int> v(E);
    for (int i=0;i<E;i++){
        cin >> u[i] >> v[i];
    }
    int Q;cin >> Q;
    vector<int> X(Q);
    vector<bool> initial(E,true);
    for (int i=0;i<Q;i++){
        cin >> X[i];
        initial[X[i]-1] = false;
    }
    UnionFind solver(N+M);
    solver.set_city(N,M);
    for (int i=0;i<E;i++){
        if (initial[i]){
            solver.unite(u[i]-1,v[i]-1);
        }
    }
    vector<int> ans;

    int init_ans = 0;
    for (int i= N;i<N+M;i++){
        init_ans += solver.count_city[i];
    }
    ans.push_back(init_ans);

    int a,b;
    for (int i=Q-1;i>=0;i--){
        a = u[X[i]-1]-1;
        b = v[X[i]-1]-1;

        if (( (solver.root(a) < N) & (solver.root(b) >= N)) | ((solver.root(a) >= N) & (solver.root(b) < N))){
            init_ans += solver.count_city[min(solver.root(a),solver.root(b))];
        }

        solver.unite(a,b);
        ans.push_back(init_ans);
    }
    
    for (int i=Q-1;i>=0;i--){
        cout << ans[i] << endl;
    }
    
}