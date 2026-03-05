# スタック（LIFO）

## 概要
スタック（Stack）は LIFO（Last In First Out）構造を持つデータ構造。

## 実装方式
固定長配列を用いて実装。
スタックポインタ `sp` により要素数を管理する。

# キュー（FIFO）
## 概要
FIFO（First In First Out）構造を持つデータ構造。

## 実装方式
固定長配列を用いた **循環キュー（Circular Queue）** として実装。

取り出された領域を再利用するため、
`head` と `tail` を用いて管理する。

full： (head + 1) % N == tail   
empty： head == tail

# 連結リスト
## 概要
ポインタでノードをつなぐ動的データ構造。配列と異なり、メモリが連続している必要がない。
- 動的にサイズ変更可能
- 挿入・削除が高速O(1)
- ランダムアクセスは不可。参照にO(n)

## 実装方式
各ノードが前と次両方のポインタを持つ
```
struct Node { 
  int key;
  Node* next;
  Node* prev;
};
```
先頭を表す値を持たないノード
`Node head `  
を用いる。
