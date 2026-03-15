/*
反転数
数列A = {a0, a1, a2, ... , an}について、ai > aj かつ i < jである組(i, j)の個数
バブルソートの交換回数と等しくなる。
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> Array;
long long inversion = 0;
const int MAX = 2000000000;

void merge(int left, int mid, int right){
  int sizeL = mid - left;
  int sizeR = right - mid;
  int size = sizeL + sizeR;
  int L[sizeL+1];
  int R[sizeR+1];
  int i;

  for (i = 0; i < sizeL; i++){
    L[i] = Array[i+left];
  }
  L[i] = MAX;

  for (i = 0; i < sizeR; i++){
    R[i] = Array[i+mid];
  }
  R[i] = MAX;

  for (int i = 0, j = 0, k = 0; k < size; k++){
    if (L[i] <= R[j]){
      Array[left + k] = L[i];
      i++;
    } else{
      Array[left + k] = R[j];
      j++;
      inversion += sizeL - i;
    }
  }
} 

void mergeSort(int left, int right){
  if (left+1 < right){
    int mid = (left+right)/2;
    mergeSort(left, mid);
    mergeSort(mid, right);
    merge(left, mid, right);
  }
}

int main(){
  int n;
  cin >> n;
  
  for(int i = 0; i < n; i++){
    int t;
    cin >> t;
    Array.push_back(t);
  }

  mergeSort(0, n);

  cout << inversion << endl;

  return 0;
}