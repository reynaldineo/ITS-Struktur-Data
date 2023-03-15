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

char pucukMin() { 
  return tumpuk.data[--tumpuk.top];
}

void pop() {
  tumpuk.top--;
}

int main() {
  init();
  char input[100];
  char postfix[100];
  scanf("%[^\n]*c", input);

  int nInput, j = 0, k = 0;
  nInput = strlen(input);  // panjang input

  for(int i = 0; i < nInput ; i++) {

    if(input[i] >= '0' && input[i]<='9') { // kalau angka masukin ke postfix
      postfix[j++] = input[i];
    }  

    // else if (input[i] == ')') {
    //   push(input[i]);
    // }
    

    // else if (input[i] == ')') {
    //   while (pucuk() != '(') {
    //     postfix[j++] = pucuk();
    //     pop();
    //   }
    // }
    
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

  int nPostfix;
  nPostfix = strlen(postfix);
  printf("n %d \n", nPostfix);
  int test =2;
  printf("0 %c \n", postfix[test]);

  for(int i = 0; i < nInput; i++) {
    printf("uhuy %c ", postfix[i]);
  }

  char hasil[100];
  
  for(int i = 0 ; i<nPostfix; i++) {

    if (postfix[i] >= '0' && postfix[i] <= '9') {
      push(postfix[i]);
    }

    if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*')
    {
      int temp;
      temp = pucuk() - pucukMin();
      pop();
      pop();
      push(temp);
    }
  }

  printf("%d", pucuk());

  
  

  
  
  
}