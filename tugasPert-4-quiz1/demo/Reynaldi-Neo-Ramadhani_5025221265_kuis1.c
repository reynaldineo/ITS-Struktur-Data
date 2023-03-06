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

void push(char operator) {
  stack.data[++stack.top] = operator;
}

char pop() {
  return stack.data[stack.top--];
}

int main () {
  char full[max];
  char postFix [max];
  int j = 0;
  init();

  scanf("%[^\n]%*c", full);

  for (int i = 0; i < strlen(full); i++) {
    if (full[i]>='0' && full[i]<='9') {
      postFix[j++] = full[i];
    }
    else if (full[i] == '+' || full[i] == '-' || full[i] == '*' || full[i] == '/') {

      if (stack.top == -1) {
        push(full[i]);
      }

      if ((stack.data[stack.top] == '*' || stack.data[stack.top] == '/') && (full[i] == '+' || full[i] == '-')) {
        postFix[j++] = pop();
        push(full[i]);
      }

      else push(full[i]);
    }
  }

  while(stack.top != -1) {
		postFix[j++] = pop();
	}

  for (int i = 0; i < j-1; i++) {
    printf("%c ", postFix[i]);
  }
}