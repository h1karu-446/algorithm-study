#include <string>
#include <map>

using namespace std;

const int NIL = -1;
const int MAX = 25;

std::map<int, std::string> Type = {
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

    std::string getType(){
      return Type[type];
    }

    int getDegree(){
      return degree;
    }
};

