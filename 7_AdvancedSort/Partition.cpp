#include <iostream>
#include <vector>

using namespace std;

vector<int> A;

int partition(int p, int r){
  int x = A[r], i, j, t;
  for (i = p-1, j = p; j < r; j++){
    if (A[j] <= x){
      i++;
      t = A[i]; A[i] = A[j]; A[j] = t;
    }
  }
  i++;
  A[r] = A[i];
  A[i] = x;
  return i;
}

int main(){
  int n, pibot;
  cin >> n;

  for (int i = 0; i < n; i++){
    int t;
    cin >> t;
    A.push_back(t);
  }

  pibot = partition(0, n-1);

  for (int i = 0; i < n; i++){
    if (i == pibot){
      cout << "[" << A[i] << "]";
    } else {
      cout << A[i];
    }
    cout << (i == n-1 ? "\n" : " ");
  }
  return 0;
}