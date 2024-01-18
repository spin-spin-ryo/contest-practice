#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <algorithm>
#include <stack>
#include <utility>
#include <queue>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <cmath>
#include <set>
#include <list>
#include <deque>
#include <limits>
#include <random>


using namespace std;
using ll = long long;
using ld = long double;
#define mod 998244353
#define INF 1e+16
#define rep(i, x) for(int i = 0; i < (x); i++)

using  vector2d = vector<vector<int> >;


struct HashPair {

    static size_t m_hash_pair_random;

    template<class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const {

        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);

        size_t seed = 0;
        seed ^= hash1 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        seed ^= hash2 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        seed ^= m_hash_pair_random + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        return seed;
    }
};

size_t HashPair::m_hash_pair_random = (size_t) random_device()();

template <typename T>
void print(vector<T> v){
    rep(i,v.size()){
        cout << v[i] << endl;
    }
    return;
}


template<typename T>
struct edge{
    public:
    T v;
    ld cost;

    edge() = default;
    explicit edge(T _v, ld c){
        v = _v;
        cost = c;
    }
};

template<typename T>
edge<T> make_edge(T v, ld cost){
    edge<T> e(v,cost);
    return e;
}

template<typename T>
ld dijkstra(T start, T end, unordered_map<T,vector<edge<T>>,HashPair> graph){
    int N = graph.size();
    unordered_map<T,ld,HashPair> dis;
    auto itr = graph.begin();
    while (itr != graph.end()){
        auto key = (*itr).first;
        dis[key] = INF;
        itr++;
    }    
    
    priority_queue<pair<ld,T>,vector<pair<ld,T>>,greater<pair<ld,T>>> que;
    dis[start] = 0;
    que.push(make_pair(dis[start],start));
    while(!que.empty()){
        auto p = que.top();
        que.pop();
        ld d = p.first;
        T u = p.second;
        if (d > dis[u]) continue;
        for (auto e: graph[u]){
            T v = e.v;
            if (dis[v] > dis[u] + e.cost){
                dis[v] = dis[u] + e.cost;
                que.push(make_pair(dis[v],v));
            }
        }
    }
    return dis[end];
}

int main(){
    int N;cin >> N;
    vector<int> X(N);
    vector<int> Y(N);
    rep(i,N){
        cin >> X[i] >> Y[i];
    }
    int C = 40;
    
    unordered_map<pair<int,int>,vector<edge< pair<int,int> > > ,HashPair> graph;
    for(int i=0;i<N;i++){
        for(int j=i+1;j<min(N,(int)(i+1+C));j++){
            ld dis = sqrt((X[i] - X[j])*(X[i] - X[j]) +   (Y[i] - Y[j])*(Y[i] - Y[j]));
            for(int c=0;c<C;c++){
                if (c+j-i-1 < C){
                    edge<pair<int,int>> e =  make_edge(make_pair((int)j,(int)(c+j-i-1)),dis);
                    graph[make_pair(i,c)].push_back(e);
                }
            }
        }
    }
    rep(c,C){
        if (c==0){
            graph[make_pair(N-1,c)].push_back(make_edge(make_pair((int)N,(int)0),0));
        }else{
            graph[make_pair(N-1,c)].push_back(make_edge(make_pair((int)N,(int)0),pow(2,c-1)));
        }
    }
    vector<edge<pair<int,int>>> v;
    graph.insert(make_pair(make_pair((int)N,(int)0),v));
    cout << setprecision(16) <<dijkstra(make_pair((int)0,(int)0),make_pair(N,0),graph) << endl;
}