#include <stdio.h>
#include <string.h>
#define max 10

typedef struct {
  int top;
  char data[10];
} isiOperator;

isiOperator stack;

void init() {
  stack.top = -1;
}

int isFull() {
  return (stack.top == max -1) ? 1 : 0;
}

int isEmpty() {
  return (stack.top == -1) ? 1 : 0;
}

void push(char operator) {
  stack.data[++stack.top] = operator;
}

char pop() {
  return stack.data[stack.top--];
}

int main () {
  char full[100];
  char postFix [100];
  init();
  // 1. masukin semua nya
  scanf("%[^\n]%*c", full);
    int j = 0;

  // 2. ngecek isinya 1 per 1
  for (int i = 0; i < strlen(full); i++) {
    // 3. setiap ada angka di masukin ke post fix
    if (full[i]>='0' && full[i]<='9') {
      postFix[j++] = full[i];
    }
    
    // kalau ada operator di masukin ke stack
    else if (full[i] == '+' || full[i] == '-' || full[i] == '*' || full[i] == '/') {
      // postFix[i] = full[i];

      // Kalau blm ada data
      if (stack.top == -1) {
        push(full[i]);
        // break;
      }

      // kalau ... 
      else if ((stack.data[stack.top] == '*' || stack.data[stack.top] == '/') && (full[i] == '+' || full[i] == '-')) {
        postFix[j++] = pop();
        push(full[i]);
      }
      
      // masukin operatornya ke stack
      // else push(full[i]); 
    }

    while(stack.top != -1) {
		postFix[j++] = pop();
	}
    
    
  }

  // printf("%s\n", postFix);

    for (int i = 0; i < strlen(full); i++)
    {
      printf("%c ", postFix[i]);
    }
}