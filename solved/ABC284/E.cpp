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
#include <deque>
#include <list>

using namespace std;
using ll = long long;

int main(){
    int N;cin >> N;
    string S;cin >> S;
    deque<char> another_string;
    deque<char> main_string;
    for (int i=0;i<N;i++){
        main_string.push_back(S[N-1-i]);
        another_string.push_back(S[N+i]);
    }
    map<deque<char>,int> count;
    for (int i=0;i<=N;i++){
        count[main_string] = 1;
        if (count[another_string]){
            for (int j=0;j<N;j++) cout << main_string[j];
            cout << endl;
            cout << i << endl;
            return 0;
        }
        count.erase(main_string);
        if (i!=N){
            char s = main_string[N-1];
            char s2 = another_string[i];
            main_string.pop_back();
            main_string.push_front(s2);
            another_string[i] = s;
        }
    }
    cout << -1 << endl;
    return 0;
}