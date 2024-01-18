# 忘れがちなことメモ
## 三項間演算子忘れがち 
(cond?x:y) condがtrueならx 

## ラムダ式
auto mod2 = [](int x) { return x % 2;};
auto mod2 = [&](int x) { return x % 2;};
https://cpprefjp.github.io/lang/cpp11/lambda_expressions.html

## 全点間対最短路 (Warshall Floyd)

## Moのアルゴリズム
クエリの平方根で分割するの面白い

## 当たったバグ
再帰関数について
https://everykalax.hateblo.jp/entry/2022/04/08/163635
そもそもでかい構造体を引数に使う関数を使うときはアドレス参照にしないと遅い。

## ゲーム理論的なやつ
Grundy数 : ゲームの盤面を非負整数で表したもの。0ならば先手負け。それ以外は価値。
Grundy数 = 0 (if 定義よりわかる負け) else mex(現在の盤面から遷移できるGrundy数の集合)

mex(S) = Sに含まれない最小の非負整数。
Grundy数同士は独立？なもの同士でxorで合成できるらしい
例：Nimは各山のGrundy数が石の数に一致して、複数の山のGrundy数をxorで合成できる。

## ソート
~~sortをした配列とそれに関する難かしらの量を保持するような構造は存在しなさそう？~~
ヒープを二つ使えばやっぱりできました。（ヒープでも最大値最小値はすぐとりだせるという当たり前のことを失念していた）

## クラス
定期的に書かないと忘れる
https://cpprefjp.github.io/lang/cpp11/defaulted_and_deleted_functions.html

explicit: 暗黙的型変換を禁止する

## たまに当たる問題
(a,b)と(a_i,b_i)に対してa>=a_i, b>=b_iとなるものが存在するか→seg木と座圧でいける。

xor minimization ↓bit にぶんき

## 全探索系
あまり出ないので解けない。再帰関数を使うとやりやすい？

## 可変変数
reserveしてmallocしないとばぐることがあるらしい

## unordered_map
キーにハッシュ関数を適用できるものじゃないとエラります？？</br>
https://qiita.com/ganyariya/items/df35d253726269bda436
