#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// GAGAL, blm selesai

typedef struct TNode{
    int data;
    struct TNode *next;
};

struct TNode *head;

void init() {
    head = NULL;
}

int isEmpty() {
    if(head == NULL) return 1;
    else return 0;
}

void insertDepan (int databaru){
    struct TNode *baru;
    baru = new TNode;
    baru->data = databaru;
    baru->next = NULL;
    if(isEmpty()==1){
        head = baru;
        head->next = NULL;
    } else {
        baru->next = head;
        
    }
}