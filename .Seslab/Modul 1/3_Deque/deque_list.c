/**
 * Implementasi ADT Deque (Double-ended Queue)
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

typedef struct dnode_t {
    int data;
    struct dnode_t      \
        *next,  // referensi untuk data selanjutnya
        *prev;  // referensi untuk data sebelumnya
} DListNode;

/* Struktur ADT Deque */
/* Implementasi didasarkan pada Doubly-Linked List */

typedef struct deque_t {
    DListNode           \
        *_head, // menunjuk index paling depan
        *_tail; // menunjuk index paling belakang
    unsigned _size;
} Deque;

/* DAFTAR FUNGSI YANG TERSEDIA */

DListNode* __dlist_createNode(int value);
void deq_init(Deque *deque);
bool deq_isEmpty(Deque *deque);
void deq_pushFront(Deque *deque, int value);
void deq_pushBack(Deque *deque, int value);
int  deq_front(Deque *deque);
int  deq_back(Deque *deque);
void deq_popFront(Deque *deque);
void deq_popBack(Deque *deque);

/* Definisi Fungsi */

DListNode* __dlist_createNode(int value)
{
    DListNode *newNode = \
        (DListNode*) malloc (sizeof(DListNode)); // alokasi memori untuk node baru
    
    if (!newNode) return NULL; // kalau gaga terbuat return NULL
    newNode->data = value;  // masukin nilai inputan ke data dari newNode
    newNode->next = NULL; // set next dari newNode NULL
    newNode->prev = NULL; // set prev dari newNode NULL

    return (DListNode*) newNode; // return newNode yang udah di set isinya
}

void deq_init(Deque *deque)
{
    deque->_head = deque->_tail = NULL; // set head dan tail nya null
    deque->_size = (unsigned) 0;  // set sizenya 0
}

bool deq_isEmpty(Deque *deque) {
    return (deque->_head == NULL && \
            deque->_tail == NULL); // cek kosong cukup cek kepala dan ekornya null apa engga 
}

void deq_pushFront(Deque *deque, int value)
{
    DListNode *newNode = __dlist_createNode(value); // buat node baru dan set nilainya
    if (newNode) { // kalau newNode berhasil terbuat 
        deque->_size++; // tambah sizenya/indexnya
        if (deq_isEmpty(deque)) { // kalau deque kosong
            deque->_head = newNode; // jadikan newNodenya menjadi head
            deque->_tail = newNode; // jadikan newNodenya juga menjadi tail, yaa karena cuman ada 1 node
            return;
        }
        // Jika tidak kosong
        newNode->next = deque->_head; // sambungin next nodeny ke head (node paling awal) 
        deque->_head->prev = newNode; // buat prev (sebelum/didepannya) dari head (node paling awal) berisi nilai  node baru
        deque->_head = newNode; // pindah (penunjuk) head ke node baru
    }
}

void deq_pushBack(Deque *deque, int value)
{
    DListNode *newNode = __dlist_createNode(value); // buat node baru
    if (newNode) {  // kalau node barunya berhasil terbentuk 
        deque->_size++; // nambah size dari dequenya
        if (deq_isEmpty(deque)) { // kalau dequenya kosong
            deque->_head = newNode; // langsung head isi newNode
            deque->_tail = newNode; // tail juga isi newNode, karena cuman 1 node
            return;
        }
        // kalau deque ga kosong /empty
        deque->_tail->next = newNode; // set next dari node paling ujung (tail) isi newNode
        newNode->prev = deque->_tail; // set prev (sebelumnya) dari node baru isi tail sebelumnya yg blm di update
        deque->_tail = newNode; // set tail terbaru (paling akhir) menjadi newNode yg baru di tambahkan
    }
}

int deq_front(Deque *deque) {
    if (!deq_isEmpty(deque)) { // ngecek apakh kosong atau tidak
        return (deque->_head->data);  // retur data head (paling depan)
    }
    return 0;
}

int deq_back(Deque *deque) {
    if (!deq_isEmpty(deque)) { // ngecek apakah kosong atau tidak
        return (deque->_tail->data); // return data tail (paling belakang)
    }
    return 0;
}

void deq_popFront(Deque *deque)
{
    if (!deq_isEmpty(deque)) {  // kalau ga empty
        DListNode *temp = deque->_head; // buat temp yg isinya daya head
        if (deque->_head == deque->_tail) { // kalau head == tail, alias datanya 1
            deque->_head = NULL;  // set head NULL karena datanya habis
            deque->_tail = NULL;  // set tail NULL karena datanya habis
            free(temp); // hapus tempt
        }
        else {  // kalau datanya lebih dri 1
            deque->_head = deque->_head->next;  // buat headnya isi next dri head (data ke 2)
            deque->_head->prev = NULL;  // buat prev head (data pertama) null
            free(temp); // hapus temp
        }
        deque->_size--; // kurangin indexnya
    }
}

void deq_popBack(Deque *deque)
{
    if (!deq_isEmpty(deque)) { // kalau ga kosong
        DListNode *temp; // buat temp
        if (deque->_head == deque->_tail) { // kalau head == tail, alias datanya 1
            temp = deque->_head;  // isi temp dengan data head atau tail sama aja
            deque->_head = NULL;  // set head NULL karena datanya habis
            deque->_tail = NULL;  // set tail NULL karena datanya habis
            free(temp); // hapus temp
        }
        else {  // kalau data lebih dari 1
            temp = deque->_tail;  // masukin tail ke temp
            deque->_tail = deque->_tail->prev;  // masukin data sebelum tail (data ke 2 terakhir) ke tail
            deque->_tail->next = NULL;  // set next dari tail baru NULL
            free(temp); // hapus temp
        }
        deque->_size--; // kurangin indexnya
    }
}

int main(int argc, char const *argv[])
{
    Deque mydeq;
    deq_init(&mydeq);

    deq_pushBack(&mydeq, 1);
    deq_pushBack(&mydeq, 12);
    deq_pushBack(&mydeq, 6);
    deq_pushBack(&mydeq, 7);
    deq_pushBack(&mydeq, 2);

    deq_pushFront(&mydeq, 11);
    deq_pushFront(&mydeq, 8);
    deq_pushFront(&mydeq, 0);

    deq_popBack(&mydeq);
    deq_popFront(&mydeq);

    while (!deq_isEmpty(&mydeq)) {
        printf("%d ", deq_front(&mydeq));
        deq_popFront(&mydeq);
    }
    puts("");
    return 0;
}