#include <iostream>
#include <string>

using namespace std;

struct command{
  string name;
  int time;
  bool complete;
};

class Queue{
  private:
    command data[100000];
    int head;
    int tail;
  public:
    Queue() : head(0), tail(0) {};
    
    void enqueue(command d){
      if (full()) {
        cout << "queue is full" << endl;
      } else {
        data[head] = d;
        head = (head+1) % 100000;
      }
    }
    
    command dequeue(){
      if (empty()){
        cout << "queue is empty" << endl;
        exit(1);
      } else {
        command d = data[tail];
        tail = (tail+1) % 100000;
        return d;
      }
    }

    bool full(){
      return (head+1) % 100000 == tail;
    }

    bool empty(){
      return head == tail;
    }
};

void RoundRobin(Queue& que, int q){
  int totaltime = 0;
  while(!que.empty()){
    command nowCommand = que.dequeue();
    if (nowCommand.time > q){
      totaltime += q;
      nowCommand.time -= q;
      que.enqueue(nowCommand);
    } else {
      totaltime += nowCommand.time;
      cout << nowCommand.name << " " << totaltime << endl;
    }
  }
}

int main() {
  int n, q;
  Queue que;
  command d;

  cin >> n >> q;
  for (int i = 0; i < n; i++){
    cin >> d.name >> d.time;
    que.enqueue(d);
  } 
  
  RoundRobin(que, q);

  return 0;
}