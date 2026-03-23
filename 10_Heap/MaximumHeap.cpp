#include <iostream>

using namespace std;

int H, A[500001];

void maxHeapify(int A[], int i){
  long long l = i*2;
  long long r = i*2+1;
  int largest = i;
  
  if (l <= H && A[largest] < A[l]){
    largest = l;
  }
  if (r <= H && A[largest] < A[r]){
    largest = r;
  }

  if (largest != i){
    int t = A[i];
    A[i] = A[largest];
    A[largest] =t;
    maxHeapify(A, largest);
  }
}

int main(){
  cin >> H;
  for (int i = 1; i <= H; i++){
    cin >> A[i];
  }

  for(int i = H/2; i > 0; i--){
    maxHeapify(A, i);
  }

  for (int i = 1; i <= H; i++){
    cout << " " << A[i];
  }
  cout << endl;

  return 0;
}

