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

int main(){
    string s = "wbwbwwbwbwbw";
    string p = "";
    int w,b; cin >> w >> b;
    rep(i,100){
        p += s;
    }
    bool isExist = false;
    rep(i,p.size() - w -b){
        int count_w = 0;
        int count_b = 0;
        rep(j,w+b){
            if (p[i+j] =='w'){
                count_w ++;
            }else{
                count_b++;
            }
        }
        if (count_w == w & count_b == b){
            isExist = true;
        }
    }
    if (isExist){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    
}