#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct mahasiswa_t{
    int _nim;
    char _nama[100];
    struct Mahasiswa *next;
} Mahasiswa;

void init(Mahasiswa **p){ // double pointer karena pass by value
    *p = NULL;
}

Mahasiswa *alokasi(int nim, char nama[]){
    Mahasiswa *p;
    p = (Mahasiswa*)malloc(sizeof(Mahasiswa));
    if(p != NULL){
        p->next = NULL;
        p->_nim =  nim;
        strcpy(p->_nama, nama);

    }    
    return (p);
}

void add(Mahasiswa **p, int nim,  char nama[]){
    *p = alokasi(nim, nama);
    printf("Data yang telah di input :\n");
    printf("Nim : %d \nNama : %s\n", (*p)->_nim, (*p)->_nama);
}

int main () {
    Mahasiswa *head; // pointer main untuk akses struct
    init(&head); //

    int nJumlah;
    printf("Masukan jumlah data yang ingin di input : ");
    scanf("%d", &nJumlah);
    while(nJumlah--){
        int nim;
        char nama[100];
        printf("Masukan nim dan nama yang ingin di input : ");
        scanf("%d %s", &nim, nama);
        add(&head, nim, nama);
    }
    return 0;
}