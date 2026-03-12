#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  string s;
  cin >> s;

  stack<int> S1;
  stack<pair<int, int>> S2;
  
  for (int i = 0; i < s.size(); i++){
    if (s[i] == '\\'){
      S1.push(i);
    }
    else if (s[i] == '/' && !S1.empty()){
      int j = S1.top();
      S1.pop();
      int area = i - j;

      while(!S2.empty() && S2.top().first > j){
        area += S2.top().second;
        S2.pop();
      }
      S2.push({j, area});
    }
  }

  int total = 0;
  vector<int> ans;
  while(!S2.empty()){
    total += S2.top().second;
    ans.push_back(S2.top().second);
    S2.pop();
  }

  reverse(ans.begin(), ans.end());
  cout << total << endl;
  cout << ans.size();
  for (int x: ans){
    cout << " " << x;
  }
  cout << endl;

  return 0;
}