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
    int N;cin >> N;
    vector<vector<vector<int>>> grid(100,vector<vector<int>>(100,vector<int>(100,0)));
    rep(i,N){
        int x1,x2,y1,y2,z1,z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        for (int x = x1;x<x2;x++){
            for(int y = y1;y<y2;y++){
                for(int z = z1;z<z2;z++){
                    grid[x][y][z] = i+1;
                }
            }
        }
    }

    map<pair<int,int>,int> count;
    vector<int> ans(N,0);

    for (int x=0;x<100;x++){
        for(int y=0;y<100;y++){
            for(int z = 0;z<100;z++){
                

                if (x-1 >=0){
                    int index = grid[x][y][z];
                    int index1 = grid[x-1][y][z];
                    if (index != index1 & index!= 0 & index1 != 0){
                        if (index1 < index) swap(index,index1);
                        auto itr = count.find(make_pair(index,index1));
                        if (itr == count.end()){
                            ans[index-1]++;
                            ans[index1-1]++;
                            count.insert(make_pair(make_pair(index,index1),0));
                        }
                    }
                }
                if (x+1<100){
                    int index = grid[x][y][z];
                    int index1 = grid[x+1][y][z];
                    if (index != index1 & index!= 0 & index1 != 0){
                        if (index1 < index) swap(index,index1);
                        auto itr = count.find(make_pair(index,index1));
                        if (itr == count.end()){
                            ans[index-1]++;
                            ans[index1 -1]++;
                            count.insert(make_pair(make_pair(index,index1),0));
                        }
                    }
                }
                if (y-1 >=0){
                    int index = grid[x][y][z];
                    int index1 = grid[x][y-1][z];
                    if (index != index1 & index!= 0 & index1 != 0){
                        if (index1 < index) swap(index,index1);
                        auto itr = count.find(make_pair(index,index1));
                        if (itr == count.end()){
                            ans[index-1]++;
                            ans[index1 -1]++;
                            count.insert(make_pair(make_pair(index,index1),0));
                        }
                    }
                }
                if (y+1 <100){
                    int index = grid[x][y][z];
                    int index1 = grid[x][y+1][z];
                    if (index != index1 & index!= 0 & index1 != 0){
                        if (index1 < index) swap(index,index1);
                        auto itr = count.find(make_pair(index,index1));
                        if (itr == count.end()){
                            ans[index-1]++;
                            ans[index1 -1]++;
                            count.insert(make_pair(make_pair(index,index1),0));
                        }
                    }
                }
                if (z-1 >=0){
                    int index = grid[x][y][z];
                    int index1 = grid[x][y][z-1];
                    if (index != index1 & index!= 0 & index1 != 0){
                        if (index1 < index) swap(index,index1);
                        auto itr = count.find(make_pair(index,index1));
                        if (itr == count.end()){
                            ans[index-1]++;
                            ans[index1 -1]++;
                            count.insert(make_pair(make_pair(index,index1),0));
                        }
                    }
                }
                if (z+1 <100){
                    int index = grid[x][y][z];
                    int index1 = grid[x][y][z+1];
                    if (index != index1 & index!= 0 & index1 != 0){
                        if (index1 < index) swap(index,index1);
                        auto itr = count.find(make_pair(index,index1));
                        if (itr == count.end()){
                            ans[index-1]++;
                            ans[index1 -1]++;
                            count.insert(make_pair(make_pair(index,index1),0));
                        }
                    }
                }

            }
        }
    }
    // auto itr = count.begin();
    // while (itr != count.end()){
    //     cout << (*itr).first.first << " " << (*itr).first.second<< endl;
    //     itr ++;
    // }
    rep(i,N){
        cout << ans[i] << endl;
    }
}