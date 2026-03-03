#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
  int n, q, totalTime = 0, tt;
  string tn;
  queue<string> names;
  queue<int> times;
  cin >> n >> q;

  for (int i = 0; i < n; i++){
    cin >> tn >> tt;
    names.push(tn);
    times.push(tt);
  } 

  while (!names.empty()){
    int currentTime = times.front();
    string currentName = names.front();
    times.pop();
    names.pop();

    if (currentTime <= q){
      totalTime += currentTime;
      cout << currentName << " " << totalTime << endl;
    } else {
      totalTime += q;
      currentTime -= q;
      times.push(currentTime);
      names.push(currentName);
    }
  }
}