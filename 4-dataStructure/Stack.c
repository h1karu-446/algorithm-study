#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stack[101], top;

void push(int x){
    stack[top] = x;
    top++;
}

int pop(){
    top--;
    return stack[top];
}

int main()
{
    top = 0;
    int i_1, i_2;
    char s[100];

    while(scanf("%s", s) != EOF){
        if (s[0] == '+'){
            i_1 = pop();
            i_2 = pop();
            push(i_2+i_1);
        }
        else if (s[0] == '-'){
            i_1 = pop();
            i_2 = pop();
            push(i_2-i_1);
        }
        else if (s[0] == '*'){
            i_1 = pop();
            i_2 = pop();
            push(i_2*i_1);
        }
        else {
            push(atoi(s));
        }
    } 
    printf("%d\n", pop());

    return 0;
}




