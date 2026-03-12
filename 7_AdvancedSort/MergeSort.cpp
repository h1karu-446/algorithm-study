#include <iostream>
#include <vector>

using namespace std;

#define MAX 1000000001

vector<int> S;
int sw = 0;

void merge(int left, int mid, int right){
  int size1 = mid - left;
  int size2 = right - mid;
  int L[size1+1], R[size2+1];

  for (int i = 0; i < size1; i++){
    L[i] = S[i+left];
  }
  
  for (int i = 0; i < size2; i++){
    R[i] = S[i+mid];
  }
  L[size1] = MAX;
  R[size2] = MAX;

  for (int i = 0, j = 0, k = left; i+j < right-left; k++){
    if (L[i] <= R[j]){
      S[k] = L[i];
      i++;
    } else {
      S[k] = R[j];
      j++;
    }
    sw++;
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
  int n, t;

  cin >> n;

  for(int i = 0; i < n; i++){
    cin >> t;
    S.push_back(t);
  }

  mergeSort(0, n);

  for (int i = 0; i < n; i++){
    cout << S[i];
    cout << (i == n-1 ? "\n" : " ");
  }
  cout << sw << endl;

  return 0;
}