#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
  stack<int> formula;
  string c;
  int pre, rear, ans;

  while(cin >> c){
    if (c[0] == '+'){
      rear = formula.top(); formula.pop();
      pre = formula.top(); formula.pop();
      formula.push(rear+pre);
    }
    else if (c[0] == '-'){
      rear = formula.top(); formula.pop();
      pre = formula.top(); formula.pop();
      formula.push(pre-rear);
    }
    else if (c[0] == '*'){
      rear = formula.top(); formula.pop();
      pre = formula.top(); formula.pop();
      formula.push(rear*pre);
    } else {
      formula.push(atoi(c.c_str()));
    }
  }

  cout << formula.top() << endl;

  return 0;
}