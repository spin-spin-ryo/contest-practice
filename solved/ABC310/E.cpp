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

char nand(char a, char b){
    if (a=='1' & b == '1') return '0';
    else return '1';
}

int main(){
    int N;cin >> N;
    string A; cin >> A;
    ll ans = 0;
    map<char,ll> count;
    count.insert(make_pair('1',0));
    count.insert(make_pair('0',0));
    rep(i,N){
        int count1 = 0;
        int count0 = 0;
        if (nand('1',A[i]) == '1'){
            count1 += count['1'];
        }else{
            count0 += count['1'];
        }

        if (nand('0',A[i]) == '1'){
            count1 += count['0'];
        }else{
            count0 += count['0'];
        }

        count['1'] = count1;
        count['0'] = count0;
        count[A[i]] ++;
        ans += count['1'];
    }
    cout << ans << endl;

}