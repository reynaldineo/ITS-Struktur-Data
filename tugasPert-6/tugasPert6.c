#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_t {
    int nim;
    char nama[101];
    struct node *next;
} node;

void init(node **head) {
    *head = NULL;
}

node *alokasi(int nim, char nama[]) {
    node *p = (node*) malloc(sizeof(node));
    if (p != NULL) {
        p->next = NULL;
        strcpy(p->nama, nama);
        p->nim = nim;
    }
    return p;
}

void add(node **head, int nim, char nama[]) {
    *head = alokasi(nim, nama);
    printf("%d %s\n", (*head)->nim, (*head)->nama);
}

int main() {
    node *head;
    init(&head);
    int nim, t,i;
    char nama[101];
    printf("Masukkan jumlah mahasiswa: ");
    scanf("%d", &t);
    for ( i = 0; i < t; i++) {
        printf("Masukkan NIM dan nama mahasiswa ke-%d: ", i+1);
        scanf("%d %s", &nim, nama);
        add(&head, nim, nama);
    }
    return 0;
}


