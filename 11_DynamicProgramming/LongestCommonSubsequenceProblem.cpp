#include <iostream>

using namespace std;

int size(char S[]){
  int n = 0;
  for (int i = 0; S[i] != '\0'; i++){
    n++;
  }
  return n;
}

int LCS(char X[], char Y[]){
  // null文字を抜いた大きさを取得
  int xsize = size(X);
  int ysize = size(Y);

  int c[xsize+1][ysize+1];
  //cの0はX[0],Y[0]の前何もないところつまり漸化式の初期値を表してる。
  for (int i = 0; i <= xsize; i++){
    c[i][0] = 0;
  }
  for (int j = 0; j <= ysize; j++){
    c[0][j] = 0;
  }

  
  for (int i = 1; i <= xsize; i++){
    for (int j = 1; j <= ysize; j++){
      // 0オリジンだからX[xsize], Y[ysize]はnull文字を表してしまうので調整。
      if (X[i-1] == Y[j-1]){
        c[i][j] = c[i-1][j-1] + 1;
      } else {
        c[i][j] = max(c[i-1][j], c[i][j-1]);
      }
    }
  }
  return c[xsize][ysize];
}

int main(){
  int q;
  char X[1001];
  char Y[1001];

  scanf("%d", &q);
  for(int i = 0; i < q; i++){
    scanf("%s", X);
    scanf("%s", Y);
    int lcs = LCS(X, Y);
    printf("%d\n", lcs);
  }

  return 0;
} 