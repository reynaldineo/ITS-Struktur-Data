#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct TNode{
    int nim;
    char nama[100];
    TNode *next;
};

TNode *head, *tail;

void init(){
    head = NULL;
    tail = NULL;
}

int isEmpty(){
    if(tail == NULL) return 1;
    else return 0;
}

void insertDepan(int dataBaru, char namaBaru[]){
    TNode *baru; 
    // baru =  new TNode; // temp
    baru = (TNode*) malloc(sizeof(TNode));
    baru->nim = dataBaru;
    strcpy(baru->nama, namaBaru);
    baru->next = NULL;
    if(isEmpty()==1){
        head = tail = baru;
        tail->next = NULL;
    } else {
        baru->next = head;
        head = baru;
    }
    printf("Data masuk\n");
}

void hapusData(){
    TNode *hapus;
    int d;
    if(isEmpty()==0){
        if(head!=tail){
            hapus = head;
            d = hapus->nim;
            head = head->next;
            // delete hapus;
            free(hapus);
        } 
        else {
            d = tail->nim;
            head = tail = NULL;
        }
        printf("Nim %d terhapus\n", d);
    }
    else printf("Masih kosong\n");
}

void tampil(){
    struct TNode *bantu;
    bantu  = head;
    if(isEmpty()==0){
        while(bantu != NULL){
            printf("%s %d\n", bantu->nama, bantu->nim);
            bantu = bantu->next;
        }
        printf("\n");
    } else printf ("Masih kosong\n"); 
}

int main(){
    int nim;
    char nama[100];
    int menu;
    init();

    do{
        printf("menu:\n");
        printf("1 = exit\n");
        printf("2 = inset\n");
        printf("3 = hapus \n");
        scanf("%d", &menu);

        if(menu== 2){
            printf("\n");
            printf("Masukan nama dan nim ");
            scanf("%s %d",nama, &nim);
            insertDepan(nim, nama);
            tampil();
        }
        else if(menu == 3){
            hapusData();
            tampil();
        }
    } while (menu != 1);


    // insertDepan(1, (char*)"Rey");
    // insertDepan(2, (char*)"Budi");
    // tampil();
    // hapusData();
    // tampil();

}


