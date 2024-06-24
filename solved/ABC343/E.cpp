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
#define rep(i, x) for(int i = 0; i < (x); ++i)


int count_volume[15][15][15];
bool visited[15][15][15][15][15][15];
int ans[3];
int v1,v2,v3;
int x1=-1;
int ans_y1=-1;
int z1=-1;
int x2=-1;
int y2=-1;
int z2=-1;

void update_ans(int at_count,int diff){
   if (at_count == 0){
      return;
   }
   ans[at_count-1] += diff;
}

void update(int a,int b, int c, int x, int y, int z,int n){
   int I,J,K;
   int X,Y,Z;
   int A,B,C;
   switch (abs(n)){
      case 1:
         I = 1;J = 7;K = 7;
         X = a;Y = b;Z = c;
         A = 7;B=0;C=0;
         break;
      case 2:
         I = 7;J = 1;K = 7;
         X = a;Y = b; Z= c;
         A = 0;B=7;C=0;
         break;
      case 3:
         I = 7;J = 7;K= 1;
         X = a;Y = b;Z = c;
         A = 0;B=0;C=7;
         break;
      case 4:
         I = 1;J = 7;K = 7;
         X = x;Y = y;Z = z;
         A = 7;B=0;C=0;
         break;
      case 5:
         I = 7;J = 1;K = 7;
         X = x;Y = y;Z = z;
         A = 0;B=7;C=0;
         break;
      case 6:
         I = 7;J = 7;K = 1;
         X = x;Y = y;Z = z;
         A = 0;B=0;C=7;
         break;
      default:
         break;
   }
   if (n> 0){
      for (int i=0;i<I;i++){
         for (int j=0;j<J;j++){
            for (int k=0;k<K;k++){
               update_ans(count_volume[X+i][Y+j][Z+k],-1);
               count_volume[X+i][Y+j][Z+k]--;
               update_ans(count_volume[X+i][Y+j][Z+k],1);
               update_ans(count_volume[X+i+A][Y+j+B][Z+k+C],-1);
               count_volume[X+i+A][Y+j+B][Z+k+C]++;
               update_ans(count_volume[X+i+A][Y+j+B][Z+k+C],1);
            }
         }
      }
   }else{
      for (int i=0;i<I;i++){
         for (int j=0;j<J;j++){
            for (int k=0;k<K;k++){
               update_ans(count_volume[X+A+i][Y+B+j][Z+C+k],-1);
               count_volume[X+i+A][Y+j+B][Z+k+C]--;
               update_ans(count_volume[X+A+i][Y+B+j][Z+C+k],1);
               update_ans(count_volume[X+i][Y+j][Z+k],-1);
               count_volume[X+i][Y+j][Z+k]++;
               update_ans(count_volume[X+i][Y+j][Z+k],1);
            }
         }
      }
   }
   return;
}




void dfs(int a,int b, int c, int x, int y, int z){
   visited[a][b][c][x][y][z] = true;
  // cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
   if (ans[0] == v1 & ans[1] == v2 & ans[2] == v3){
      x1 = a;ans_y1 = b;z1 = c;x2 = x;y2 = y;z2 = z;
      return;
   }
   if (a<8 & !visited[a+1][b][c][x][y][z]){
      update(a,b,c,x,y,z,1);
      dfs(a+1,b,c,x,y,z);
      update(a,b,c,x,y,z,-1);
   }
   if (b<8 & !visited[a][b+1][c][x][y][z]){
      update(a,b,c,x,y,z,2);
      dfs(a,b+1,c,x,y,z);
      update(a,b,c,x,y,z,-2);
   }
   if (c<8 & !visited[a][b][c+1][x][y][z]){
      update(a,b,c,x,y,z,3);
      dfs(a,b,c+1,x,y,z);
      update(a,b,c,x,y,z,-3);
   }
   if (x<8 & !visited[a][b][c][x+1][y][z]){
      update(a,b,c,x,y,z,4);
      dfs(a,b,c,x+1,y,z);
      update(a,b,c,x,y,z,-4);
   }
   if (y<8 & !visited[a][b][c][x][y+1][z]){
      update(a,b,c,x,y,z,5);
      dfs(a,b,c,x,y+1,z);
      update(a,b,c,x,y,z,-5);
   }
   if (z<8& !visited[a][b][c][x][y][z+1]){
      update(a,b,c,x,y,z,6);
      dfs(a,b,c,x,y,z+1);
      update(a,b,c,x,y,z,-6);
   }


}
// 0<= a <= 14


int main(){
   cin >> v1 >> v2 >> v3;
   for (int i=0;i<14;i++){
      for (int j=0;j<14;j++){
         for (int k=0;k<14;k++){
            count_volume[i][j][k] = 0;
            rep(x,14){
               rep(y,14){
                  rep(z,14){
                     visited[i][j][k][x][y][z] = false;
                  }
               }
            }
         }
      }
   }
   for (int i=0;i<7;i++){
      for (int j=0;j<7;j++){
         for (int k=0;k<7;k++){
            count_volume[i][j][k] = 2;
         }
      }
   }
   for (int i=0;i<7;i++){
      for (int j=0;j<7;j++){
         for (int k=0;k<7;k++){
            count_volume[i+1][j+1][k+1]++;
         }
      }
   }
   rep(i,8){
        rep(j,8){
            rep(k,8){
                update_ans(count_volume[i][j][k],1);
            }
    }
   }
   dfs(0,0,0,0,0,0);
   if (x1 == -1){
      cout << "No" << endl;
   }else{
      cout << "Yes" << endl;
      cout << 1<< " " << 1 <<" " << 1 << " "<< x1 << " " << ans_y1 << " " << z1 << " " << x2 << " " << y2 << " " << z2 << endl;
   }
   
}