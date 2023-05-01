#include<iostream>
#include<vector>
#include <tuple>
#include <string>
#include <algorithm>
#include <stack>
#include <utility>


using namespace std;
using ll = long long;
#define mod 998244353
using  vector2d = vector<vector<int> >;

class node{
    int value;
    int parent;
    int parent_edge = 1;
    vector<pair<int,int> > children;

    public:
    
    void setValue(int v){
        value = v;
    }

    int getValue(){
        return value;
    }

    void setParent(int p, int w = 1){
        parent = p;
        parent_edge = 1;
    }

    int getParent(){
        return parent;
    }

    void addChild(int c, int w = 1){
        children.push_back(make_pair(c,w));
    }

    vector<pair<int,int> > getChildren(){
        return children;
    }

};

class tree{
    vector<node> nodes;

    public:

    tree() = default;

    explicit tree(size_t size): nodes(size){}
    
    void makeTree(int start, vector<vector<int> > graph){
        stack<int> sta;
        int N = graph.size();
        vector<bool> visited(N,false);
        visited[start] = true;
        sta.push(start);
        while(!sta.empty()){
            int u = sta.top();
            sta.pop();
            for (int i=0;i<graph[u].size();i++){
                int v = graph[u][i];
                if (!visited[v]){
                    visited[v] = true;
                    nodes[u].addChild(v);
                    nodes[v].setParent(u);
                    sta.push(v);
                }
            }
        }
    }

    void makeTree(int start, vector<vector<pair<int,int> > > graph){
        stack<int> sta;
        int N = graph.size();
        vector<bool> visited(N,false);
        visited[start] = true;
        sta.push(start);
        while(!sta.empty()){
            int u = sta.top();
            sta.pop();
            for (int i=0;i<graph[u].size();i++){
                int v = graph[u][i].first;
                int w = graph[u][i].second;
                if (!visited[v]){
                    visited[v] = true;
                    nodes[u].addChild(v,w);
                    nodes[v].setParent(u,w);
                    sta.push(v);
                }
            }
        }
    }

};


