#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

#define M 1000003

vector<string> H[M];

int h(int key){
  return key % M;
}

int getKey(string str){
  long long sum = 0, p = 1;

  for(int i = 0; i < str.length(); i++){
    int v;

    if(str[i]=='A') v = 1;
    else if(str[i]=='C') v = 2;
    else if(str[i]=='G') v = 3;
    else v = 4;

    sum += v * p;
    p *= 5;
  }

  return sum;
}

void insert(string str){
  int key, hash;
  key = getKey(str);
  hash = h(key);
  for (string s : H[hash]){
    if (s == str) return ;
  }
  H[hash].push_back(str);
}

bool find(string str){
  int key, hash;
  key = getKey(str);
  hash = h(key);

  for (string s : H[hash]){
    if (s == str) return true;
  }
  return false;
}

int main(){
  int n;
  string command;
  string str;

  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> command >> str;
    if (command == "insert"){
      insert(str);
    }
    else if (command == "find"){
      cout << (find(str) ? "yes\n" : "no\n");
    }
  }
}