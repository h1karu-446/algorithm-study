#include <iostream>
using namespace std;

#define NOT_FOUND -1

int LinearSearch(int* data, int n, int v){
  for(int i = 0; i < n; i++){
    if (data[i] == v){
      return i;
    }
  }
  return NOT_FOUND;
}

int LinearSearch_sentinel(int* data, int n, int v){
  data[n] = v;
  int i = 0;
  while(data[i] != v) i++;
  return (i != n ? i : NOT_FOUND);
}


int main(void){
  int n, q, count = 0;
  cin >> n;

  int S[n+1];
  for (int i = 0; i < n; i++){
    cin >> S[i];
  }

  cin >> q;
  int T[q];
  for (int i = 0; i < q; i++){
    cin >> T[i];
    if (LinearSearch_sentinel(S, n, T[i]) != NOT_FOUND){
      count++;
    }
  }
  cout << count << endl;
  return 0;
}