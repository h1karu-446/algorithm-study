#include <iostream>

using namespace std;

#define NOT_FOUND -1

int BinarySearch(int* S, int size, int key){
  int mid, left = 0, right = size;
  while(left <= right){
    mid = (left+right)/2;
    if (S[mid] == key){
      return mid;
    } else if (S[mid] < key){
      left = mid+1;
    } else {
      right = mid-1;
    }
  }
  return NOT_FOUND;
}

int main(){
  int n, q, count = 0;
  cin >> n;

  int S[n];
  for (int i = 0; i < n; i++){
    cin >> S[i];
  }

  cin >> q;
  int T[q];
  for (int i = 0; i < q; i++){
    cin >> T[i];
    if (BinarySearch(S, n, T[i]) != NOT_FOUND){
      count++;
    }
  }
  cout << count << endl;
  return 0;
}