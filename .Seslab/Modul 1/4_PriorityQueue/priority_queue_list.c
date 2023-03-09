/**
 * Implementasi ADT PriorityQueue menggunakan Linked List
 * [default: minimum priority]
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

typedef struct pqueueNode_t {
    int data; // isi data nodenya
    struct pqueueNode_t *next;  // untuk nyambungin ke node selanjutnya
} PQueueNode;

/* Struktur ADT PriorityQueue menggunakan Linked List */

// Prioritas default: nilai minimum
typedef struct pqueue_t {
    PQueueNode *_top; // nunujuk yg paling atas (priority teratas)
    unsigned _size; // ukurannya/jumlah index
} PriorityQueue;

/* Function prototype */

void pqueue_init(PriorityQueue *pqueue);
bool pqueue_isEmpty(PriorityQueue *pqueue);
void pqueue_push(PriorityQueue *pqueue, int value);
void pqueue_pop(PriorityQueue *pqueue);
int  pqueue_top(PriorityQueue *pqueue);

/* Function definition below */

void pqueue_init(PriorityQueue *pqueue)
{
    pqueue->_top = NULL;  // set kepalanya null
    pqueue->_size = 0;  // set size nya 0
}

bool pqueue_isEmpty(PriorityQueue *pqueue) {
    return (pqueue->_top == NULL); // kalau topnya null ya kosong
}

void pqueue_push(PriorityQueue *pqueue, int value)
{
    PQueueNode *temp = pqueue->_top; // Buat node temp (temporary) yang mengacu pada top pqueue.
    PQueueNode *newNode = \
        (PQueueNode*) malloc (sizeof(PQueueNode)); // Buat node baru.
    newNode->data = value; // masukin inputan ke data newNode
    newNode->next = NULL; // set next newNode menjadi NULL

    if (pqueue_isEmpty(pqueue)) { // jika kosong
        pqueue->_top = newNode; // masukin newNode nya ke top 
        return;
    }

    if (value < pqueue->_top->data) { // data node baru lebih kecil dari top
        newNode->next = pqueue->_top; // Buat next node baru ke top pqueue.
        pqueue->_top = newNode; // Pindah top pqueue ke node baru.
    }
    else { // data node baru lebih besar dari top
        while ( temp->next != NULL && 
                temp->next->data < value) // Iterasi temp sampai data sebelum node baru tidak ada yang lebih besar. ATAU sampai paling akhir
            temp = temp->next; // KALAU DI HAPUS, ga error
        newNode->next = temp->next; // Arahkan next node baru ke next dari temp. (sambungin)
        temp->next = newNode; // Arahkan next dari temp ke node baru.
    }
}

void pqueue_pop(PriorityQueue *pqueue)
{
    if (!pqueue_isEmpty(pqueue)) { // kalau blm empty
        PQueueNode *temp = pqueue->_top; // buat temp yg isinya top
        pqueue->_top = pqueue->_top->next; // Memindah top pqueue ke node selanjutnya.
        free(temp); // hapus 
        // pqueue->_size--; // tapi kenapa di modul ga ada ya
    }
}

int pqueue_top(PriorityQueue *pqueue) {
    if (!pqueue_isEmpty(pqueue)) // kalau ga kosong
        return pqueue->_top->data; // ya langsung return top datanya
    else return 0;
}

int main(int argc, char const *argv[])
{
    // Buat objek PriorityQueue
    PriorityQueue myPque;

    // PENTING! Jangan lupa diinisialisasi
    pqueue_init(&myPque);

    // Operasi pada priority queue
    pqueue_push(&myPque, 12);
    pqueue_push(&myPque, 1);
    pqueue_push(&myPque, 3);

    // cetak isi pque
    while (!pqueue_isEmpty(&myPque)) {
        printf("%d ", pqueue_top(&myPque));
        pqueue_pop(&myPque);
    }
    puts("");
    return 0;
}