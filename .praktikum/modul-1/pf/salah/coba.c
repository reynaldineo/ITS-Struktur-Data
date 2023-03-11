#include <stdio.h>
#include <string.h>

typedef struct {
  int top;
  int data[100];
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

void pop() {
  tumpuk.top--;
}

char pucuk() {
  return tumpuk.data[tumpuk.top];
}

char pucukMin() {
  return tumpuk.data[--tumpuk.top];
}



int main() {
  init();
  char postfix [100];
  scanf("%[^\n]*c", postfix);

  int panjangPostfix;
  panjangPostfix = strlen(postfix);

  for (int i = 0; i < panjangPostfix; i++)
  {
    if (postfix[i] >= '0' && postfix[i] <= '9')
    {
      push(postfix[i]);
    }

    if (postfix[i] == '+')
    {
      int tempHasil;
      int p1 = pucuk(), p2 = pucukMin();
      tempHasil = p1 + p2;

    }
    
    
  }
  
}