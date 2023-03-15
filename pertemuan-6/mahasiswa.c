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
    
    int nData;
    scanf("%d", &nData);

    for (int i = 0; i < nData; i++)
    {

        int data;
        char namaData[100];
        scanf("%d %s", data, namaData);
        add(&head, data, namaData);
    }
    



    // while (1)
    // {
    //     mhs *head;
    //     init(&head);
    //     printf("apakah masih mau input\n (Y\\N) ");
    //     char pilihan;
    //     scanf("%c", &pilihan);

    //     if (pilihan == 'Y')
    //     {
    //         int data;
    //         add(&head, 20);
    //     } 
    //     else if (pilihan == 'N')
    //     {
    //         break;
    //     }
        
        
        
    // }
    
    
    // getch();
}