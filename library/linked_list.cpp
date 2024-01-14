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

int main(){
    linked_list<int> a;
    linked_list<int> b;
    linked_list<int> c;
    linked_list<int> d;
    linked_list<int> e;

    a.append(10);
    b.append(8);
    c.append(7);
    d.append(6);
    e.append(1);
    b.append_list(c);
    a.append_list(b);
    a.append_list(d);
    // a.append_list(e);
    a.show();
}