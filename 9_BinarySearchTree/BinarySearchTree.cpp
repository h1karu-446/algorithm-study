#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct Node {
  int key;
  Node *parent, *left, *right;
};

Node *root, *NIL;  //静的記憶領域を持つ変数はゼロ(NULL)に初期化されるからこれでroot == NIL == NULLになってる。

void insert(int key){
  Node *current, *parent, *self;

  self = (Node *)malloc(sizeof(Node));
  self->key = key;
  self->left = NIL;
  self->right = NIL;

  current = root;
  parent = NIL;

  while(current != NIL){
    parent = current; //親を設定
    if (parent->key > self->key){
      current = parent->left;
    } else {
      current = parent->right;
    }
  }

  self->parent = parent;
  if (parent == NIL){ //木が空の時
    root = self;
  } else {
    if (parent->key > self->key){
      parent->left = self;
    } else {
      parent->right = self;
    }
  }
}

Node* find(int key){
  Node *current;

  current = root;
  while(current != NIL && current->key != key){
    if (current->key > key){
      current = current->left;
    } else {
      current = current->right;
    }
  }
  return current;
}

void inOrder(Node *u){
  if (u == NIL) return ;
  inOrder(u->left);
  cout << " " << u->key;
  inOrder(u->right);
}

void preOrder(Node *u){
  if (u == NIL) return;
  cout << " " << u->key;
  preOrder(u->left);
  preOrder(u->right);
}

void print(){
  inOrder(root);
  cout << endl;
  preOrder(root);
  cout << endl;
}

Node *getMinimum(Node *N){
  while(N->left != NIL){
    N = N->left;
  }
  return N;
}

Node *getSuccessor(Node* N){
  // Nに右の子があるなら右部分木で一番小さい(左にある)ノードが次ノード (deleteNode()ではこのif文は絶対にtrue)
  if (N->right != NIL){
    return getMinimum(N->right);
  }
  
  // Nに右の子がない場合、親を辿る必要がある
  Node *p = N->parent;

  // 自分が「親の左の子」になっている最初の祖先が、次のノードになる
  // もしそのような祖先が存在しない場合（自分が最も右のノード）は、次ノードはNIL
  while(p != NIL && N == p->right){
    N = p;
    p = p->parent;
  }
  return p;
}

void deleteNode(int key){
  Node *target; //削除したいkeyを持つノード
  Node *y; //実際に削除されるノード
  Node *child;  //yの子

  target = find(key);  //対象のノードを見つける
  if (target == NIL) return;

  if(target->left != NIL && target->right != NIL){  //対象のノードが2つ子を持つとき  
    y = getSuccessor(target); //右の子を持つのでNILが返ることはない
  } else {
    y = target;
  }

  if (y->left != NIL){ 
    child = y->left;
  } else {
    child = y->right;
  }

  if(y->parent == NIL){ //消すノードがrootの時
    root = child;
  } else if (y == y->parent->left){
    y->parent->left = child;
  } else {
    y->parent->right = child;
  }

  if (child != NIL){
    child->parent = y->parent;
  }

  if (y != target) { //2つ子を持つ時、keyを上書きしてちゃんと消したいkeyを持つノードを消す
    target->key = y->key;
  }
}


int main(){
  int m, k;
  string command;
  cin >> m;

  for(int i = 0; i < m; i++){
    cin >> command;
    if (command == "insert"){
      cin >> k;
      insert(k);
    } else if (command == "find"){
      cin >> k;
      if (find(k) == NIL){
        cout << "no" << endl;
      } else {
        cout << "yes" << endl;
      }
    } else if (command == "delete"){
      cin >> k;
      deleteNode(k);
    } else if (command == "print"){
      print();
    }
  }

  return 0;
}