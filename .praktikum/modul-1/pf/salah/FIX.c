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

char pucuk() {
  return tumpuk.data[tumpuk.top];
}

char pucukMin() {
  return tumpuk.data[tumpuk.top--];
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
  n = strlen(input); // panjang inputan

  // 1. push 1 1
  // di cek kalau angka lanjut push, kalau operator di 
  // 2. operasiin dengan ngambil top dan top-1
  // push hasilnya, lanjut

  // convert string ke angka

  for(int i = 0; i < n ; i++) {
    if(input[i] >= '0' && input[i]<='9') {
      // postfix[j++] = input[i];s
      push(input[i]);
    }  

    else if (input[i] == '*')
    {
      int hasilTemp;
      hasilTemp = pucuk() + pucukMin();
      printf("tot %d p%d pmin%d", hasilTemp, pucuk(), pucukMin);
      push(input[i]);
      pop();
      pop();
      pop();
      push(hasilTemp);
    }

    else if (input[i] == '+')
    {
      int hasilTemp;
      hasilTemp = pucuk() + pucukMin();
      push(input[i]);
      pop();
      pop();
      pop();
      push(hasilTemp);
    }

    
    else if (input[i] == '-')
    {
      int hasilTemp;
      hasilTemp = pucuk() - pucukMin();
      push(input[i]);
      pop();
      pop();
      pop();
      push(hasilTemp);
    }
  }
  printf("%d", pucuk());
}