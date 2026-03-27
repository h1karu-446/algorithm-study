#include <iostream>
#include <algorithm>

using namespace std;

int F[45];

int fib(int n){
  if (n == 0 || n == 1) {
    return F[n] = 1;
  }
  if (F[n] != -1){
    return F[n];
  }
  
  return F[n] = fib(n-1) + fib(n-2);
}

int main(){
  int n, f;
  fill(F, F+45, -1);

  cin >> n;
  f = fib(n);
  cout << f << endl;

  return 0;
}