#include <iostream>
#include <cstring>

using namespace std;

struct list{
  int key;
  list* prev = NULL;
  list* next = NULL;
};
list head = {0, &head, &head};

void insert(int value){
  list *x = (list *)malloc(sizeof(list));
  x->key = value;
  x->next = head.next;
  head.next->prev = x;
  x->prev = &head;
  head.next = x;
}

void deleteNode(list* t){
  t->next->prev = t->prev;
  t->prev->next = t->next;
  free(t);
}

void search(int value){
  for (list* p = head.next; p != &head; p = p->next){
    if (p->key == value){
      deleteNode(p);
      break;
    }
  }
}

void deleteFirst(){
  deleteNode(head.next);
}

void deleteLast(){
  deleteNode(head.prev);
}

int main() {
  int n, value;
  cin >> n;
  char instruction[20];
  
  for(int i = 0; i < n; i++){
    scanf("%s%d", instruction, &value);
    if (!strcmp(instruction, "insert")){
      insert(value);
    } else if(!strcmp(instruction, "delete")) {
      search(value);
    } else if (!strcmp(instruction, "deleteFirst")){
      deleteFirst();
    } else if (!strcmp(instruction, "deleteLast")){
      deleteLast();
    } else {
      __throw_logic_error("適切な命令を投げてください");
    }
  }

  for(list* p = head.next; p != &head; p = p->next){
    if (p->next == &head){
      cout << p->key << endl;
      break;
    }
    cout << p->key << " ";
  }

  return 0;
}