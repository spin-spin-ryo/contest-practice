# 忘れがちなことメモ
## 三項間演算子忘れがち 
(cond?x:y) condがtrueならx 

## ラムダ式
auto mod2 = [](int x) { return x % 2;};
auto mod2 = [&](int x) { return x % 2;};

## 全点間対最短路 (Warshall Floyd)

## Moのアルゴリズム
クエリの平方根で分割するの面白い

## 当たったバグ
再帰関数について
https://everykalax.hateblo.jp/entry/2022/04/08/163635

## ゲーム理論的なやつ
Grundy数 : ゲームの盤面を非負整数で表したもの。0ならば先手負け。それ以外は価値。
Grundy数 = 0 (if 定義よりわかる負け) else mex(現在の盤面から遷移できるGrundy数の集合)

mex(S) = Sに含まれない最小の非負整数。
Grundy数同士は独立？なもの同士でxorで合成できるらしい
例：Nimは各山のGrundy数が石の数に一致して、複数の山のGrundy数をxorで合成できる。