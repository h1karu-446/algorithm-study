#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000000001;

struct Card{
  int number;
  char pic;
};

int partition(Card *A, int p, int r){
  int x = A[r].number;
  int i, j;
  Card temp;

  for (i = p-1, j = p; j < r; j++){
    if (A[j].number <= x){
      i++;
      temp = A[i];
      A[i] = A[j];
      A[j] = temp;
    }
  }
  i++;
  char c = A[r].pic;
  A[r] = A[i];
  A[i].number = x;
  A[i].pic = c;

  return i;
}

void quickSort(Card *A, int p, int r){
  if (p < r){
    int q;
    q = partition(A, p, r);
    quickSort(A, p, q-1);
    quickSort(A, q+1, r);
  }
}

void merge(Card *A, int left, int mid, int right){
  int i, j, k;
  int sizel = mid - left;
  int sizer = right - mid;
  Card L[sizel+1];
  Card R[sizer+1];
  for (i = 0; i < sizel; i++){
    L[i] = A[i+left];
  }
  L[i].number = MAX;
  for (i = 0; i < sizer; i++){
    R[i] = A[i+mid];
  }
  R[i].number = MAX;

  for(i = 0, j = 0, k = left; i+j < right-left; k++){
    if (L[i].number <= R[j].number){
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
  }
}

void mergeSort(Card *A, int left, int right){
  if (left+1 < right){
    int mid = (left+right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

bool isStable(Card *A, Card *B, int n){
  mergeSort(B, 0, n);
  for (int i = 0; i < n; i++){
    if (A[i].pic != B[i].pic) return false;
  }
  return true;
}

int main(){
  int n;
  Card A[100000], B[100000];

  cin >> n;
  for (int i = 0; i < n; i++){
    scanf(" %c %d", &A[i].pic, &A[i].number);
    B[i] = A[i];
  }

  quickSort(A, 0, n-1);

  if(isStable(A, B, n)) {
    cout << "Stable" << endl;
  } else {
    cout << "Not stable" << endl;
  }

  for (int i = 0; i < n; i++){
    cout << A[i].pic << " " << A[i].number << endl;
  }

  return 0;
}