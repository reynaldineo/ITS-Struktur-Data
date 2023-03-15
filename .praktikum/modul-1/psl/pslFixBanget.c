#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tnode_t {
    char namaPasien[1000];
    int umurPasien, skalaPasien;
    struct tnode_t *next;
} pQueueNode;

typedef struct pqueue_t {
    int _size;
    pQueueNode *_top;
} PriorityQueue;

void init(PriorityQueue *pqueue) {
    pqueue->_top = 0;
}

bool pq_isEmpty(PriorityQueue *pqueue) {
    return (pqueue->_top == NULL);
}

char nama1[1000], nama2[1000];
int skala1, skala2;
int cekUmurPenyakit = 0; 

void pq_push(PriorityQueue *pqueue, char nama[], int umur, int prioritas) {
    pQueueNode *temp = pqueue->_top;
    pQueueNode *newNode = (pQueueNode *)malloc(sizeof(pQueueNode)); // alokasi memortri untuk semua data

    strcpy(newNode->namaPasien, nama); // input
    newNode->umurPasien = umur; // input umur
    newNode->skalaPasien = prioritas;
    newNode->next = NULL;

    if(pq_isEmpty(pqueue)) { // kalau kosong ya masukin ke data pertama yaa kerena kosong
        pqueue->_top = newNode; 
    }
    else { // kalau ga kosong
    // >> dari soal

        // kalau skala sama
        if(prioritas == pqueue->_top->skalaPasien) { // kalau skalanya sama kan di suruk cek umurnya
            // > cek umur

            // kalau umur lebih besar
            if(umur > pqueue->_top->umurPasien) {
                newNode->next = pqueue->_top; // untuk buat ke paling atas, next newnode di sambung ke top yg udh di stack
                pqueue->_top = newNode; // ubah top stacknya menjadi data dari newNode alias newNode jadi topnya
            }

            // kalau umur sama, di atas jg cek skala sama, berarti di print JODOh
            else if(umur == pqueue->_top->umurPasien) {
                strcpy(nama1, pqueue->_top->namaPasien);
                strcpy(nama2, nama);
                skala1 = pqueue->_top->skalaPasien;
                skala2 = prioritas;
                cekUmurPenyakit = 1;
                return; // langsung print
            }

            // kalau umur lebih kecil
            else {
                newNode->next = pqueue->_top->next;
                pqueue->_top->next = newNode;
            }
        }
        
        // kalau skala lebih kecil (ga ngubah push)
        else if(prioritas < pqueue->_top->skalaPasien) {
            newNode->next = pqueue->_top;
            pqueue->_top = newNode;
        }

        // kalau skala lebih besar
        else {
            while ((temp->next != NULL && temp->next->skalaPasien < prioritas) 
            || (temp->next != NULL && temp->next->skalaPasien 
            == prioritas && umur <= temp->next->umurPasien)) {
                // kalau umur sama skala sama, print JODOH
                if (umur == temp->next->umurPasien && prioritas == temp->next->skalaPasien)
                {
                    cekUmurPenyakit = 1;
                    strcpy(nama1, temp->next->namaPasien);
                    strcpy(nama2, nama);
                    skala1 = temp->next->skalaPasien;
                    skala2 = prioritas;
                    return; // langsung print
                }
                temp = temp->next; 
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

void pq_pop(PriorityQueue *pqueue) {
    if (!pq_isEmpty(pqueue)) {
        pQueueNode *temp = pqueue->_top;
        pqueue->_top = pqueue->_top->next;
        free(temp);
    }
}

int main() {
    PriorityQueue myPque;
    init(&myPque);

    int n, m, cekSama = 0;
    scanf("%d %d", &n, &m);

    if (m == n) cekSama = 1; // kalau sama yaa ga ada pasiaen yg bisa di cek

    while (n--) {
        char nama[1000];
        int umur, skalaPenyakit;
        scanf("%s %d %d", nama, &umur, &skalaPenyakit);

        if (!cekUmurPenyakit && !cekSama) {
            pq_push(&myPque, nama, umur, skalaPenyakit);
        }
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
        pq_pop(&myPque);
    printf("Pasien selanjutnya adalah: %s - %d\n", myPque._top->namaPasien, myPque._top->skalaPasien);

    return 0;
}