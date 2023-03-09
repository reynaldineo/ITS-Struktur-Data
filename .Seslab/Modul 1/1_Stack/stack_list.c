/**
 * Implementasi ADT Stack (Stack menggunakan Linked List)
 * 
 * Dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 22 Januari 2019
 * Struktur Data 2020
 * Implementasi untuk bahasa C
 * 
 * !!NOTE!!
 * cara menggunakan lihat pada fungsi main()
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/* Struktur Node */

typedef struct stackNode_t {
    int data; // isi data nodenya
    struct stackNode_t *next; // (head) untuk nyambungin ke node selanjutnya
} StackNode; // tipedata yg isinya node

/* Struktur ADT Stack */

typedef struct stack_t { // kalau ada _ berarti stack inti
    StackNode *_top;  // node teratas
    unsigned _size; // sejenis index atau ukurannya
} Stack;  // tipedata yg isinya stack init / utama

/* Function prototype */

void stack_init(Stack *stack);
bool stack_isEmpty(Stack *stack);
void stack_push(Stack *stack, int value);
void stack_pop(Stack *stack);
int stack_top(Stack *stack);
unsigned stack_size(Stack *stack);

/* Function definition below */

void stack_init(Stack *stack) 
{
    stack->_size = 0; // set ukurannya kosong
    stack->_top = NULL; // set paling atasnya kosong
}

bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL); // kalau paling atasnya null ya kosong
}

// udah pasti push front karena stack
void stack_push(Stack *stack, int value) 
{
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));  // alokasi memori
    if (newNode) {  // kalau sudah terbentuk
        stack->_size++; // ukurannya di tambah
        newNode->data = value;  // masukin value yg mau di push
        
        if (stack_isEmpty(stack)) newNode->next = NULL; // kalau stack kosong, maka jadikan node baru sebagai top
        else newNode->next = stack->_top; // kalau ga kosong, next/pantat dari node barunya di jadiin top 

        stack->_top = newNode; // topnya masukin node baru karena LIFO
    }
}

void stack_pop(Stack *stack) 
{
    if (!stack_isEmpty(stack)) {
        StackNode *temp = stack->_top; // nampung nilai top ke variabel temp, karena nnti mau di pop/keluarin
        stack->_top = stack->_top->next; // memperbarui topnya ke stack di bawahnya, karena yg ini mau di hapus
        free(temp); // hapus nilai dri top sebelumnya
        stack->_size--; // kurangin sizenya
    }
}

int stack_top(Stack *stack) // alias TOS (top of stack)
{
    if (!stack_isEmpty(stack)) // kalau stacknya ga kosong
        return stack->_top->data; // yaa return nilai topnya 
    return 0; // kaalau stack kosong yaa return 0 
}

unsigned stack_size(Stack *stack) {
    return stack->_size; // return sizenya ada brp
}

int main(int argc, char const *argv[])
{
    // Buat objek Stack
    Stack myStack;

    // PENTING! Jangan lupa diinisialisasi
    stack_init(&myStack);

    // Operasi pada stack
    stack_push(&myStack, 1);
    stack_push(&myStack, 2);
    stack_push(&myStack, 3);

    // cetak isi stack
    while (!stack_isEmpty(&myStack)) {
        printf("%d ", stack_top(&myStack));
        stack_pop(&myStack);
    } // isinya : 3 2 1 karena stack itu LIFO
    puts("");
    return 0;
}