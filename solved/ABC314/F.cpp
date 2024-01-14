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

template<typename T>
struct node{
    public:
    T value;
    node<T> *next_pointer = NULL;

    void set_next_pointer(node<T> *n){
        next_pointer = n;
    }
};


template<typename T>
struct linked_list
{
    public:
    node<T> *front_node = NULL;
    node<T> *last_node = NULL;
    int size_ = 0;

    linked_list() = default;
    void append(T m){
        size_ ++;
        node<T> *n;
        n = new node<T>;
        (*n).value = m;
        if (!front_node){
            front_node = n;
        }else{
            if (!last_node){
                last_node = n;
                front_node->set_next_pointer(n);
            }else{
                last_node->set_next_pointer(n);
                last_node = n;
            }
        }
    }   

    int size(){
        return size_;
    }

    void append_list(linked_list<T> li){
        // liは
        if (li.size() == 0) return;
        if (size_ == 1){
            front_node->set_next_pointer(li.front_node);
            if (li.size() == 1){
                last_node = li.front_node;
            }else{
                last_node = li.last_node;
            }
            
            
        }else{
            last_node->set_next_pointer(li.front_node);
            if (li.size() == 1){
                last_node = li.front_node;
            }else{
                last_node = li.last_node;
            }
            
        }
        size_ += li.size();
    }

    void show(){
        node<int> top = *front_node;
        while (top.next_pointer){
            cout << top.value << endl;
            top = *top.next_pointer;
        }
        cout << top.value << endl;
    }
};
class UnionFind{
    vector<int> parent;
    


    public:
    vector<int> connection_size;
    vector<linked_list<int>> list_nodes;
    explicit UnionFind(size_t size):parent(size){
        connection_size.resize(size,1);
        list_nodes.resize(size);
        for (int i=0;i<size;i++){
            parent[i] = i;
            linked_list<int> li;
            li.append(i);
            list_nodes[i] = li;
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
        if (rx < ry) swap(rx,ry);
        parent[rx] = ry;
        connection_size[ry] += connection_size[rx];
        connection_size[rx] = 0;
        // cout << "--" << endl;
        // list_nodes[ry].show();
        // cout << "-" << endl;
        // list_nodes[rx].show();
        list_nodes[ry].append_list(list_nodes[rx]);
        // cout << "#" << endl;
        // list_nodes[ry].show();
        // linked_list<int> li;
        // list_nodes[rx] = li;
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

ll power(ll n, ll r){
    ll ans = 1;
    for (int i=0;(r>>i) >0 ;i++){
        if ((r>>i)&1){
            ans *= n;
            ans %= mod;
        }
        n *= n;
        n %= mod;
    }
    return ans;
}

ll inv(ll n){
    return power(n, mod-2);
}

int main(){
    int N;cin >> N;
    
    UnionFind solver(N);
    vector<int> p(N);
    vector<int> q(N);
    rep(i,N-1){
        cin >> p[i] >> q[i];
        p[i]--;q[i]--;
        solver.unite(p[i],q[i]);
    }
    node<int> *top = solver.list_nodes[0].front_node;
    vector<int> edge2index(N,0);
    vector<int> index2edge(N,0);
    int count = 0;
    while(top->next_pointer){
        int index = (*top).value;
        edge2index[index] = count;
        index2edge[count] = index;
        count++;
        *top = *top->next_pointer;
        
    }
    int index = (*top).value;
    edge2index[index] = count;
    index2edge[count] = index;
    // rep(i,N){
    //     cout << edge2index[i] << endl;
    // }
    vector<ll> ans(N+1,0);
    UnionFind solver1(N);
    rep(i,N-1){
        int rx = solver1.root(p[i]);
        int ry = solver1.root(q[i]); 
        ll rx_size = solver1.connection_size[rx];
        ll ry_size = solver1.connection_size[ry];
        int index_rx = edge2index[rx];
        int index_ry = edge2index[ry];
        // cout << index_rx <<" " <<  rx_size<< endl;
        // cout << index_ry <<" " <<  ry_size<< endl;
        ans[index_rx] += rx_size*inv(rx_size+ry_size) % mod;
        ans[index_rx] %= mod;
        ans[index_rx + rx_size] -= rx_size*inv(rx_size+ry_size) % mod;
        ans[index_rx + rx_size] %= mod;
        ans[index_ry] += ry_size*inv(rx_size+ry_size) % mod;
        ans[index_ry] %= mod;
        ans[index_ry + ry_size] -= ry_size*inv(rx_size+ry_size) % mod;
        ans[index_ry + ry_size] %= mod;
        solver1.unite(p[i],q[i]);
    }
    rep(i,N){
        ans [i+1] += ans[i];
        ans[i+1] %= mod;
        if (ans[i+1] < 0) ans[i+1] += mod;
    }
    rep(i,N){
        cout << ans[edge2index[i]] << " ";
    }
    cout << endl;
}