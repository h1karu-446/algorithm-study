#include <iostream>
#include <map>
#include <string>

using namespace std;

const int NIL = -1;
const int MAX = 25;

map<int, string> Type = {
  {1, "root"},
  {2, "internal node"},
  {3, "leaf"}
};

class Node {
  private:
    int parent, left, right, degree, depth, height, type;

  public:
    Node(){
      parent = NIL;
      left = NIL;
      right = NIL;
    }

    Node(int p, int l, int r){
      parent = p;
      left = l;
      right = r;
    }

    void setParent(int p){
      parent = p;
    }

    void setChild(int l, int r){
      left = l;
      right = r;
    }

    void setDepth(int d){
      depth = d;
    }

    void setHeight(int h){
      height = h;
    }

    void setDegree(){
      if (left == -1 && right == -1){ degree = 0; }
      else if (left == -1 || right == -1) { degree = 1; }
      else { degree = 2; }
    }

    void setType(){
      if (parent == NIL){
        type = 1;
      } else if (left == NIL && right == NIL){
        type = 3;
      } else {
        type = 2;
      }
    }

    int getParent(){
      return parent;
    }

    int getLeftChild(){
      return left;
    }
    
    int getRightChild(){
      return right;
    }

    int getDepth(){
      return depth;
    }

    int getHeight(){
      return height;
    }

    string getType(){
      return Type[type];
    }

    int getDegree(){
      return degree;
    }
};

Node BTree[MAX];

void setDepths(int u, int d){
  if (u == NIL) { return; }
  BTree[u].setDepth(d);
  setDepths(BTree[u].getLeftChild(), d+1);
  setDepths(BTree[u].getRightChild(), d+1);
}

int setHeights(int u){
  int h1 = 0, h2 = 0, h;
  if (BTree[u].getLeftChild() != NIL){
    h1 = setHeights(BTree[u].getLeftChild()) + 1;
  }
  if (BTree[u].getRightChild() != NIL){
    h2 = setHeights(BTree[u].getRightChild()) + 1;
  }
  h = max(h1, h2);
  BTree[u].setHeight(h);
  return h;
}

int getRoot(int n){
  for (int i = 0; i < n; i++){
    if (BTree[i].getParent() == NIL){
      return i;
    }
  }
  return NIL;
}

int getSibling(int i){
  int p = BTree[i].getParent();
  if (p == NIL) return NIL;
  if (BTree[p].getLeftChild() != i) return BTree[p].getLeftChild(); 
  if (BTree[p].getRightChild() != i) return BTree[p].getRightChild(); 
  return NIL;
}

void print(int n){
  for (int i = 0; i < n; i++){
    int p = BTree[i].getParent();
    int sibling = getSibling(i);
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n", i, p, sibling,  BTree[i].getDegree(), BTree[i].getDepth(), BTree[i].getHeight(), BTree[i].getType().c_str());
  }
}


int main(){
  int n;

  cin >> n;

  for (int i = 0; i < n; i++){
    int self, l, r;
    cin >> self >> l >> r;
    BTree[self].setChild(l, r);
    if (l != NIL) {
      BTree[l].setParent(self);
    }
    if (r != NIL) {
      BTree[r].setParent(self);
    }
  }

  int root = getRoot(n);
  setDepths(root, 0);
  setHeights(root);
  for (int i = 0; i < n; i++){
    BTree[i].setType();
    BTree[i].setDegree();
  }

  print(n);

  return 0;
}

