#include <stdio.h>
#include <stdlib.h>

struct TNode{
    int data;
    struct TNode *next;
};

struct TNode *head, *tail;

void init(){
    head = NULL;
}

int isEmpty(){
    if(head == NULL) return 1;
    else return 0;
}

void insertDepan(int databaru){
    struct TNode *baru, *bantu;
    baru = (struct TNode*)malloc(sizeof(struct TNode));
    baru->data = databaru;
    baru->next = baru;
    if(isEmpty()==1){
        head = baru;
        head->next = head;
    }
    else{
        bantu = head;
        while(bantu->next!=head){
            bantu = bantu->next;
        }
        baru->next=head;
        head=baru;
        bantu->next = head;
    }
    printf("Data masuk\n");
}

void insertBelakang(int databaru){
    struct TNode *baru, *bantu;
    baru = (struct TNode*)malloc(sizeof(struct TNode));
    baru->data = databaru;
    baru->next = baru;
    if(isEmpty()==1){
        head = baru;
        head->next = head;
    }
    else{
        bantu = head;
        while(bantu->next!=head){
            bantu = bantu->next;
        }
        bantu->next = baru;
        baru->next = head;
    }
    printf("Data masuk\n");
}

void tampil() {
    struct TNode *b;
    b = head;
    if (isEmpty ()==0) {
        do{
            printf ("%d ",b->data);
            b=b->next;

        } while (b!=head) ;
        printf ("\n");
    } else printf("Masih kosong\n") ;
}

void hapusBelakang (){
    struct TNode *hapus, *bantu;
    if (isBmpty ()==0) {
        int d;
        hapus = head;
        d = head->data;
        if(head->next != head) {
            bantu = head;
            while (bantu->next != head) {
                bantu = bantu->next;
            }
            head = head->next;
            free(hapus);
            bantu->next = head;
        } else{
            head=NULL;
        }
        printf("%d terhapus \n", d);
    } else printf("Masih kosong\n");
}

