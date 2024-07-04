#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <algorithm>
#include <stack>
#include <utility>
#include <queue>
#include <unordered_map>
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
#define rep(i, x) for(ll i = 0; i < (x); i++)

bool isExist = false;

using  vector2d = vector<vector<ll> >;

int main(){
  ll n; cin >> n;
  string s; cin >> s;
  string t; cin >> t;
  vector<vector<ll>> alphabet_counter(26,vector<ll>(s.size() + 1,0));
  rep(i,s.size()){
    rep(j,26){
      if (j == (int)(s[i]-'a')){
        alphabet_counter[j][i+1] = alphabet_counter[j][i] + 1;
      }else{
        alphabet_counter[j][i+1] = alphabet_counter[j][i];
      }
    }
  }

  ll l = 0;
  ll r = 100000000000000001;
  int s_len = s.size();
  while (r-l > 1){
    ll k = (r+l)/2;
    ll loop_time = 0;
    ll index = 0;
    rep(i,t.size()){
      int char_index = (int)(t[i] - 'a');
      ll counter = k;
      if (alphabet_counter[char_index][s_len] == 0){
        cout << 0 << endl;
        return 0;
      }
      if (loop_time > n){
        break;
      }
      if (alphabet_counter[char_index][s_len] - alphabet_counter[char_index][index] < counter){
        counter -= alphabet_counter[char_index][s_len] - alphabet_counter[char_index][index];
        loop_time ++;
        index = 0;
      }else{
        auto itr = lower_bound(alphabet_counter[char_index].begin(),alphabet_counter[char_index].end(),counter  + alphabet_counter[char_index][index] );
        index = itr - alphabet_counter[char_index].begin();
        continue;
      }
      loop_time += counter/alphabet_counter[char_index][s_len];
      counter = counter%alphabet_counter[char_index][s_len];
      if (counter == 0){
        loop_time--;
        auto itr = lower_bound(alphabet_counter[char_index].begin(),alphabet_counter[char_index].end(),alphabet_counter[char_index][s_len] );
        index = itr - alphabet_counter[char_index].begin();
        continue;
      }
      auto itr = lower_bound(alphabet_counter[char_index].begin(),alphabet_counter[char_index].end(),counter);
      index = itr - alphabet_counter[char_index].begin();
    }
    if (index >0) loop_time++;
    if (loop_time <= n){
      l = k;
    }else{
      r = k;
    }
  }
  cout << l << endl;

}