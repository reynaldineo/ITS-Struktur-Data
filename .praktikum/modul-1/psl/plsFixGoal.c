#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/* Struktur Node */

typedef struct pqueueNode_t {
    char namaPasien [1000];
    int umurPasien, skalaPasien;
    struct pqueueNode_t *next;
} PQueueNode;

/* Struktur ADT PriorityQueue menggunakan Linked List */

typedef struct pqueue_t {
    PQueueNode *_top;
    unsigned _size;
} PriorityQueue;

/* Function definition below */

void pqueue_init(PriorityQueue *pqueue) {
    pqueue->_top = NULL;
    pqueue->_size = 0;
}

bool pqueue_isEmpty(PriorityQueue *pqueue) {
    return (pqueue->_top == NULL);
}

char nama1 [1000], nama2 [1000];
int skala1, skala2;
int cekUmurPenyakit = 0;

void pqueue_push(PriorityQueue *pqueue, char nama[], int umur, int skalaPenyakit) {
    PQueueNode *temp = pqueue->_top;
    PQueueNode *newNode = (PQueueNode*) malloc (sizeof(PQueueNode)); // semua data

    strcpy(newNode->namaPasien, nama); // input nama
    newNode->umurPasien = umur; // input umur
    newNode->skalaPasien = skalaPenyakit; // input skala
    newNode->next = NULL;

    if (pqueue_isEmpty(pqueue)) { // kalau kosong masukin ke node  pertama
        pqueue->_top = newNode; // semua data masukin kr top
        return; 
    }

    // >> dari soal

    // kalau skala sama
    if (skalaPenyakit == pqueue->_top->skalaPasien) { // kalau skalanya sama kan di suruk cek umurnya
        // >cek umur

        // kalau umur lebih besar
        if (umur > pqueue->_top->umurPasien) {
            newNode->next = pqueue->_top; // untuk buat ke paling atas, next newnode di sambung ke top yg udh di stack
            pqueue->_top = newNode; // ubah top stacknya menjadi data dari newNode alias newNode jadi topnya
        }

        // kalau umur sama, di atas jg cek skala sama, berarti di print JODOh
        else if (umur == pqueue->_top->umurPasien) {
            cekUmurPenyakit = 1;
            strcpy(nama1, pqueue->_top->namaPasien); // pasien pertama nya
            strcpy(nama2, nama); // inputan
            skala1 = pqueue->_top->skalaPasien;
            skala2 = skalaPenyakit; // inputan
            return; // langsung print/
        }

        // kalau umur lebih kecil
        else {
            newNode->next = pqueue->_top->next; 
            pqueue->_top = newNode; 
        }
    }

    // kalau skala lebih kecil (ga ngubah)
    else if (skalaPenyakit < pqueue->_top->skalaPasien) {
        newNode->next = pqueue->_top;
        pqueue->_top = newNode;
    }

    // kalau skala lebih besar
    else {
        while ((temp->next != NULL && temp->next->skalaPasien < skalaPenyakit) 
        || (temp->next != NULL && temp->next->skalaPasien == skalaPenyakit && umur <= temp->next->umurPasien)) {
            // kalau umur sama skala sama, print JODOH
            if (umur == temp->next->umurPasien 
            && skalaPenyakit == temp->next->skalaPasien) {
                // sama kayak yg di atas
                cekUmurPenyakit = 1;
                strcpy(nama1, pqueue->_top->namaPasien); // pasien pertama nya
                strcpy(nama2, nama); // inputan
                skala1 = pqueue->_top->skalaPasien;
                skala2 = skalaPenyakit; // inputan
                return; // langsung print
            }
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void pqueue_pop(PriorityQueue *pqueue) {
    if (!pqueue_isEmpty(pqueue)) {
        PQueueNode *temp = pqueue->_top;
        pqueue->_top = pqueue->_top->next;
        free(temp);
    }
}

// int pqueue_top(PriorityQueue *pqueue) {
//     if (!pqueue_isEmpty(pqueue))
//         return pqueue->_top->data;
//     else return 0;
// }

int main(int argc, char const *argv[])
{
    // Buat objek PriorityQueue
    PriorityQueue myPque;

    // PENTING! Jangan lupa diinisialisasi
    pqueue_init(&myPque);

    int n, m, cekSama;
    scanf("%d %d", &n, &m);

    if(m == n) cekSama = 0; // kalau sama yaa ga ada pasiaen yg bisa di cek
    
    while (n--) {
        char nama[1000];
        int umur, skalaPenyakit;
        scanf("%s %d %d", nama, &umur, &skalaPenyakit);

        // PUSH
        // if ((cekSama && cekUmurPenyakit) == 0) {
            pqueue_push(&myPque, nama, umur, skalaPenyakit);
        // }
    }

    // Jika umur dan skalaPenyakit sama
    if (cekUmurPenyakit == 1) {
        printf("Kamu jodoh ya %s - %d && %s - %d\n", nama1, skala1, nama2, skala2);
        return 0;
    }

    // Jika tidak ada pasien yg dapat diobati selanjutnya
    if (cekSama == 1) {
        printf("Full senyum deck");
        return 0;
    }

    // Untuk ngeprint pasien selanjutnya 
    while (m--)
        pqueue_pop(&myPque);
    printf("Pasien selanjutnya adalah: %s - %d\n", myPque._top->namaPasien, myPque._top->skalaPasien);


    return 0;
}