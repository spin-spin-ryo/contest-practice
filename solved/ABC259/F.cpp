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
using  vector2d = vector<vector<ll> >;

class node{
    ll value;
    ll parent = -1;
    ll parent_edge = 1;
    vector<pair<ll,ll> > children;

    public:
    ll value1;
    ll value2;

    void setValue(ll v){
        value = v;
    }

    ll getValue(){
        return value;
    }

    void setParent(ll p, ll w = 1){
        parent = p;
        parent_edge = 1;
    }

    ll getParent(){
        return parent;
    }

    void addChild(ll c, ll w = 1){
        children.push_back(make_pair(c,w));
    }

    vector<pair<ll,ll> > getChildren(){
        return children;
    }

};

class tree{
    

    public:
    vector<node> nodes;
    vector<ll> distance;
    tree() = default;

    explicit tree(size_t size): nodes(size),distance(size){}
    
    void makeTree(ll start, vector<vector<ll> > graph){
        stack<ll> sta;
        ll N = graph.size();
        vector<bool> visited(N,false);
        visited[start] = true;
        distance[start] = 0;
        sta.push(start);
        while(!sta.empty()){
            ll u = sta.top();
            sta.pop();
            for (ll i=0;i<graph[u].size();i++){
                ll v = graph[u][i];
                if (!visited[v]){
                    visited[v] = true;
                    nodes[u].addChild(v);
                    nodes[v].setParent(u);
                    distance[v] = distance[u]+1;
                    sta.push(v);
                }
            }
        }
    }

    void makeTree(ll start, vector<vector<pair<ll,ll> > > graph){
        stack<ll> sta;
        ll N = graph.size();
        vector<bool> visited(N,false);
        visited[start] = true;
        sta.push(start);
        while(!sta.empty()){
            ll u = sta.top();
            sta.pop();
            for (ll i=0;i<graph[u].size();i++){
                ll v = graph[u][i].first;
                ll w = graph[u][i].second;
                if (!visited[v]){
                    visited[v] = true;
                    nodes[u].addChild(v,w);
                    nodes[v].setParent(u,w);
                    sta.push(v);
                    distance[v] = distance[u]+1;
                }
            }
        }
    }

};


int main(){
    ll N;cin >> N;
    vector<ll> d(N);
    for (ll i=0;i<N;i++) cin >> d[i];
    ll u,v,w;
    vector<vector<pair<ll,ll> > > graph(N);
    for (ll i=0;i<N-1;i++){
        cin >> u >> v >> w;
        u--;v--;
        graph[u].push_back(make_pair(v,w));
        graph[v].push_back(make_pair(u,w));
    }

    tree solver(N);

    solver.makeTree(0,graph);
    vector<pair<ll,ll> > node_dis;
    for (ll i=0;i<solver.distance.size();i++){
        node_dis.push_back(make_pair(solver.distance[i],i));
    }
    sort(node_dis.begin(),node_dis.end(),greater<pair<ll,ll> >());

    for (ll i=0;i<N;i++){
        ll u = node_dis[i].second;
        node n = solver.nodes[u];
        vector<ll> S;
        ll value1 = 0;
        ll value2 = 0;
        vector<pair<ll,ll> >  children = n.getChildren();
        for (ll i=0;i<children.size();i++){
            ll v = children[i].first;
            ll w = children[i].second;
            node m = solver.nodes[v];
            value1 += m.value1;
            value2 += m.value1;
            if (d[v]!= 0) S.push_back(m.value2 + w -m.value1);
        }
        sort(S.begin(),S.end(),greater<ll>());
        for (ll i=0;i<min(d[u],(ll)S.size());i++){
            if (S[i]>0){
                value1 += S[i];
                if (i < d[u]-1){
                    value2 += S[i];
                }
            }
        }
       
        solver.nodes[u].value1 = value1;
        solver.nodes[u].value2 = value2;
    }
    cout << solver.nodes[0].value1 << endl;
}