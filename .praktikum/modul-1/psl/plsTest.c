// #include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
// using namespace std;
#include <stdbool.h>

typedef struct tnode_t
{
    char nama[1011];
    int umur, priority;
    struct tnode_t *next;
} pQueueNode;

typedef struct pq // test
{
    int size;
    pQueueNode *top;
} PriorityQueue;

void init(PriorityQueue *ipq)
{
    ipq->top = 0;
}

bool pq_isEmpty(PriorityQueue *ipq)
{
    return (ipq->top == 0);
}

int flag_1 = 1; // jika ada yang sama
char nama1[1011];
char nama2[1011];
int prioritas_1, prioritas_2;

void pq_push(PriorityQueue *ipq, char nama[], int umur, int prioritas)
{
    pQueueNode *temp = ipq->top;
    pQueueNode *newNode = (pQueueNode *)malloc(sizeof(pQueueNode)); // alokasi memortri
    strcpy(newNode->nama, nama); // masukin nama
    newNode->umur = umur;
    newNode->priority = prioritas;
    newNode->next = NULL;

    if(pq_isEmpty(ipq)) // kalau kosong ya masukin ke data pertama yaa kerena kosong
    {
        ipq->top = newNode; //
    }
    else // kalau ga kosong
    {
        if(prioritas == ipq->top->priority) // kalau prioritas sama
        {
            // cari umur yg tinggi

            if(umur > ipq->top->umur)
            {
                newNode->next = ipq->top;
                ipq->top = newNode;
            }
            else if(umur == ipq->top->umur)
            {
                flag_1 = 0;
                strcpy(nama1, ipq->top->nama);
                strcpy(nama2, nama);
                prioritas_1 = ipq->top->priority;
                prioritas_2 = prioritas;
                return; // langsung print
            }
            else // kalau umur lebvih kecil
            {
                newNode->next = ipq->top->next;
                ipq->top->next = newNode;
            }
        }
        
        else if(prioritas < ipq->top->priority) // kalau lebih rendah (alias udh sesuai priotyt ngambil paling kecil)
        {
            newNode->next = ipq->top;
            ipq->top = newNode;
        }
        else // kalau priorty lebih besar
        {
            // masukin ke dasar alias paling bawah
            while ((temp->next != NULL && temp->next->priority < prioritas) || 
                (temp->next != NULL && temp->next->priority == 
                prioritas && umur <= temp->next->umur))
            {
                if (umur == temp->next->umur && prioritas == temp->next->priority)
                {
                    flag_1 = 0;
                    strcpy(nama1, temp->next->nama);
                    strcpy(nama2, nama);
                    prioritas_1 = temp->next->priority;
                    prioritas_2 = prioritas;
                    return;
                }
                temp = temp->next; // dri sana
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
}
}

void pq_pop(PriorityQueue *ipq)
{
    if (ipq->top != NULL)
    {
        pQueueNode *temp = ipq->top;
        ipq->top = ipq->top->next;
        free(temp);
    }
}

int main()
{
    PriorityQueue pq;
    init(&pq);
    int n, m, flag_2 = 1;
    scanf("%d %d", &n, &m);
    // tanda untuk pasien selanjutnya gaada
    if (m == n)
        flag_2 = 0;

    while (n--)
    {
        int umur, prioritas;
        char nama[1011];
        scanf("%s %d %d", nama, &umur, &prioritas);
        if (flag_1 && flag_2)
            pq_push(&pq, nama, umur, prioritas);
    }
    
    // jika ada yang sama
    if (flag_1 == 0)
    {
        printf("Kamu jodoh ya %s - %d && %s - %d\n", nama1, prioritas_1, nama2, prioritas_2);
        return 0;
    }

    // jika m = n
    if (flag_2 == 0)
    {
        puts("Full senyum deck");
        return 0;
    }

    while (m--) pq_pop(&pq);
    printf("Pasien selanjutnya adalah: %s - %d\n", pq.top->nama, pq.top->priority);
}