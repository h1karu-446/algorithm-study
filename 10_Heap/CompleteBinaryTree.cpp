#include <iostream>

using namespace std;

int main(){
  int H;
  int A[251];

  cin >> H;
  
  for (int i = 1; i <= H; i++){
    cin >> A[i];
  }

  for (int i = 1; i <= H; i++){
    printf("node %d: key = %d, ", i, A[i]);
    if (i > 1){
      printf("parent key = %d, ", A[i/2]);
    }
    if (i*2 <= H){
      printf("left key = %d, ", A[i*2]);
    }
    if (i*2 + 1 <= H){
      printf("right key = %d, ", A[2*i+1]);
    }
    printf("\n");
  }
  return 0;
}