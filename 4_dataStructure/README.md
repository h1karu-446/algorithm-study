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

# Standard Template Library
これらのデータ構造は、C++のSTLとして提供されている。

## Stack 
`#include <stack>`

- push(x): スタックにxを積む
- top(): 頂点の要素を参照
- pop(): 頂点の要素を削除
- size(): スタックの要素数を返す
- empty(): 空の時trueを返す
  
## Queue
`#include <queue>`

- push(x): キューにxを追加
- front(): 先頭の要素を参照
- pop(): 先頭の要素を削除
- size(): 要素数を返す
- empty(): 空の時trueを返す

## list
`#include <list>`

- push_front(x): 先頭にxを追加
- push_back(x): 最後にxを追加
- insert(p, x): pの位置にxを挿入。pはすでにリストにあるイテレータで、その前に挿入する
- erase(p): pの位置の要素を削除。
- pop_front(): 先頭要素を削除
- pop_back(): 最後の要素を削除
- size(): リストの要素数を返す
- begin(): リストの先頭を指すイテレータを返す
- end(): リストの末尾(最後の要素の次)を指すイテレータを返す。
- clear(): 全ての要素を削除する
- front(), back(): それぞれ先頭, 最後の要素を参照する

### イテレータ
コンテナの要素を指すポインタのようなもの  
STLには、listやvector, setなど色々なコンテナがある。それらを同じ方法で操作するために使われる。だいたいポインタと同じようなもの。

`テンプレート名<型> ::  iterator イテレータ名`: 宣言  
`*イテレータ名`: イテレータの指す要素の値を参照  
`++イテレータ名, --イテレータ名`: 次の要素や前の要素へ移動  

リストでの具体例だと
```
list<int> L = {10, 20, 30};
list<int> :: iterator it;

for (it = L.begin(); it != L.end(); ++it){
  cout << *it << endl;
}

```

# vector
要素の追加によってサイズ拡張が可能な動的配列(可変長配列)

- push_back(x): 最後のxを追加
- pop_back(): 最終要素を削除, erase(V.end()-1)と同じ
- begin(): 先頭要素を指すイテレータを返す
- end(): 末尾(最後の要素の次)を指すイテレータを返す
- insert(p, x): pの位置にxを挿入。pはすでに追加ずみのイテレータでその前に挿入される
- erase(p): pの位置の要素を削除
- clear(): 全ての要素を削除
