#include <iostream>
#include "BinaryTreeNode.cpp"

using namespace std;

Node Tree[MAX];

void makeTree(int n){
  for(int i = 0; i < n; i++){
    int id, l, r;
    cin >> id >> l >> r;
    Tree[id].setChild(l, r);
    if (l != -1) Tree[l].setParent(id);
    if (r != -1) Tree[r].setParent(id);
  }
}

int getRoot(int n){
  for (int i = 0; i < n; i++){
    if (Tree[i].getParent() == NIL){
      return i;
    }
  }
  return NIL;
}

void PreOrder(int id){
  if (id == NIL) return;
  cout << " " << id;
  PreOrder(Tree[id].getLeftChild());
  PreOrder(Tree[id].getRightChild());
}

void InOrder(int id){
  if (id == NIL) return;
  
  InOrder(Tree[id].getLeftChild());
  cout << " " << id;
  InOrder(Tree[id].getRightChild());
}

void PostOrder(int id){
  if (id == NIL) return ;

  PostOrder(Tree[id].getLeftChild());
  PostOrder(Tree[id].getRightChild());
  cout << " " << id;
}

int main(){
  int n;
  cin >> n;
  makeTree(n);

  cout << "Preorder" << endl;
  PreOrder(getRoot(n));
  cout << endl;

  cout << "Inorder" << endl;
  InOrder(getRoot(n));
  cout << endl;

  cout << "Postorder" << endl;
  PostOrder(getRoot(n));
  cout << endl;

  return 0;
}