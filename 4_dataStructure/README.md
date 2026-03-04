# スタック（LIFO）

## 概要
スタック（Stack）は LIFO（Last In First Out）構造を持つデータ構造。

## 実装方式
固定長配列を用いて実装。
スタックポインタ `sp` により要素数を管理する。

# Queue（FIFO）
## 概要
FIFO（First In First Out）構造を持つデータ構造。

## 実装方式
固定長配列を用いた **循環キュー（Circular Queue）** として実装。

取り出された領域を再利用するため、
`head` と `tail` を用いて管理する。

full： (head + 1) % N == tail   
empty： head == tail