#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <string>

using namespace std;

int test_stack(){
  stack<int> S;

  //データの追加はpush()
  S.push(3);
  S.push(7);

  cout << S.size() << "\n";
  
  //頂点の要素を参照
  cout << S.top() << "\n";
  //頂点の要素を削除
  S.pop();

  cout << (S.empty() ? "空です\n" : "空ではないです\n");

  return 0;
}

int test_queue(){
  queue<string> Q;

  // データの追加
  Q.push("red");
  Q.push("yellow");

  // 先頭の要素を返す
  cout << Q.front() << " ";
  
  // 先頭の要素を削除
  Q.pop();

  return 0;
}

int test_vector(){
  vector<double> V;

  V.push_back(1.1);
  V.push_back(2.2);
  V[0] = 4.4;
  V.insert(V.begin()+1, 1.5);

  for(int i = 0; i < V.size(); i++){
    cout << V[i] << " ";
  }
  cout << endl;

  V.insert(V.end(), 3.3);
  V.erase(V.begin());
  for(int i = 0; i < V.size(); i++){
    cout << V[i] << " ";
  }
  cout << endl;

  return 0;
}

int test_list(){
  list<char> L;

  L.push_front('b');
  L.push_back('c');
  L.push_front('a');

  cout << L.front();
  cout << L.back();

  L.pop_front();

  return 0;
}

int main(){
  test_stack();
  test_queue();
  test_list();
  test_vector();
  return 0;
}