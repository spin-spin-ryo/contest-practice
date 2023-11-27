# 忘れがちなことメモ
## 三項間演算子忘れがち 
(cond?x:y) condがtrueならx 

## ラムダ式
auto mod2 = [](int x) { return x % 2;};
auto mod2 = [&](int x) { return x % 2;};

## 全点間対最短路 (Warshall Floyd)
