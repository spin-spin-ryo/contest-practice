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
#include <atcoder/lazysegtree>

using namespace std;
using ll = long long;
#define mod 998244353
#define INF 1e+16
#define rep(i, x) for(int i = 0; i < (x); i++)

using  vector2d = vector<vector<int> >;


using S = long long;
using F = long long;
// 区間和区間加算
S op(S a, S b){
  return a+b;
}
S e(){
  return 0;
}
S mapping(F f, S x){ return f+x; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

// 区間加算、区間最小値
S op(S a, S b){
  return min(a,b);
}
S e(){
  return INF;
}
S mapping(F f, S x){ return f+x; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

int main(){
  atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(10);
}

