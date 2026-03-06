#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#define M 1046527

char H[M][13];

void H_init(){
  for(int i = 0; i < M; i++){
    H[i][0] = '\0';
  }
}

int h1(int key){
  return key % M;
}

int h2(int key){
  return 1 + key % (M-1);
}

long long getKey(string str){
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

bool insert(string str){
  int key, hash;
  key = getKey(str);

  for (int i = 0; ;i++){
    hash = (h1(key)+i*h2(key)) % M;
    if(strcmp(H[hash], str.c_str()) == 0) return 1;
    else if (strlen(H[hash]) == 0) {
      strcpy(H[hash], str.c_str());
      return 0;
    } 
  }
  return 0;
}

bool find(string str){
  int key, hash;
  key = getKey(str);

  for (int i = 0; ;i++){
    hash = (h1(key)+i*h2(key)) % M;
    if(strcmp(H[hash], str.c_str()) == 0) return true;
    else if (strlen(H[hash]) == 0) {
      return false;
    } 
  }
  return false;
}

int main(){
  int n;
  string command;
  string str;

  cin >> n;
  H_init();
  for(int i = 0; i < n; i++){
    cin >> command >> str;
    if (strcmp(command.c_str(), "insert") == 0){
      insert(str);
    }
    else if (strcmp(command.c_str(), "find") == 0){
      cout << (find(str) ? "yes\n" : "no\n");
    }
  }
}