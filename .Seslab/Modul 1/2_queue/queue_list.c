/**
 * Implementasi ADT Queue (Queue menggunakan Linked List)
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

typedef struct queueNode_t {
    int data;   // isi datanya
    struct queueNode_t *next; // untuk nyambungin ke node selanjutnya
} QueueNode;

/* Struktur ADT Queue */

typedef struct queue_t {
    QueueNode   *_front, // menunjuk index paling depan
                *_rear; // menunjuk index paling belakang
    unsigned _size; // jumlah data/ sejenis index
} Queue;

/* Function prototype */

void queue_init(Queue *queue);
bool queue_isEmpty(Queue *queue);
void queue_push(Queue *queue, int value);
void queue_pop(Queue *queue);
int  queue_front(Queue *queue);
int  queue_size(Queue *queue);

/* Function definition below */

void queue_init(Queue *queue)
{
    queue->_size = 0;   // set size nya 0
    queue->_front = NULL; // set paling depannya null
    queue->_rear = NULL;    // set paling belakangnya null
}

bool queue_isEmpty(Queue *queue) {
    return (queue->_front == NULL && queue->_rear == NULL); // memeriksa apakah yg paling depan dan paling belakang kosong apa tidak
}

void queue_push(Queue *queue, int value)
{
    QueueNode *newNode = (QueueNode*) malloc(sizeof(QueueNode)); // alokasi memori untuk node baru
    if (newNode) { // kalau newNode berhasil terbuat
        queue->_size++; // tambah indexnya/jmlh data
        newNode->data = value; // masukin inputan ke newNode
        newNode->next = NULL; // set ujungnya newNode NULL karena newNode udh paling akhir dong
        
        if (queue_isEmpty(queue)) // kalau queuenya kosong            
            queue->_front = queue->_rear = newNode; // membuat nilai front dan read = newnode, JIKA queue kosong
        else { // kalau queuenya ada isi
            queue->_rear->next = newNode; // masukin newNode ke nextnya node si rear (paling belakang), agar newNode jadi yg paling belakang
            queue->_rear = newNode; // set paling belakangnya si newNode ini
        }
    }
}

void queue_pop(Queue *queue)
{
    if (!queue_isEmpty(queue)) {
        QueueNode *temp = queue->_front; // buat variabel temp, buat nyimpen data si front (urutan ke 1)
        queue->_front = queue->_front->next; //Mengganti front dengan referensi next dari front. alias ganti dengan nilai dari urutan ke 2, karena urutan 1 nya mau di pop
        free(temp); // Menghapus node temp.
        
        if (queue->_front == NULL) // jika front kosong
            queue->_rear = NULL; // maka rear juga kosong
        queue->_size--; // kurangin index queuenya
    }
}

int queue_front(Queue *queue)
{
    if (!queue_isEmpty(queue)) { // kalau ga kosong
        return (queue->_front->data); // ya return nilai frontnya (paling depan)
    }
    return (int)0;
}

int queue_size(Queue *queue) {
    return queue->_size; // return nilai sizenya / jumlah index
}

int main(int argc, char const *argv[])
{
    // Buat objek QueueArray
    Queue myQueue;

    // PENTING! Jangan lupa diinisialisasi
    queue_init(&myQueue);

    // Operasi pada queue
    queue_push(&myQueue, 1);
    queue_push(&myQueue, 2);
    queue_push(&myQueue, 3);

    // cetak isi queue
    while (!queue_isEmpty(&myQueue)) {
        printf("%d ", queue_front(&myQueue));
        queue_pop(&myQueue);
    }
    puts("");
    return 0;
}