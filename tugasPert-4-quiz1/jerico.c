#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    int top;
    char data[10];
} Stack;

Stack tumpuk;

void init()
{
    tumpuk.top = -1;
}

bool isFull()
{
    return (tumpuk.top == 10 - 1) ? 1 : 0;
}

bool isEmpty()
{
    return (tumpuk.top == -1) ? 1 : 0;
}

void push(char x)
{
    tumpuk.data[++tumpuk.top] = x;
}

char pop()
{
    char datas = tumpuk.data[tumpuk.top];
    tumpuk.top--;
    return datas;
}

int main()
{
    char opr[100];
    char postfix[100];
    scanf("%[^\n]%*c", opr);
    for (int i = 0; i < strlen(opr); i++)
    {
        if (opr[i] == '-' || opr[i] == '+' || opr[i] == '*' || opr[i] == '/')
        {
            if ((opr[i] == '+' || opr[i] == '-') && (tumpuk.data[tumpuk.top] == '*' || tumpuk.data[tumpuk.top] == '/'))
            {
                printf("%c ", pop());
                push(opr[i]);
            }

            else
            {
                push(opr[i]);
            }
        }

        else if (opr[i] >= '0' && opr[i] <= '9')
        {
            printf("%c ", opr[i]);
        }
    }

    while (!isEmpty())
    {
      // printf("test");
        printf("%c ", pop());
    }
}