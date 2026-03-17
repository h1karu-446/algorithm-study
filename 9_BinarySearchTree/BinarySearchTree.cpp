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
    } else if (command == "print"){
      print();
    }
  }

  return 0;
}