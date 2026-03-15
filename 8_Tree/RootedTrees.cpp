/*
左子右兄弟方式
parent, left, rightの三つの整数値で木構造を定義する。
leftに長男を、rightに一つ下の弟を持つ。
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAX = 200000;

const int nil = -1;

struct Node {
  int parent, left, right, depth; 
  string type;
};

Node Tree[MAX];

void printTree(int);
void setDepth(int);
void setDepths(int, int);
void setType(int);

int main(){
  int num, id, k, child, bigbro;
  cin >> num;

  //初期化
  for (int i = 0; i < num; i++) Tree[i].parent = Tree[i].left = Tree[i].right = nil;
  
  //木の作成
  for (int i = 0; i < num; i++){
    cin >> id >> k;
    for (int j = 0; j < k; j++){
      cin >> child;
      if (j == 0){
        Tree[id].left = child;
      } 
      else {
        Tree[bigbro].right = child;
      }
      Tree[child].parent = id;
      bigbro = child;
    }
  }

  //getDepthによる深さの設定
  // for(int i = 0; i < num; i++){
  //   setDepth(i);
  // }

  //setDepthによる深さの設定
  int root;
  for (int i = 0; i < num; i++){
    if (Tree[i].parent == nil){
      root = i; //親を探す
      break;
    }
  }
  setDepths(root, 0);

  //typeを求める
  for (int i = 0; i < num; i++){
    setType(i);
  }

  printTree(num);

  return 0;
}

void printTree(int num){
  for (int i = 0; i < num; i++){
    //子供達を求める
    vector<int> children;
    for(int c = Tree[i].left; c != nil; c = Tree[c].right){
      children.push_back(c);
    }

    printf("node %d: parent = %d, depth = %d, %s, [", i, Tree[i].parent, Tree[i].depth, Tree[i].type.c_str());
    for(int j = 0; j < children.size(); j++){
      printf("%d", children[j]);
      if (j+1 != children.size()) printf(", ");
    }
    printf("]\n");
  }
}

// 親をたどって自分の深さを求める。
void setDepth(int id){
  int d = 0;
  while (Tree[id].parent != nil){
    d++;
    id = Tree[id].parent;
  }
  Tree[id].depth = d;
}

//再起的に深さを求める。初期値引数は(ルートid, 0)で始めないといけない。
void setDepths(int id, int d){
  Tree[id].depth = d;
  if (Tree[id].right != nil){
    setDepths(Tree[id].right, d); //兄弟なら深さは同じ
  }
  if (Tree[id].left != nil){
    setDepths(Tree[id].left, d+1); //子供なら深さを一つ増やす
  }
}

void setType(int id){
  if (Tree[id].parent == nil) Tree[id].type = "root";
  else if (Tree[id].left == nil) Tree[id].type = "leaf";
  else Tree[id].type = "internal node";
}