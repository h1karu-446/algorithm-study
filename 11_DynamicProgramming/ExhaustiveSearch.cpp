#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int n, q;
int *A;
int dp[21][2001] = {-1};

bool solve(int i, int m){
  if (m < 0) return false;
  
  if (dp[i][m] != -1){
    return dp[i][m];
  }
  if (m == 0){
    return dp[i][m] = 1;
  }
  else if (i >= n) {
    return dp[i][m] = 0;
  } else if (solve(i+1, m)){
    return dp[i][m] = 1;
  } else if (solve(i+1, m-A[i])){
    return dp[i][m] = 1;
  } else {
    return dp[i][m] = 0;
  }
}

int main(){
  memset(dp, -1, sizeof(dp));

  scanf("%d", &n);
  A = (int *)malloc(sizeof(int)*n);

  for (int i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  scanf("%d", &q);
  for(int i = 0; i < q; i++){
    int m;
    cin >> m;
    if (solve(0, m)) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
  free(A);

  return 0;
}