#include <iostream>
#include <cstring>

using namespace std;

int S[2000001];
int H = 0;

void insert(int key){
  H++; //1オリジン
  int i = H;
  S[i] = key;
  while(i > 1 && S[i/2] < S[i]){
    int t = S[i/2];
    S[i/2] = S[i];
    S[i] = t;
    i = i/2;
  }
}

void maxHeapify(int i){
  int L = i*2;
  int R = i*2+1;
  int largest = i;

  if (L <= H && S[L] > S[largest]){
    largest = L;
  }
  if (R <= H && S[R] > S[largest]){
    largest = R;
  }
  
  if (largest != i){
    int t = S[i];
    S[i] = S[largest];
    S[largest] = t;
    maxHeapify(largest);
  }
}

int extract(){
  if (H > 0){
    int max = S[1];
    S[1] = S[H];
    H--;
    maxHeapify(1);
    return max;
  } else {
    return -1;
  }
}

int main(){
  char command[20];
  int key;

  while(1){
    scanf("%s", command);
    if(strcmp(command, "insert") == 0){
      scanf("%d", &key);
      insert(key);
    } else if (strcmp(command, "extract") == 0){
      int m = extract();
      printf("%d\n", m);
    } else if (strcmp(command, "end") == 0){
      break;
    }
  }

  return 0;
}