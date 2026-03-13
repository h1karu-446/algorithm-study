#include <iostream>
#include <vector>

using namespace std;

int findMax(vector<int> A, int n){
  int max = 0;
  for(int i = 0; i < n; i++){
    if (max < A[i]) max = A[i];
  }
  return max;
}

void countingSort(vector<int> &A, int n){
  int k = findMax(A, n);
  int C[k+1], B[n];
  for (int i = 0; i < k+1; i++){
    C[i] = 0;
  }
  for (int i = 0; i < n; i++){
    C[A[i]]++;
  }
  for (int i = 1; i < k+1; i++){
    C[i] += C[i-1];
  }

  for (int j = n-1; j >= 0; j--){
    B[--C[A[j]]] = A[j];
  }

  for (int i = 0; i < n; i++){
    A[i] = B[i];
  }
}

int main(){
  int n;
  vector<int> A;

  cin >> n;
  for (int i = 0; i < n; i++){
    int t;
    cin >> t;
    A.push_back(t);
  }

  countingSort(A, n);

  for (int i = 0; i < n; i++){
    cout << A[i];
    cout << (i == n-1 ? "\n" : " ");
  }

  return 0;
}