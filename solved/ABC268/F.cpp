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

using namespace std;
using ll = long long;
#define mod 998244353
using  vector2d = vector<vector<int> >;

int main(){
    int N;cin >> N;
    vector<string> S(N);
    vector<int> count_x(N);
    vector<int> point_string(N);
    vector<int> point_full(N);
    int total_point = 0;
    for (int i=0;i<N;i++){
        cin >> S[i];
        int now_point = 0;
        int full_point = 0;
        for (int j=0;j<S[i].size();j++){
            if (S[i][j]=='X'){
                count_x[i]++;
            }else{
                full_point += (int)(S[i][j] - '0');
                now_point += (int)(S[i][j] - '0') * count_x[i];
            }
        }
        point_string[i] = now_point;
        point_full[i] = full_point;
        total_point += full_point;
    }
    priority_queue<pair<int,pair<int,int>>> que;
    for (int i=0;i<N;i++){
        que.push(make_pair(- point_full[i],make_pair(count_x[i],i)));
    }
    int ans = 0;
    int deleted_point = 0;
    while (!que.empty()){
        pair<int,pair<int,int>> p = que.top();
        que.pop();
        int index = p.second.second;
        int point = (total_point + p.first - deleted_point)*count_x[index] + point_string[index];
        ans += point;
        deleted_point += point_full[index]; 
    }
    cout << ans << endl;
}