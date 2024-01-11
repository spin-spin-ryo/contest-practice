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

using namespace std;
using ll = long long;
#define mod 998244353
#define INF 1e+16
#define rep(i, x) for(int i = 0; i < (x); i++)

vector<int> enumerate_factor(int N){
    int d = 1;
    vector<int> factors;
    while (d*d <= N){
        if (N%d == 0){
            factors.push_back(d);
            if (N/d != d){
                factors.push_back(N/d);
            }
        }
        d++;
    }
    sort(factors.begin(),factors.end());
    return factors;
} 



template <typename T>
void print(vector<T> v){
    int N = v.size();
    rep(i,N) cout << v[i] << endl;
    cout << endl;
    return;
}

int main(){
    int n = 25;
    print(enumerate_factor(n));
    return 0;
}