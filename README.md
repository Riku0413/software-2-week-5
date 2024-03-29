# software-2-week-5

### このリポジトリについて

- 「工学部電子情報工学科 2022年度2Aセメスター講義 ソフトウェアⅡ 第5回」で作成したプログラム
- C言語により、漸化式計算、ナップサック問題、巡回セールスマン問題を解くアルゴリズムを実装

## 課題1

### 実行環境

Apple M1, VScode

### 実行方法

ターミナルでまず以下のコードを実行しディレクトリを移動する.
```
cd ./helloworld
```

続いて,以下のコードによりコンパイルする.
```
make
```

最後に,次のように実行する.
```
bin/helloworld1
```

すると,以下のように出力される.
```
Hello,world
```

### 実装したこと

1. helloworld1.c

   float型の数値をchar型の文字列として出力

2. calc_magicnumber.c

   float型の構造に基づいて,char型のビット列をfloat型に変換



## 課題2

### 実行方法

ターミナルでまず以下のコードを実行しディレクトリを移動する.
```
cd ./fibo
```

続いて,以下のコードによりコンパイルする.
```
make
```

最後に,次のように実行する.
```
bin/main
```

すると,以下のように第20項目までが出力される.
```
0
1
2
3
5
8
13
21
34
55
89
144
233
377
610
987
1597
2584
4181
6765
10946
```

### 実装したこと

1. obj.h

   2×2行列を表す構造体の定義,関数の宣言

2. func.c

   関数の定義

3. main.c

   フィボナッチ数列の第20項目までの出力



## 課題3

### 実行方法

ターミナルでまず以下のコードを実行しディレクトリを移動する.
```
cd ./knapsack1
```

続いて,以下のコードによりコンパイルする.
```
make
```

最後に,次のように実行する.
```
bin/knapsack1 sample.dat 20.0
```

すると,以下のようにバイナリファイルが読み込まれ,最適解が出力される.
```
max capacity: W = 20, # of items: 3
v[0] = 15.0, w[0] = 13.2
v[1] = 10.0, w[1] =  4.8
v[2] =  7.0, w[2] = 10.5
----
000, total_value =   0.0, total_weight =   0.0
001, total_value =   7.0, total_weight =  10.5
010, total_value =  10.0, total_weight =   4.8
011, total_value =  17.0, total_weight =  15.3
100, total_value =  15.0, total_weight =  13.2
110, total_value =  25.0, total_weight =  18.0
----
best solution:
value: 25.0
```

### 実装したこと

1. item.c

   load_itemset()関数の実装

2. main.c

   load_itemset()関数によるファイルの読み込み
    


## 課題4

### 実行方法

ターミナルでまず以下のコードを実行しディレクトリを移動する.
```
cd ./tsp1
```

続いて,以下のコードによりコンパイルする.
```
make
```

最後に,次のように実行する.（第３引数は初期解の個数）
```
bin/tsp1 data/city20seed100.dat 10000
```

すると,例えば以下のように解が出力される.
```
total distance = 244.887441
14 -> 3 -> 8 -> 17 -> 13 -> 12 -> 5 -> 4 -> 19 -> 1 -> 16 -> 10 -> 15 -> 9 -> 11 -> 2 -> 7 -> 0 -> 18 -> 6 -> 14
```

### 実装したこと

1. solve.c

   山登り法の実装

2. main.c

   スタート地点が0以外の場合にも対応するように変更
