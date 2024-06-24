// 次のクエリを処理する
// ・区間[l,r)について配列a_i <= Kであるような要素の数を求める。
// ・区間[l,r)について配列a_i <= Kであるような要素の総和を求める。
// 0-indexed
// 前計算量 O(NlogN)
// クエリ O(logN^2)
// debug用問題　https://atcoder.jp/contests/abc339/tasks/abc339_g
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
#define INF 1e+10
#define rep(i, x) for(int i = 0; i < (x); i++)



class merge_sort_tree{
  merge_sort_tree() = default;
  public:
  int n;
  vector<vector<ll>> seg;
  vector<vector<ll>> seg_accumulate;
  merge_sort_tree(vector<ll> a){
    int x = 1;
    int _n = a.size();
    while (_n>x){
        x*= 2;
    }
    n = x;
    seg.resize(2*n);
    seg_accumulate.resize(2*n);
    rep(i,n-_n){
      a.push_back(INF);
    }
    for (int i = 2*n -1   ;i>0;i--){
      if (i> n-1){
        seg[i].push_back(a[i - n]);
      }else{
        seg[i] = merge(seg[2*i],seg[2*i+1]);
      }
    }
    for(int i=1;i<seg.size();i++){
      seg_accumulate[i].resize(seg[i].size());
      rep(j,seg[i].size()){
        if (j==0){
          seg_accumulate[i][j] = seg[i][j];
        }else{
          seg_accumulate[i][j] = seg[i][j] + seg_accumulate[i][j-1];
        }
      }
    }
    
    return;
  }
  vector<ll> merge(vector<ll> &a, vector<ll> &b){
    vector<ll> c;
    int index1 = 0;
    int index2 = 0;
    int aLength = a.size();
    int bLength = b.size();
    while(index1 < aLength | index2 < bLength){
      if (index1 < aLength & index2 < bLength){
        if (a[index1] < b[index2]){
          c.push_back(a[index1]);
          index1++;
        }else{
          c.push_back(b[index2]);
          index2++;
        }
      }else if(index1 < aLength & index2 == bLength){
        c.push_back(a[index1]);
        index1++;
      }else{
        c.push_back(b[index2]);
        index2++;
      }
    }
    return c;
  }

  int inner_count(vector<ll> &v, ll k){
    auto itr = upper_bound(v.begin(),v.end(),k);
    return (int)(itr - v.begin());
  }

  ll inner_sum(vector<ll> &v, vector<ll> &v_accumulate, ll k){
    if (v[0] > k) return 0;
    auto itr = upper_bound(v.begin(),v.end(),k);
    int index = (int)(itr - v.begin());
    if (index > 0) return v_accumulate[index - 1];
    else return 0;
  }

  int count_query(ll k,ll l, ll r){
    return count_less_k(k,l,r,1,0,n);
  }

  int count_less_k(ll k, int l, int r, int index, int a, int b){
    if (r <= a || b <= l){
      return 0;
    }else{
      if (l <= a && b <= r){
        return inner_count(seg[index],k);
      }
    }
    return count_less_k(k,l,r,2*index,a,(a+b)/2) + count_less_k(k,l,r,2*index+1,(a+b)/2,b);
  }

  ll sum_query(ll k,ll l, ll r){
    return sum_less_k(k,l,r,1,0,n);
  }

  ll sum_less_k(ll k, int l, int r, int index, int a, int b){
    if (r <= a || b <= l){
      return 0;
    }else{
      if (l <= a && b <= r){
        return inner_sum(seg[index],seg_accumulate[index],k);
      }
    }
    return sum_less_k(k,l,r,2*index,a,(a+b)/2) + sum_less_k(k,l,r,2*index+1,(a+b)/2,b);
  }
};

int main(){
  ll n;cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  merge_sort_tree solver(a);
  int q;cin >> q;
  ll prev=0;
  while (q>0){
    q--;
    ll alpha,beta,gamma; cin >> alpha >> beta >> gamma;
    ll l = alpha ^ prev;
    ll r = beta ^ prev;
    ll k = gamma ^ prev;
    l--;r--;
    prev = solver.sum_query(k,l,r+1);
    cout << prev << endl;
  }
}