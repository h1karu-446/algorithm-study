#include <iostream>
#include <cstring>

using namespace std;

struct Node{
  long long key;
  Node* next = NULL;
  Node* prev = NULL;
};

Node head;

void init(){
  head.next = &head;
  head.prev = &head;
}

void insert(long long key){
  Node* p;
  p = (Node *)malloc(sizeof(Node));
  p->key = key;
  p->next = head.next;
  head.next->prev = p;
  p->prev = &head;
  head.next = p;
}

Node* search(long long key){
  Node* p;
  for (p = head.next; p != &head; p = p->next){
    if (p->key == key){
      return p;
    }
  }
  return p;
}

void delete_ele(Node* ele){
  if (ele == &head) {
    cout << "リストは空です" << endl;
    return ;
  }
  ele->prev->next = ele->next;
  ele->next->prev = ele->prev;
  free(ele);
}

void deleteFirst(){
  delete_ele(head.next);
}

void deleteLast(){
  delete_ele(head.prev);
}

void printNode(){
  for(Node* p = head.next; p != &head; p = p->next){
    cout << p->key;
    cout << (p->next != &head ? " " : "\n");
  }
}

int main() {
  int n;
  long long value;
  Node* p;
  cin >> n;
  char instruction[20];

  init();
  
  for(int i = 0; i < n; i++){
    cin >> instruction;
    if (!strcmp(instruction, "insert")){
      cin >> value;
      insert(value);
    } else if(!strcmp(instruction, "delete")) {
      cin >> value;
      p = search(value);
      delete_ele(p);
    } else if (!strcmp(instruction, "deleteFirst")){
      deleteFirst();
    } else if (!strcmp(instruction, "deleteLast")){
      deleteLast();
    } else {
      __throw_logic_error("適切な命令を投げてください");
    }
  }

  printNode();

  return 0;
}