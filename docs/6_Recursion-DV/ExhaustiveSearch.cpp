#include <iostream>

using namespace std;

int n, q, A[20];

bool solve(int i, int m){
  if (m == 0){
    return true;
  }

  if (i >= n){
    return false;
  }
  
  // ||の左側はi番目の要素を使う組み合わせを探索。右側は、i番目の要素を使う組み合わせの探索
  bool res = solve(i+1, m) || solve(i+1, m-A[i]); 
  return res;
}

int main(){
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> A[i];
  }

  cin >> q;
  for (int i = 0; i < q; i++){
    int m;
    cin >> m;
    if (solve(0, m)){
      printf("yes\n");
    } else {
      printf("no\n");
    }
  }

  return 0;
}