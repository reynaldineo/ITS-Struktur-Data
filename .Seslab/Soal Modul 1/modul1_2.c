/*
SOAL :
Sebuah klinik TC sedang melayani antrian pasien. Setiap pasien mempunyai id dan level urgensi masing-masing yang direpresentasikan oleh sebuah bilangan. Buatlah program untuk mensimulasikan antrian pada klinik tersebut.

Input
Baris pertama adalah Q, banyaknya query. Setiap query dapat berupa:

MASUK id x - id adalah id dari orang dan x adalah tingkat urgensinya.
LAYANI - cetak id orang yang akan dilayani sekarang.
Output
Untuk setiap query LAYANI, cetak id orang yang akan dilayani saat ini. Jika sudah tidak ada pasien yang antri, maka cetak "HORE".
*/

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
    int data;
    struct pqueueNode_t *next;
} PQueueNode;

/* Struktur ADT PriorityQueue menggunakan Linked List */

// Prioritas default: nilai minimum
typedef struct pqueue_t {
    PQueueNode *_top;
    unsigned _size;
} PriorityQueue;

/* Function prototype */

// void pqueue_init(PriorityQueue *pqueue);
// bool pqueue_isEmpty(PriorityQueue *pqueue);
// void pqueue_push(PriorityQueue *pqueue, int value);
// void pqueue_pop(PriorityQueue *pqueue);
// int  pqueue_top(PriorityQueue *pqueue);

/* Function definition below */

void pqueue_init(PriorityQueue *pqueue, int antrian)
{
    pqueue->_top = NULL;
    pqueue->_size = antrian;
}

bool pqueue_isEmpty(PriorityQueue *pqueue) {
    return (pqueue->_top == NULL);
}

void pqueue_push(PriorityQueue *pqueue, int value, int priority)
{
    PQueueNode *temp = pqueue->_top;
    PQueueNode *newNode = \
        (PQueueNode*) malloc (sizeof(PQueueNode));
    newNode->data = value;
    newNode->next = NULL;

    if (pqueue_isEmpty(pqueue)) {
        pqueue->_top = newNode;
        return;
    }

    if (priority < pqueue->_top->data) {
        newNode->next = pqueue->_top;
        pqueue->_top = newNode;
    }
    else {
        while ( temp->next != NULL && 
                temp->next->data < priority)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void pqueue_pop(PriorityQueue *pqueue)
{
    if (!pqueue_isEmpty(pqueue)) {
        PQueueNode *temp = pqueue->_top;
        pqueue->_top = pqueue->_top->next;
        free(temp);
    }
}

int pqueue_top(PriorityQueue *pqueue) {
    if (!pqueue_isEmpty(pqueue))
        return pqueue->_top->data;
    else return 0;
}

#include <string.h>

int main(int argc, char const *argv[])
{
    // Buat objek PriorityQueue
    PriorityQueue myPque;

    // banayaknya querry
    int q;
    printf("Masukan jumlah querry ");
    scanf("%d", &q);
    // PENTING! Jangan lupa diinisialisasi
    pqueue_init(&myPque, q);

    while (q--)
    {
        char input[10];
        scanf("%s, input");

        int id, x; 

        if (strcmp(input,"MASUK")==0) {
            scanf("%d %d", &id, &x);
            pqueue_push(&myPque, id, x);
        } else if (strcmp(input,"LAYANI")==0) {
            // pqueue_pop(&myPque);
            // cetak isi pque
            while (!pqueue_isEmpty(&myPque)) {
                printf("%d ", pqueue_top(&myPque));
                pqueue_pop(&myPque);
            }
            puts("");
        } else if (pqueue_isEmpty) {
            printf("HORE");
            break;
        }
        }


    
    return 0;
}