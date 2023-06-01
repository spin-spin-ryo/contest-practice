#include<iostream>
#include<vector>

using namespace std;

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
    int N = 10;
    vector<long long> v(N);
    for (int i=0;i<N;i++) v[i] = i;
    BIT solver(v);
    solver.add(0,1);
    cout << solver.sum(2,10) << endl;
    
}