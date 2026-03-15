#include <iostream>
#include <algorithm>

using namespace std;

static const int MAX = 1000;
static const int VMAX = 10000;

int n, A[MAX], s;
int B[MAX], T[VMAX+1];

int solve() {
  int ans = 0;
  bool V[MAX];

  for (int i = 0; i < n; i++){
    B[i] = A[i];
    V[i] = false;
  }
  sort(B, B+n); //Bはソート済みの整列。つまり最終的にあるべき姿

  for (int i = 0; i < n; i++) T[B[i]] = i; //Tはソート後の値→インデックスをつなぐ関数
  
  //全ての要素を探索
  for (int i = 0; i < n; i++){
    if ( V[i] ) continue; //すでに処理済みのサイクルなら次へ
    int cur = i; 
    int S = 0; //Σw_i サイクルの各要素の和
    int m = VMAX; //サイクル内の最小値
    int an = 0; //サイクル内の要素の個数を数える
    //サイクルを辿る
    while(1){
      V[cur] = true; //足跡をつける。
      an++; 
      int v = A[cur];
      m = min(m, v); //サイクル内最小値を更新していく
      S += v; //サイクル内の値の総和をとる
      cur = T[v]; //サイクルの次の値へ。ソート後あるべき場所に今ある要素を辿る
      if (V[cur]) break;
    }
    /*
    サイクル内だけでの交換におけるコストは、Σw_i + (n-2) * min(w_i) *S 
    サイクル外から最小値を借りてきた時のコストは、min(w_i) + Σw_i  + (n+1)*配列全体における最小値
    - S = Σw_i
    - sは配列全体の最小値
    */
    ans += min(S+(an-2)*m, m+S+(an+1)*s); 
  }

  return ans;
}


int main() {
  cin >> n;
  s = VMAX;
  for (int i = 0; i < n; i++){
    cin >> A[i];
    s = min(s, A[i]);
  }
  int ans = solve();
  cout << ans << endl;

  return 0;
}