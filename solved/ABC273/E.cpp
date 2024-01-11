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
#define mod 998244353
#define INF 1e+16
using  vector2d = vector<vector<ll> >;

int main(){
    ll Q; cin >> Q;
    string query;
    ll x;
    vector<string> queries;
    vector<ll> X;
    map<ll,ll> load_write;
    map<ll,ll> x_write_index;
    ll initial_length = 0;
    ll length = 0;
    map<ll,ll> length_memo;
    ll write_index = -1;
    map<ll,vector<ll>> need_index;
    vector<ll> indexes;
    indexes.push_back(0);
    for (ll i=0;i<Q;i++){
        cin >> query;
        if (query != "DELETE"){
            cin >> x;
            X.push_back(x);
        }else{
            X.push_back(-1);
        }
        queries.push_back(query);

        if (query == "ADD"){
            length ++;
        }

        if (query == "DELETE"){
            if (length>0) length --;
            if ((length < initial_length) & (length > 0)){
                indexes.push_back(length-1);
                initial_length --;
            }
        }

        if (query == "LOAD"){
            if (write_index != -1){
                if (need_index[write_index].size() < indexes.size()){
                    need_index[write_index].resize(indexes.size());
                    copy(indexes.begin(),indexes.end(),back_inserter(need_index[write_index]));
                }
            }
            indexes.clear();
            initial_length = length_memo[x];
            length = initial_length;
            if (length>0) indexes.push_back(length-1);
            write_index = x_write_index[x];
        }

        if (query == "SAVE"){
            x_write_index[x] = i+1;
            length_memo[x] = length;
        }
    }

    need_index[write_index] = indexes;
    
    
    vector<ll> values;
    map<ll,vector<ll>> need_vectors;
    for (ll i=0;i<Q;i++){
        query = queries[i];
        
        if (query == "ADD"){
            values.push_back(X[i]);
        }
        
        if (query == "DELETE"){
            if (values.size() >0) values.pop_back();
        }
        
        if (query == "LOAD"){
            values.clear();
            auto itr = need_vectors.find(X[i]);
            if (itr!= need_vectors.end()){
                values.resize(need_vectors[X[i]].size());
                copy(need_vectors[X[i]].begin(),need_vectors[X[i]].end(),back_inserter(values));
            }
        }

        if (query == "SAVE"){
            indexes.clear();
            indexes.resize(need_index[i+1].size());
            copy(need_index[i+1].begin(),need_index[i+1].end(),back_inserter(indexes));
            vector<ll> save_values;  
            save_values.clear();
            for (ll j=(ll)indexes.size()-1;j>=0;j--){
                if (indexes[j] < values.size()){
                    save_values.push_back(values[indexes[j]]);
                }
                
            }
            need_vectors[X[i]].clear();
            need_vectors[X[i]].resize(save_values.size());
            copy(save_values.begin(),save_values.end(),back_inserter(need_vectors[X[i]]));
        }
            
        
        if (values.size() == 0){
            cout << -1 << " ";
        }else{
            cout << values[(ll)values.size()-1] << " ";
        }
    }
}