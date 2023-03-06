#include <stdio.h>
#include <string.h>

typedef struct {
  int top;
  int data[10];
} Stack;

Stack tumpuk;

void init() {
  tumpuk.top = -1;
}

int isEmpty() {
  return (tumpuk.top==-1) ? 1 : 0;
}

void push(char temp) {
  tumpuk.data[++tumpuk.top] = temp;
}

char pucuk() {
  return tumpuk.data[tumpuk.top];
}

void pop() {
  tumpuk.top--;
}

int main() {
  init();
  char input[100];
  char postfix[100];
  scanf("%[^\n]*c", input);
  int n, j = 0;
  n = strlen(input);    

  for(int i = 0; i < n ; i++) {
    if(input[i] >= '0' && input[i]<='9') {
      postfix[j++] = input[i];
    }  
    
    else if(input[i] == '*' || input[i] == '/') {
      if(pucuk() == '*' ||pucuk() == '/') {
        postfix[j++] = pucuk();
        pop();
      } 
      push(input[i]);
    }

    else if (input[i] == '+' || input[i] == '-') {
      while(!isEmpty()) {
        postfix[j++] = pucuk();
        pop();
      }
      push(input[i]);
    }
  }

  while(!isEmpty()) {
    postfix[j++] = pucuk();
    pop();
  }

  for(int i = 0; i < n; i++) {
    printf("%c ", postfix[i]);
  }
}