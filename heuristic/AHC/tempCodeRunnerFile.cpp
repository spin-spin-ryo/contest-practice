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
#include <cassert>
#include <random>

using namespace std;
using ll = long long;
#define mod 998244353
#define INF 1e+16
#define rep(i, x) for(int i = 0; i < (x); i++)
#define MAX_H (int)10000
#define MAX_W (int)10000
#define MOVE_MAX (int)10

double get_score(double r, double s, int x, int y,int left, int bottom, int right, int top){
    if ( left <= x & x < right & bottom <= y & y < top){
        return 1 -  (1 - min(r,s)/max(r,s))*(1 - min(r,s)/max(r,s));
    }else{
        return 0;
    }
}

double get_total_score(vector<double> area, vector<int> center_x, vector<int> center_y,vector<vector<int>> points){
    int N = points.size();
    double ans = 0;
    rep(i,N){
        int left,bottom,right,top;
        left = points[i][0];
        bottom = points[i][1];
        right = points[i][2];
        top = points[i][3];
        double s = (top - bottom)*(right - left);
        ans += get_score(area[i],s,center_x[i],center_y[i],left,bottom,right,top)/N;
    }
    return (1e+9)*ans;
}



#define Napier 2.71828182845904523536028747135
#define rep(i, x) for(int i = 0; i < (x); i++)

random_device seed_gen;
default_random_engine engine(seed_gen());
uniform_real_distribution<> dist(0,1.0);
uniform_int_distribution<> dist_int(0, 12);


class State{
    public:
    vector<vector<int>> points;
    State() = default;
    State(int n){
        points.resize(n);
        rep(i,n){
            points[i].resize(4);
        }
    }
    void show(){
        rep(i,points.size()){
            cout << points[i][0] << " " << points[i][1] << " " << points[i][2] << " " << points[i][3] << endl;
        }
    }
};

class SimulatedAnnealing{
    public:
    State now_state;
    State best_state;
    double now_energy;
    double best_energy;

    vector<int> X,Y;
    vector<double> R;
    vector<vector<int>> used;
    


    void set_X(vector<int> _X){
        X = _X;
    }

    void set_R(vector<double> _X){
        R = _X;
    }
    void set_Y(vector<int> _X){
        Y = _X;
    }

    void show_result(){
        best_state.show();
    }


    void run(int max_iter){
        generate_initial();
        now_energy = get_energy(now_state);
        best_energy = now_energy;
        rep(now_iter,max_iter){
            State next_state = get_neighbor();
            // cout << now_energy << endl;
            double next_energy = get_energy(next_state);
            // cout << next_energy << endl;
            if (next_energy < now_energy){
                best_state = next_state;
                best_energy = next_energy;
            }
            double T = get_temperature(now_iter,max_iter);
            double r = dist(engine);
            if (r < get_probability(now_energy,next_energy,T)){
                now_state = next_state;
                now_energy = next_energy;
            }
        }
    }

    private:
    void generate_initial(){
        used.resize(MAX_H+1);
        rep(i,MAX_H+1){
            used[i].resize(MAX_W+1,0);
        }
        State init_s(X.size());
        rep(i,X.size()){
            init_s.points[i][0] = X[i];
            init_s.points[i][1] = Y[i];
            init_s.points[i][2] = X[i] + 1;
            init_s.points[i][3] = Y[i] + 1;
            used[X[i]][Y[i]] = 1;
        }
        now_state = init_s;
        best_state = init_s;
    }


    double get_temperature(int now_iter, int max_iter){
        return 1 - ( ((double)now_iter + 1)/(double)max_iter);
    }

    State get_neighbor(){
        State temp_state = now_state;
        int n = temp_state.points.size();
        rep(i,n){
            int m = dist_int(engine);
            int direction = m/3;
            int left,bottom,right,top;
            left = temp_state.points[i][0];
            bottom = temp_state.points[i][1];
            right = temp_state.points[i][2];
            top = temp_state.points[i][3];
            if (direction == 0){
                int next_x = right;
                for( int new_x = right+1;new_x < min(MAX_W+1,right+MOVE_MAX+1);new_x++){
                    bool can_use = true;
                    for(int l = bottom;l < top;l++){
                        if (used[new_x-1][l]){
                            can_use = false;
                            continue;
                        }
                    }
                    if (can_use) next_x = new_x;
                    else continue;
                }
                for(int x=right;x < next_x;x++){
                    for(int y = bottom;y< top;y++){
                        used[x][y] = 1;
                    }
                }
                temp_state.points[i][2] = next_x;
            }
            if (direction == 1){
                int next_y = top;
                for( int new_y = top+1;new_y < min(MAX_H+1,top+1+MOVE_MAX);new_y++){
                    bool can_use = true;
                    for(int l = left;l < right;l++){
                        if (used[l][new_y-1]){
                            can_use = false;
                            continue;
                        }
                    }
                    if (can_use) next_y = new_y;
                    else continue;
                }
                for(int x=left;x < right;x++){
                    for(int y = top;y< next_y;y++){
                        used[x][y] = 1;
                    }
                }
                temp_state.points[i][3] = next_y;
            }
            if (direction == 2){
                int next_x = left;
                for( int new_x = left - 1;new_x >= max(0,left-1-MOVE_MAX);new_x--){
                    bool can_use = true;
                    for(int l = bottom;l < top;l++){
                        if (used[new_x][l]){
                            can_use = false;
                            continue;
                        }
                    }
                    if (can_use) next_x = new_x;
                    else continue;
                }
                for(int x=left-1;x>= next_x;x--){
                    for(int y = bottom;y< top;y++){
                        used[x][y] = 1;
                    }
                }
                temp_state.points[i][0] = next_x;
            }
            if(direction == 3){
                int next_y = bottom;
                for( int new_y = bottom-1;new_y >= max(0,bottom - 1-MOVE_MAX);new_y--){
                    bool can_use = true;
                    for(int l = left;l < right;l++){
                        if (used[l][new_y]){
                            can_use = false;
                            continue;
                        }
                    }
                    if (can_use) next_y = new_y;
                    else continue;
                }
                for(int x=left;x < right;x++){
                    for(int y = bottom - 1;y>= next_y;y--){
                        used[x][y] = 1;
                    }
                }
                temp_state.points[i][1] = next_y;
            }
        }

        return temp_state;
    }

    double get_energy(State state){
        return -get_total_score(R,X,Y,state.points);
    }

    double get_probability(double now_energy, double next_energy,double temperature){
        if (now_energy >= next_energy){
            return 1;
        }else{
            double e = Napier;
            return pow(e,(now_energy - next_energy)/temperature);
        }
    }

    

};
int main(){
    int n; cin >> n;
    vector<int> x(n),y(n);
    vector<double> area(n);
    rep(i,n){
        cin >> x[i] >> y[i] >> area[i];
    }
    SimulatedAnnealing solver;
    solver.set_X(x);
    solver.set_Y(y);
    solver.set_R(area);
    int max_iter = 1000;
    solver.run(max_iter);
    solver.show_result();
}