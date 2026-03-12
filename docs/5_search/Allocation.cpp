#include <iostream>
using namespace std;

int n, k;
int w[100000];

int check(int P){
  int i = 0;

  for(int j = 0; j < k; j++){
    int sum = 0;

    while(i < n && sum + w[i] <= P){
      sum += w[i];
      i++;
    }
  }

  return i;
}

int main(){

  cin >> n >> k;

  for(int i = 0; i < n; i++){
    cin >> w[i];
  }

  int left = 0;
  int right = 100000 * 10000; //n*w_iの最大値

  while(left < right){
    int mid = (left + right) / 2;

    if(check(mid) == n){ //nなら全ての荷物が仮定のP(つまりmid)で積むことができる
      right = mid; //より小さい範囲で最小のPを探索する
    }else{
      left = mid + 1;
    }
  }

  cout << left << endl;
}