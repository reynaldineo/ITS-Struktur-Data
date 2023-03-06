#include <stdio.h>
#include <string.h>
#define max 10

typedef struct {
  int top;
  char data[max];
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
  char full[max];
  scanf("%[^\n]%*c", full);

  for (int i = 0; i < strlen(full); i++) {
    if (full[i] >= '0' && full[i] <= '9') {
      printf("%c ", full[i]);
    } else if (full[i] == '-' || full[i] == '+' || full[i] == '*' || full[i] == '/') {
      if ((full[i] == '+' || full[i] == '-') && (stack.data[stack.top] == '*' || stack.data[stack.top] == '/')) {
        printf("%c ", pop());
        push(full[i]);
      } else {
        push(full[i]);
      }
    }
  }

  while (!isEmpty()) {
    // printf("sisa");
    printf("%c ", pop());
  }
}