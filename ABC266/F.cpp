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
using  vector2d = vector<vector<int> >;

template<typename T>
struct SparseTable{
    vector<vector<T> >st;
    vector<int> lookup;
    
    SparseTable() = default;
    SparseTable(const vector<T> &v){
        int b = 0;
        while ((1<<b) <= v.size()) ++b;
        st.assign(b,vector<T>(1<<b));
        for (int i=0;i<v.size();i++){
            st[0][i] = v[i];
        }

        for (int i=1;i<b;i++){
            for (int j=0;j+(1 << i) <= (1<<b);j++){
                st[i][j] = min(st[i-1][j],st[i-1][j + (1 << (i-1))]);
            }
        }
        lookup.resize(v.size() + 1);

        for (int i=2;i < lookup.size();i++){
            lookup[i] = lookup[i>> 1] + 1;
        }
    }

    inline T rmq(int l, int r){
        int b = lookup[r-l];
        return min(st[b][l],st[b][r - (1<<b)]);
    }
};

class LCA{
    public:
    LCA() = default;
    
    explicit LCA(vector<vector<int> > &g){
        V = g.size();
        first_appear.resize(V);
        visited.resize(V);
        DFS(0,0,g);
        build();
    }

    void DFS(int v, int d, vector<vector<int> > graph){
        visited[v] = true;
        first_appear[v] = euler.size();
        euler.push_back(make_pair(d,v));
        for (int i=0;i<graph[v].size();i++){
            int u = graph[v][i];
            if (!visited[u]){
                DFS(u,d+1,graph);
                euler.push_back(make_pair(d,v));
            }
        }
    }

    void build(){
        sp = SparseTable<pair<int,int>>(euler);
    }

    int lca(int u, int v){
        int p1 = first_appear[u];
        int p2 = first_appear[v];

        if (p2 < p1) swap(p1,p2);
        pair<int,int> p = sp.rmq(p1,p2+1);
        return p.second;
    }


    private:
    vector<pair<int,int> > euler;
    vector<int> first_appear;
    vector<bool> visited;
    int V;
    SparseTable<pair<int,int>> sp;
};

pair<int,int> dfs(int start,vector<vector<int> > graph){
    int V = graph.size();
    vector<bool> visited(V,false);
    vector<int> parent(V,-1);
    stack<int> st;
    st.push(start);
    parent[start] = start;
    visited[start] = true;
    while (!st.empty()){
        int u = st.top();
        st.pop();
        for (int i=0;i<graph[u].size();i++){
            int v = graph[u][i];
            if (!visited[v]){
                visited[v] = true;
                st.push(v);
                parent[v] = u;
            }else{
                if (v != parent[u]){
                    return make_pair(u,v);
                }
            }
        }
    }
    return make_pair(-1,-1);
}

int main(){
    int N;cin >> N;
    vector<vector<int> > graph(N);
    int u,v;
    for (int i=0;i<N;i++){
        cin >> u >> v;
        u--;v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    pair<int,int> p = dfs(0,graph);

    for (int i=0;i<graph[p.first].size();i++){
        if (p.second == graph[p.first][i]){
            graph[p.first].erase(graph[p.first].begin() + i);
            break;
        }
    }

    for (int i=0;i<graph[p.second].size();i++){
        if (p.first == graph[p.second][i]){
            graph[p.second].erase(graph[p.second].begin() + i);
            break;
        }
    }

    

    LCA solver(graph);
    int Q;cin >> Q;
    for (int i=0;i<Q;i++){
        cin >> u >> v;
        u--;v--;
        int z = solver.lca(u,v);

        int w1 = solver.lca(u,p.first);
        int w2 = solver.lca(v,p.second);

        if ( (solver.lca(w1,z) == z) & (solver.lca(w2,z) == z) & (w1!=w2)){
            cout << "No" << endl;
        }else{
            w1 = solver.lca(v,p.first);
            w2 = solver.lca(u,p.second);
            if ( (solver.lca(w1,z) == z) & (solver.lca(w2,z) == z) & (w1!=w2)){
                cout << "No" << endl;
            }else{
                w1 = solver.lca(v,p.first);
                w2 = solver.lca(v,p.second);
                if ( (solver.lca(w1,z) == z) & (solver.lca(w2,z) == z) & (w1!=w2)){
                    cout << "No" << endl;
                }else{
                    w1 = solver.lca(u,p.first);
                    w2 = solver.lca(u,p.second);
                    if ( (solver.lca(w1,z) == z) & (solver.lca(w2,z) == z) & (w1!=w2)){
                        cout << "No" << endl;
                    }else{
                        cout << "Yes" << endl;
                    }
                }
            }
        }
        

    }
}