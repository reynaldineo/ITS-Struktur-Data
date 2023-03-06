#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int top;
    int data[10];
}Stack;

Stack tumpuk;

void inisialisasi()
{
    tumpuk.top = -1;
}

void push(char a)
{
    tumpuk.data[++tumpuk.top] = a;
}

int isEmpty()
{
    return (tumpuk.top==-1) ? 1 : 0;
}

char TOS()
{
    return tumpuk.data[tumpuk.top];
}

void pop()
{
    tumpuk.top--;
}

int main()
{
    inisialisasi();
    char infix[101];
    char postfix[101];
    int idx = 0;
    system("cls");
    printf("Masukkan Nilai infix : ");
    scanf("%[^\n]*c", infix);
    int i, n;
    n = strlen(infix);    

    for(i = 0; i < n ; i++)
    {
        // percabangan angka
        if(infix[i] >= '0' && infix[i]<='9')
        {
            postfix[idx++] = infix[i];
        }  
         
        // percabangan operator (*) dan (/)
        else if(infix[i] == '*' || infix[i] == '/')
        {
            // jika data teratas dari stack merupakan (*) dan (/)
            // maka pindahkan TOS ke postfix dan push infix
            if(TOS() == '*' ||TOS() == '/')
            {
                    postfix[idx++]=TOS();
                    pop();
            }
            push(infix[i]);
        }

        // percabangan operator (+) dan (-)
        else if (infix[i] == '+' || infix[i] == '-')
        {
            // pindahkan semua data yang ada di tumpuk ke postfix
            // lalu, push infix
            while(!isEmpty())
            {
                postfix[idx++]=TOS();
                pop();
            }
            push(infix[i]);
        }
    }

    // memindahkan semua data yang ada di tumpuk ke postfix
    while(!isEmpty())
    {
        postfix[idx++]=TOS();
        pop();
    }

    printf("Hasil Convert Postfix : \n");
    // printf postfix
    for(i = 0; i < n; i++)
    {
        printf("%c ", postfix[i]);
    }
}