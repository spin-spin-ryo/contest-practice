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
using  vector2d = vector<vector<int> >;

class BIT{
    // 1-indexed
    public:

    BIT() = default;
    // 入力は0-indexed
    explicit BIT(size_t size): m_bit(size+1){}

    explicit BIT(const vector<long long>& v) : m_bit(v.size()+1){
        for (int i=0;i<v.size();i++){
            add((i+1),v[i]);
        }
    }

    // a[1] + ... + a[r]
    long long sum(int r) const{
        long long ret = 0;
        for (; 0< r;r-=(r& -r)){
            ret += m_bit[r];
        }

        return ret;
    }

    // a[l] +  ... + a[r]
    long long sum(int l, int r) const{
        return (sum(r) - sum(l-1));
    }

    void add(int i, long long value){
        for (;i< m_bit.size();i+= (i& -i)){
            m_bit[i] += value; 
        }
    }

    private:
    
    vector<long long> m_bit;

};

bool check_ascending(string S,int index){
    char s = S[index];
    if (S.size() == 1) return true;
    if ((index == 0) | (index == S.size() -1)){
        if (index==0){
            char s_after = S[index+1];
            return s <= s_after;
        }
        if (index == S.size() -1){
            char s_before = S[index -1];
            return s_before <= s;
        }
    }else{
        char s_before = S[index-1];
        char s_after = S[index+1];
        return (s_before <= s) & (s<= s_after );
    }
    return true;
}

int main(){
    int N;cin >> N;
    string S;cin >> S;
    vector<BIT> alphabets(26);
    for (int i=0;i<26;i++){
        alphabets[i] = BIT(N);
    }
    BIT ascending_flag(N);
    for (int i=0;i<N;i++){
        char s = S[i];
        int index = (int)(s - 'a');
        alphabets[index].add(i+1,1);
        if (check_ascending(S,i)){
            ascending_flag.add(i+1,1);
        }
    }

    int Q;cin >> Q;
    while (Q>0){
        Q--;
        int a,b,c;
        char s;
        cin >>a >> b;
        if (a == 2){
            cin >> c;
            int sum_flag = ascending_flag.sum(b,c);
            if (sum_flag!= c-b+1){
                cout << "No" << endl;
                continue;
            }

            char start = S[b-1];
            char end = S[c-1];
            int index_start = (int)(start - 'a');
            int index_end = (int)(end - 'a');
            bool all_flag = true;
            for (int i=index_start+1;i<index_end;i++){
                if (alphabets[i].sum(b,c) != alphabets[i].sum(1,N)){
                    all_flag = false;
                }
            }
            if (all_flag){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }else{
            cin >> s;
            char tmp_s = S[b-1];
            int now_flag = ascending_flag.sum(b,b);
            S[b-1] = s;
            if (check_ascending(S,b-1)){
                if (now_flag ==0){
                    ascending_flag.add(b,1);
                }
            }else{
                if (now_flag==1){
                    ascending_flag.add(b,-1);
                }
            }
            int index1 = (int)(tmp_s - 'a');
            int index2 = (int)(s - 'a');
            alphabets[index1].add(b,-1);
            alphabets[index2].add(b,1);

            //両隣も変更
            if (b-1>=1){
                b--;
                now_flag = ascending_flag.sum(b,b);
                if (check_ascending(S,b-1)){
                    if (now_flag ==0){
                        ascending_flag.add(b,1);
                    }
                }else{
                    if (now_flag==1){
                        ascending_flag.add(b,-1);
                    }
                }
                b++;
            }
            if (b+1<= N){
                b++;
                now_flag = ascending_flag.sum(b,b);
                if (check_ascending(S,b-1)){
                    if (now_flag ==0){
                        ascending_flag.add(b,1);
                    }
                }else{
                    if (now_flag==1){
                        ascending_flag.add(b,-1);
                    }
                }
                b--;
            }
        }
    }
} 