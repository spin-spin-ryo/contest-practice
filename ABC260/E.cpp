#include<iostream>
#include<vector>

using namespace std;
using ll = long long;
#define mod 998244353
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

    // a[r] +  ... + a[l]
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

class BIT_RAQ{
    public:
    BIT_RAQ() = default;

    explicit BIT_RAQ(size_t size): m_bit0(size),m_bit1(size) {}

    explicit BIT_RAQ(const vector<long long>& v): m_bit0(v), m_bit1(v.size()) {}

    long long sum(int r) const{
        return (m_bit0.sum(r) + m_bit1.sum(r)*r);
    }

    long long sum(int l, int r) const{
        return (sum(r) - sum(l-1));
    }

    void add(int i, long long value){
        m_bit0.add(i,value);
    }

    void add(int l, int r, long long value){
        m_bit0.add(l ,(-value*(l-1)));
        m_bit0.add((r+1),(value*r));
        m_bit1.add(l,value);
        m_bit1.add((r+1),-value);
    }

    private:

    BIT m_bit0;
    BIT m_bit1;

};



int main(){
    int N,M;cin >> N >> M;
    vector<int> A(N);
    vector<int> B(N);
    vector2d graph(M,vector<int>());
    for (int i=0;i<N;i++){
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
        graph[A[i]].push_back(i);
        graph[B[i]].push_back(i);
    }

    BIT_RAQ solver(M);

    vector<int> count_conditions(N,0);
    int res = N;
    int l = 0;
    for (int r=0;r<M;r++){
        for (int i=0;i<graph[r].size();i++){
            if (count_conditions[graph[r][i]]==0){
                res-=1;
            }
            count_conditions[graph[r][i]]++;
        }

        if (res == 0){
            while(res == 0){
                solver.add(r-l+1,M-l,1);
                l++;
                for (int i=0;i<graph[l-1].size();i++){
                    if (count_conditions[graph[l-1][i]]==1){
                        res+=1;
                    }
                    count_conditions[graph[l-1][i]]--;
                }
            }
        }
    }

    for (int i=1;i<M+1;i++){
        cout << solver.sum(i,i) << " ";
    }
    cout << endl;
}