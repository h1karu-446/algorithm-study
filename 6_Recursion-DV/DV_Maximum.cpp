#include <iostream>

#define N 10

int max(int x, int y){
  return x >= y ? x : y;
}

//配列Aのlからr(rを含まない)までの要素の最大値を求める
//1つ要素まで細分化して、それらを比較しトーナメントのように大きい方を返していく
int findMaximum(int *A, int l, int r){
  if (l+1 == r) return A[l];
  int m = (l + r) / 2;

  int u = findMaximum(A, l, m);
  int v = findMaximum(A, m, r);
  return max(u, v);
}

int main(){
  int A[N];

  for (int i = 0; i < N; i++){
    std::cin >> A[i];
  }

  int max = findMaximum(A, 0, N);
  std::cout << max << std::endl;

  return 0;
}
