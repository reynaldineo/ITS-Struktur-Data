#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct TNode{
    int data;
    TNode *next;
    TNode *prev;
}TNode; 

TNode *head, *tail;
int jmlhData = 0;

void init(){
    head = NULL;
    tail = NULL;
}

int isEmpty(){
	if(tail == NULL) return 1;
	else return 0;
}

void insertDepan (int databaru){
  TNode *baru;
//   baru = new TNode;
  baru = (TNode*) malloc(sizeof(TNode));
  baru->data = databaru;
  baru->next = NULL;
  baru->prev = NULL;
  jmlhData++;
  if(isEmpty()==1){
	head=baru;
	tail=head;
	head->next = NULL;
	head->prev = NULL;
	tail->prev = NULL;
	tail->next = NULL;
  }
  else {
	baru->next = head;
	head->prev = baru;
	head = baru;
  }
    printf("Data masuk\n");
} 

void insertBelakang(int databaru){
	TNode *baru;
	// baru = new TNode;
    baru = (TNode*) malloc(sizeof(TNode));
	baru->data = databaru;
	baru->next = NULL;
	baru->prev = NULL;
    jmlhData++;
	if(isEmpty()==1){
	 head=baru;
	 tail=head;
	 head->next = NULL;
	 head->prev = NULL;
	 tail->prev = NULL;
	 tail->next = NULL;
	}
	else {
	 tail->next = baru;
	 baru->prev = tail;
	 tail = baru;
       tail->next = NULL;
	}
    printf("Data masuk\n");
}

void tampil(){
	TNode *bantu;
	bantu = head;
	if(isEmpty()==0){
		while(bantu!=tail->next){
            printf("%d ", bantu->data);
			bantu=bantu->next;
		}
        printf("\n");
        printf("Jmlh data : %d \n", jmlhData);
	} else printf("Data masuk\n");
}

void tampilBalik(){
	TNode *bantu;
	bantu = tail;
	if(isEmpty()==0){
		while(bantu!=head->prev){
            printf("%d ", bantu->data);
			bantu=bantu->prev;
		}
        printf("\n");
        printf("Jmlh data : %d \n", jmlhData);
	} else printf("Data masuk\n");
}

void hapusDepan(){
	TNode *hapus;
	int d;
	if (isEmpty()==0){
	 if(head->next != NULL){
		hapus = head;
		d = hapus->data;
		head = head->next;
		head->prev = NULL;
		// delete hapus;
        free(hapus);
	 } else {
		d = head->data;
		head = NULL;
          tail = NULL;
	 }
    jmlhData--;
    printf("%d terhapus\n", d);
	} else printf("Data masuk\n");
}

void hapusBelakang(){
	TNode *hapus;
	int d;
	if (isEmpty()==0){
	 if(head->next != NULL){
		hapus = tail;
		d = tail->data;
		tail = tail->prev;
		tail->next = NULL;
		// delete hapus;
        free(hapus);
	 } else {
		d = head->data;
		head = NULL;
		tail = NULL;
	 }
    jmlhData--;
    printf("%d terhapus\n", d);
	} else printf("Data masuk\n");
}

void menu(){
    int angka;
    do{
        printf("\nMenu\n");
        printf("0. keluar\n");
        printf("1. insertDepan\n");
        printf("2. insertBelakang\n");
        printf("3. hapusDepan\n");
        printf("4. hapusBelakang\n");
        printf("5. tampil\n");
        printf("6. tampilBalik\n");
        scanf("%d", &angka);

        if (angka==1) {
            int input;
            scanf("%d", &input);
            insertDepan(input);
        }
        else if(angka==2){
            int input;
            scanf("%d", &input);
            insertBelakang(input);
        }
        else if(angka==3) hapusDepan();
        else if(angka==4) hapusBelakang();
        else if(angka==5) tampil();
        else if(angka==6) tampilBalik();
    } while (angka != 0);
}

int main(){
    init();

    insertDepan(10);
    insertDepan(20);
    insertDepan(30);
    insertBelakang(40);
    insertBelakang(50);
    tampil();
    tampilBalik();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();

    // menu();
    return 0;
}

