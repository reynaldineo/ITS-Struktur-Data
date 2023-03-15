#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/* Struktur Node */

typedef struct stackNode_t {
    int data;
    struct stackNode_t *next;
} StackNode;

/* Struktur ADT Stack */

typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
} Stack;

/* Function definition below */

void stack_init(Stack *stack) 
{
    stack->_size = 0;
    stack->_top = NULL;
}

bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, int value) 
{
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        newNode->data = value;
        
        if (stack_isEmpty(stack)) newNode->next = NULL;
        else newNode->next = stack->_top;

        stack->_top = newNode;
    }
}

void stack_pop(Stack *stack) 
{
    if (!stack_isEmpty(stack)) {
        StackNode *temp = stack->_top;
        stack->_top = stack->_top->next;
        free(temp);
        stack->_size--;
    }
}

int stack_top(Stack *stack) 
{
    if (!stack_isEmpty(stack)) 
        return stack->_top->data;
    return 0;
}

unsigned stack_size(Stack *stack) {
    return stack->_size;
}

int main(int argc, char const *argv[])
{
  Stack myStack;
  stack_init(&myStack);

  char postfix[100];
  scanf("%[^\n]*c", postfix);

  int panjangPostfix;
  panjangPostfix = strlen(postfix);

  for (int i = 0; i < panjangPostfix; i++)
  {
    if (postfix[i] >= '0' && postfix[i] <= '9')
    {      
      if (postfix[i] == '0') stack_push(&myStack, 0);
      else if (postfix[i] == '1') stack_push(&myStack, 1);
      else if (postfix[i] == '2') stack_push(&myStack, 2);
      else if (postfix[i] == '3') stack_push(&myStack, 3);
      else if (postfix[i] == '4') stack_push(&myStack, 4);
      else if (postfix[i] == '5') stack_push(&myStack, 5);
      else if (postfix[i] == '6') stack_push(&myStack, 6);
      else if (postfix[i] == '7') stack_push(&myStack, 7);
      else if (postfix[i] == '8') stack_push(&myStack, 8);
      else if (postfix[i] == '9') stack_push(&myStack, 9);
    }

    else if (postfix[i] == '+')
    {
      int hasilTemp;
      int p1 = stack_top(&myStack);
      stack_pop(&myStack);
      int p2 = stack_top(&myStack);
      stack_pop(&myStack);
      hasilTemp = p2 + p1;
      stack_push(&myStack, hasilTemp);
    }

    else if (postfix[i] == '-')
    {
      int hasilTemp;
      int p1 = stack_top(&myStack);
      stack_pop(&myStack);
      int p2 = stack_top(&myStack);
      stack_pop(&myStack);
      hasilTemp = p2 - p1;
      stack_push(&myStack, hasilTemp);
    }

    else if (postfix[i] == '*')
    {
      int hasilTemp;
      int p1 = stack_top(&myStack);
      stack_pop(&myStack);
      int p2 = stack_top(&myStack);
      stack_pop(&myStack);
      hasilTemp = p2 * p1;
      stack_push(&myStack, hasilTemp);
    }
    
  }

  while (!stack_isEmpty(&myStack))
  {
    printf("%d ", stack_top(&myStack));
    stack_pop(&myStack);
  }

  return 0;
}