#include <stdio.h>
#include <stdlib.h>

typedef struct mahasiswa
{
    int nim;
    char nama[100];
    struct mahasiswa *next;
} mhs;

void init (mhs **p) {
    *p = NULL;
}

mhs *alokasi(int nim, char nama[100]) {
    mhs *p;
    p = (struct mahasiswa*) malloc (sizeof(mhs));
    if(p!=NULL) {
        p->next = NULL;
        p->nim = nim;
        p->nama = nama;
    }
    return (p);
}

void add(mhs **p, int nim, char namaData[100]) {
    *p = alokasi(nim);
    *p = alokasi(namaData);
    printf("%d %s", (*p)->nim, (*p)->nama);
}

int main () {
    mhs *head;
    init(&head);
    
    while (1)
    {
        int nim;
        char nama[100];
        scanf("%d %s", &nim, nama);

        int pilihan;
        printf("masih mau lanjut? 1 iya 2 tidak\n");
        scanf("%d", &pilihan);

        if (pilihan == 2) break;
        // else if ()
        
        
    }
    
    

    
    
    // getch();
}