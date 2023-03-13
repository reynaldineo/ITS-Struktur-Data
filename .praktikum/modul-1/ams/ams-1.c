#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/* Struktur Node */

typedef struct pqueueNode_t {
    int id, data; // isi data nodenya
    struct pqueueNode_t *next;  // untuk nyambungin ke node selanjutnya
} PQueueNode;

/* Struktur ADT PriorityQueue menggunakan Linked List */

// Prioritas default: nilai minimum
typedef struct pqueue_t {
    PQueueNode *_top; // nunujuk yg paling atas (priority teratas)
    unsigned _size; // ukurannya/jumlah index
} PriorityQueue;


/* Function definition below */

void pqueue_init(PriorityQueue *pqueue)
{
    pqueue->_top = NULL;  // set kepalanya null
    pqueue->_size = 0;  // set size nya 0
}

bool pqueue_isEmpty(PriorityQueue *pqueue) {
    return (pqueue->_top == NULL); // kalau topnya null ya kosong
}

void pqueue_push(PriorityQueue *pqueue, int value1, int value2)
{
    PQueueNode *temp = pqueue->_top; // Buat node temp (temporary) yang mengacu pada top pqueue.
    PQueueNode *newNode = \
        (PQueueNode*) malloc (sizeof(PQueueNode)); // Buat node baru.
    newNode->id = value1; // masukin inputan ke data newNode
    newNode->data = value2; // masukin inputan ke data newNode
    newNode->next = NULL; // set next newNode menjadi NULL

    if (pqueue_isEmpty(pqueue)) { // jika kosong
        pqueue->_top = newNode; // masukin newNode nya ke top 
        return;
    }

    if (value1 > pqueue->_top->data) { // data node baru lebih kecil dari top
        newNode->next = pqueue->_top; // Buat next node baru ke top pqueue.
        pqueue->_top = newNode; // Pindah top pqueue ke node baru.
    }
    else { // data node baru lebih besar dari top
        while ( temp->next != NULL && 
                temp->next->data < value1) // Iterasi temp sampai data sebelum node baru tidak ada yang lebih besar. ATAU sampai paling akhir
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

    int q;
    scanf("%d", &q);

    while (q--)
    {
      int id, n, m, skor;
      scanf("%d %d %d", &id, &n, &m);
      skor = (n*500) + (m*-200);
      pqueue_push(&myPque, id, skor);

      printf("%d\n", pqueue_top(&myPque));

    }
    




    return 0;
}