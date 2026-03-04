#include <iostream>
#include <string>

using namespace std;

class Stack {
  private:
    long long data[100];
    int sp;
  
  public:
    Stack() {
      sp = 0;
    }

    void push(long long v){
      data[sp++] = v;
    }

    long long pop() {
      return data[--sp];
    }

    bool empty() const {
      return sp == 0;
    }

    int size(){
      return sp;
    }
};

int main(void){
  Stack st;
  string s;
  long long x;

  while(cin >> s){
    if (s == "+"){
      long long right = st.pop();
      long long left = st.pop();
      st.push(left + right);
    } else if (s == "-"){
      long long right = st.pop();
      long long left = st.pop();
      st.push(left - right);
    } else if (s == "*"){
      long long right = st.pop();
      long long left = st.pop();
      st.push(left * right);
    } else {
      st.push(stoll(s));
    }
  }
  cout << st.pop() << endl;
}