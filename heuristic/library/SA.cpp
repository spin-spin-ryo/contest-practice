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
using ld = long double;

#define Napier 2.71828182845904523536028747135
#define rep(i, x) for(int i = 0; i < (x); i++)

random_device seed_gen;
default_random_engine engine(seed_gen());
uniform_real_distribution<> dist(0,1.0);


class State{
    public:
    State() = default;
    State(){

    }
};

class SimulatedAnnealing{
    public:
    State now_state;
    State best_state;
    double now_energy;
    double best_energy;

    void run(int max_iter){
        generate_initial();
        now_energy = get_energy(now_state);
        best_energy = now_energy;
        rep(now_iter,max_iter){
            State next_state = get_neighbor();
            double next_energy = get_energy(next_state);
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
        State init_s;
        now_state = init_s;
        best_state = init_s;
    }


    double get_temperature(int now_iter, int max_iter){
        return 1 - ( ((double)now_iter + 1)/(double)max_iter);
    }

    State get_neighbor(){
        State temp_state = now_state;
        return temp_state;
    }

    double get_energy(State state){

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