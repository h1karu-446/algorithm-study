// 名前 namei と必要な処理時間 timei を持つ n 個のプロセスが順番に一列に並んでいます。ラウンドロビンスケジューリングと呼ばれる処理方法では、CPU がプロセスを順番に処理します。各プロセスは最大 q ms（これをクオンタムと呼びます）だけ処理が実行されます。q ms だけ処理を行っても、まだそのプロセスが完了しなければ、そのプロセスは列の最後尾に移動し、CPU は次のプロセスに割り当てられます。

#include <iostream>
#include <queue>
#include <string>

using namespace std;

void process(queue<string> names, queue<int>times, int quantum){
  int tt, totaltime = 0;
  string tn;
   
  while(names.size()){
    if(times.front() <= quantum){
      totaltime += times.front();
      cout << names.front() << " " << totaltime << endl;
      names.pop();
      times.pop();
    }
    else{
      totaltime += quantum;
      tn = names.front();
      tt = times.front() - quantum;
      names.pop();
      times.pop();
      names.push(tn);
      times.push(tt);
    }
  }
}

int main(){
  queue<string> names;
  queue<int> times;
  string name;
  int num, quantum, time;

  cout << "プロセス数  クオンタム" << endl;
  cin >> num >> quantum;

  for (int i = 0; i < num; i++){
    cin >> name >> time;
    names.push(name);
    times.push(time);
  }

  process(names, times, quantum);

  return 0;
}