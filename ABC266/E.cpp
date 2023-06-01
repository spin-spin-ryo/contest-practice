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

using namespace std;
using ll = long long;
using ld = long double;
#define mod 998244353
using  vector2d = vector<vector<int> >;

int main(){
    int N;cin >> N;
    ld now = 3.5;
    if (N==1){
        cout << now << endl;
        return 0;
    }else{
        for (int i=0;i<N-1;i++){
            int reset_num = floor(now);
            int other = 0;
            for (int n=reset_num+1;n<=6;n++){
                other += n;
            }
            now = (ld)other/6.0 + (ld)(reset_num)/6.0*now;
        }
    }
    cout << setprecision(20) << now << endl;
}