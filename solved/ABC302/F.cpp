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
int NODE  = 0;
int SET = 1;

int bfs(int start,vector<vector<int>> &num2set,vector<vector<int>> &set2num){
    int N = set2num.size();
    int M = num2set.size();
    vector<bool> visit_set(N,false);
    vector<bool> visit_num(M,false);
    vector<ll> dis_set(N,INF);
    vector<ll> dis_num(M,INF);
    queue<pair<int,int>> que;
    que.push(make_pair(start,NODE));
    visit_num[start] = true;
    dis_num[start] = 0;
    while (!que.empty()){
        auto p = que.front();
        que.pop();
        int n = p.first;
        int state = p.second;
        if (state == NODE){
            for (auto m:num2set[n]){
                if (!visit_set[m]){
                    dis_set[m] = dis_num[n] + 1;
                    visit_set[m] = true;
                    que.push(make_pair(m,SET));
                }
            }
        }else{
            for (auto m:set2num[n]){
                if (!visit_num[m]){
                    dis_num[m] = dis_set[n] + 1;
                    visit_num[m] = true;
                    que.push(make_pair(m,NODE));
                }
            }
        }
    }
    if (dis_num[M-1] == INF){
        return -1;
    }else{
        return (dis_num[M-1]-1)/2;
    }
}

int main(){
    int N,M;cin >> N >> M;
    vector<vector<int>> num2set(M);
    vector<vector<int>> set2num(N);
    rep(i,N){
        int a; cin >> a;
        int s;
        rep(j,a){
            cin >> s;
            s--;
            set2num[i].push_back(s);
            num2set[s].push_back(i);
        }
    }
    int ans = bfs(0,num2set,set2num);
    cout << ans << endl;

}