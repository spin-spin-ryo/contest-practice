#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> row(3);

bool find = false;

int n;
string r,c;

vector<string> grid;

void dfs(int i, int fl){
    if (find) return;
    if (i==n){
        if (fl == 0){
            cout << "Yes" << endl;
            for (auto &nx:grid){cout << nx << endl;}
            find = true;
        }
        return;
    }
    for (auto &nx:row[r[i] - 'A']){
        grid.push_back(nx);
        int ufl = fl;
        bool und = true;
        for(int j =0;j<n;j++){
            if (nx[j] == '.') continue;
            int kind = (nx[j] - 'A'):
            if ((fl & (1<< (4*j+kind)))== 0) {und = false; break;}
            ufl^= (1<<(4*j+kind));
            if ((fl&(1<<(4*j+3)))!=0){
                if (nx[j]!= c[j]){und = false;break;}
                ufl ^= (1<< 4*j+3);
            }
        }
        if(und) dfs(i+1,ufl);
        grid.poop_back();
    }
}

int main(){
    cin >> n >> r >> c;
    string abc = "ABC";
    while (abc.size() < ) abc.push_back('.');
    sort(abc.begin(),abc.end());
    do{
        char tg = '.';
        for (auto &nc: abs){
            if (nx != '.') { tg = nx;break;}
        }
        row[tg - 'A'].push_back(abc);
    }while(next_permuation(abc.begin(),abc.end()));

    dfs(0,(1<<(4*n))-1);
}

