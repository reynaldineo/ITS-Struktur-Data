#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct TNode{
    int data;
    struct TNode *next;
}TNode;

struct TNode *head, *tail;

void init(){
    head = NULL;
    tail = NULL;
}

int isEmpty(){
    if(tail == NULL) return 1;
    else return 0;
}

void insertDepan(int databaru){
	  struct TNode *baru;
		// baru = new TNode;
        baru = (TNode*) malloc(sizeof(TNode));
		baru->data = databaru;
		baru->next = baru;
		if(isEmpty()==1){
		 head=baru;
		 tail=baru;
		 head->next=head;
		 tail->next=tail;
		}
		else {
			baru->next = head;
			head = baru;
			tail->next = head;
		}
		printf("Data masuk\n");
	}
void tambahBelakang(int databaru){
		struct TNode *baru;
		// baru = new TNode;
        baru = (TNode*) malloc(sizeof(TNode));
		baru->data = databaru;
		baru->next = baru;
		if(isEmpty()==1){
		 head=baru;
		 tail=baru;
		 head->next=head;
		 tail->next=tail;
		}
		else {
			tail->next = baru;
			tail = baru;
			tail->next = head;
		}
		// cout<<"Data masuk\n";
        printf("Data masuk\n");
	}


void tampil(){
	struct TNode *b;
	b = head;
	if(isEmpty()==0){
		do{
			printf("%d \n",b->data);
			b=b->next;
		}while(b!=tail->next);
		printf("\n");
	} else printf("Masih kosong\n");
} 


void hapusDepan(){
	struct TNode *hapus;
	if (isEmpty()==0){
		int d;
		hapus = head;
		d = head->data;
		if(head != tail){
			hapus = head;
			head = head->next;
			tail->next = head;
			// delete hapus;
            free(hapus);
		}else{
			head=NULL;
			tail=NULL;
		}
		printf("%d terhapus\n",d);
	} else printf("Masih kosong\n");
}

void hapusBelakang(){
	struct TNode *hapus,*bantu;
	if (isEmpty()==0){
		int d;
		if(head == tail){
			d = tail->data;
			head = NULL;
			tail = NULL;
		}else{
			bantu = head;
			while(bantu->next != tail){
				bantu = bantu->next;
			}
			hapus = tail;
			tail = bantu;
			d = hapus->data;
			tail->next = head;
			// delete hapus;
            free(hapus);
		}
		printf("%d terhapus\n",d);
	} else printf("Masih kosong\n");
}

void clear(){
	struct TNode *bantu,*hapus;
	if(isEmpty() == 0){
		bantu = head;
		while(bantu->next!=head){
			hapus = bantu;
			bantu = bantu->next;
			// delete hapus;
            free(hapus);
		}
		head = NULL;
		tail = NULL;
	}
}

int main() {
    init();
    insertDepan(10);
    insertDepan(20);
    insertDepan(30);
    tampil();
    hapusBelakang();
    tampil();
    hapusDepan();
    tampil();
    // getch();
}