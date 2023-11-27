// 文字列が与えられた時、各 i について「S と S[i:|S|-1] の最長共通接頭辞の長さ」を記録した配列 A を O(|S|) で構築するアルゴリズム

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

vector<int> z_algorithm(string S){
    vector<int> A(S.size());
    A[0] = S.size();
    int i = 1, j = 0;
    while (i < S.size()) {
        while (i+j < S.size() && S[j] == S[i+j]) ++j;
        A[i] = j;
        if (j == 0) { ++i; continue;}
        int k = 1;
        while (i+k < S.size() && k+A[k] < j) A[i+k] = A[k], ++k;
        i += k; j -= k;
    }
    return A;
}


int main(){
    string s = "aaabaaaab";
    vector<int> A = z_algorithm(s);
    for (int i=0;i<s.size();i++){
        cout << A[i];
    }
    cout << endl;
    return 0;
}