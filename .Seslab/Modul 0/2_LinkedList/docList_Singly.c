/**
 * Implementasi ADT SInglyList (Singly Linked List)
 * 
 * Dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 22 Januari 2019
 * Struktur Data 2020
 * Implementasi untuk bahasa C
 * 
 * !!NOTE!!
 * cara menggunakan lihat pada fungsi main()
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/* Struktur Node */

typedef struct snode_t {
    int data;   // isi data nodenya
    struct snode_t *next;   // untuk nyambungin ke node selanjutnya (kalau ada/mau di buat sambunggannya)
} SListNode;

/* Struktur ADT SinglyList */

typedef struct slist_t {
    unsigned _size; // sejenis index kalau di array, biar tau nodenya ada berapa, dan mau akses node ke berapa
    SListNode *_head;   // node pertama (head), di sambung di struct SListNode, kalau nambah node nnti di snode_t *next
} SinglyList;

/* DAFTAR FUNGSI YANG TERSEDIA */

void slist_init(SinglyList *list);
bool slist_isEmpty(SinglyList *list);
void slist_pushFront(SinglyList *list, int value);
void slist_popFront(SinglyList *list);
void slist_pushBack(SinglyList *list, int value);
void slist_popBack(SinglyList *list);
void slist_insertAt(SinglyList *list, int index, int value);
void slist_removeAt(SinglyList *list, int index);
void slist_remove(SinglyList *list, int value);
int  slist_front(SinglyList *list);
int  slist_back(SinglyList *list);
int  slist_getAt(SinglyList *list, int index);

/* Function definition below */

void slist_init(SinglyList *list) 
{
    list->_head = NULL; // set kepala/awalannya kosong, yaa karena blm di isi nilai
    list->_size = 0;    // set size/index nya 0, yaa seperti array
}

// Memeriksa apakah list kosong.
bool slist_isEmpty(SinglyList *list) {
    return (list->_head == NULL); // kalau kepalanya null ya kosong
}

// Memasukkan data baru dari belakang.
void slist_pushBack(SinglyList *list, int value)
{
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode)); // buat node baru 
    if (newNode) {
        list->_size++;  // nambahin size / kayak nambah index gitu
        newNode->data = value;  // masukin datanya ke node barunya
        newNode->next = NULL;   // ngestop index node barunya
        
        if (slist_isEmpty(list)) // jika list kosong
            list->_head = newNode; // headnya, adalah node baru / data 
        else {
            SListNode *temp = list->_head;  // bantuan untuk ngecek node paling belakangnya, dari head/paling awalnya masukin ke temp biar tempnya maju terus ngecek kosong/null nya dmna
            while (temp->next != NULL)  // perulanggan terus sampai temp-nya belum nemu null
                temp = temp->next;  // nimpa temp baru, ke temp lama (kayak majuin index, lewat next)
            temp->next = newNode;   
        }
    }
}

// Memasukkan data baru dari depan.
void slist_pushFront(SinglyList *list, int value) 
{
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode)); // buat node baru
    if (newNode) {
        list->_size++;  // nambah index
        newNode->data = value;  // masukin inputan/nilai ke data di nodenya

        if (slist_isEmpty(list)) newNode->next = NULL; // Jika list kosong, jadikan node baru sebagai head.
        else newNode->next = list->_head; // yg paling depan/head di masukin ke nextnya node baru, alias urutannya jadi di belakang node baru.  ATAU bisa di artiin gini: Jika tidak kosong, maka jelas bahwa next dari node baru adalah head.
        list->_head = newNode; // masukin datanya ke depan/head
    }
}

// Memasukkan data baru pada posisi tertentu.
void slist_insertAt(SinglyList *list, int index, int value)
{
    /* Kasus apabila posisinya melebihi batas */
    if (slist_isEmpty(list) || index >= list->_size) { // index di akhir
        slist_pushBack(list, value);    // sama aja kayak push back
        return;    
    }
    else if (index == 0 || index < 0) { // index di awal, alias blm ada atau 0
        slist_pushFront(list, value);   // sama aja kayak push front
        return;
    }
    
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode)); // buat node baru
    if (newNode) {
        SListNode *temp = list->_head;  // buat temp untuk bantu, search node
        int _i = 0;
        while (temp->next != NULL && _i < index-1) { // selama temp next belum null/habis DAN indexnya jug belum habis
            temp = temp->next;  // nextnya, di masukin/ di hubungin ke temp lagi, alias di majuin terusss
            _i++;   // nambah index, biar maju terus
        }
        newNode->data = value;  // masukin inputan ke data newNode
        newNode->next = temp->next; // Arahkan next dari node baru menuju node selanjutnya dari node terakhir hasil penelusuran.
        temp->next = newNode; // Sambungkan node hasil penelusuran menuju node baru.
        list->_size++; // nambah indexnya, karena kan ada node baru
    }
}

// Menghapus node/data paling depan.
void slist_popFront(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;  // Tampung head pada variabel temp (temporary).
        list->_head = list->_head->next; // Mengganti head dengan referensi/next dari head.
        free(temp); // Menghapus node temp.
        list->_size--;  // menghapus indexnya
    }
}

// Menghapus node/data paling belakang.
void slist_popBack(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        SListNode *nextNode = list->_head->next;
        SListNode *currNode = list->_head;

        if (currNode->next == NULL) { //Jika next dari currNode kosong, maka artinya jumlah data hanya satu. 
            free(currNode); // Hapus langsung node tersebut.
            list->_head = NULL;
            return;
        }

        while (nextNode->next != NULL) { // cek terus sampai akhir paling ujung/alias sebelum null
            currNode = nextNode;    // untuk majuin nodenya
            nextNode = nextNode->next;  // sama untuk manjuin nodenya
        }
        currNode->next = NULL;  // node selanjutnya(next) di set null, karena ini udh di posisi akhir
        free(nextNode); // Hapus node selanjutnya (nextNode).
        list->_size--;  // ngurangin indexnya
    }
}

// menghapus data sesaui index
void slist_removeAt(SinglyList *list, int index)
{
    if (!slist_isEmpty(list)) {
        
        /* Kasus apabila posisinya melebihi batas */
        if (index >= list->_size) {
            slist_popBack(list);
            return;    
        }
        else if (index == 0 || index < 0) { // kalau 0 alias di depan
            slist_popFront(list);   // Cukup melakukan popFront dan selesai.
            return;
        }
        
        SListNode *temp = list->_head;
        int _i = 0;
        while (temp->next != NULL && _i < index-1) { // search terus sampai belum null
            temp = temp->next;
            _i++;
        }
        SListNode *nextTo = temp->next->next;
        free(temp->next);
        temp->next = nextTo;
        list->_size--;
    }
}

// menghapus data sesuai value yang cocok, yg pertama kali di temukan
void slist_remove(SinglyList *list, int value)
{
    if (!slist_isEmpty(list)) {
        SListNode *temp, *prev; 
        temp = list->_head;

        if (temp->data == value) { // kalau langsung ketemu di depan
            slist_popFront(list);   // cukup di pop front
            return;
        }
        while (temp != NULL && temp->data != value) { // selama belum null dan datanya belum sama sesuai inputan
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) return; // kalau sampai null ga ketemu, ya berarti emng ga ada jadi return aja
        prev->next = temp->next; // Sambungkan node prev dengan next dari node sekarang
        free(temp); // Hapus node sekarang (temp).
        list->_size--; // kurangin indexnya
    }
}

// Mendapatkan nilai node terdepan.
int slist_front(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        return list->_head->data; // Manfaatkan nilai data dari head. alias tinggal ambil data headnya aja
    }
    return 0;
}

// Mendapatkan nilai node paling belakang.
int slist_back(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        while (temp->next != NULL) 
            temp = temp->next;
        return temp->data; // Cukup dengan menelusuri hingga paling akhir dan return nilainya.
    }
    return 0;
}

// Mendapatkan nilai node pada posisi tertentu.
int slist_getAt(SinglyList *list, int index)
{
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;  // buat temp untuk cari datanya
        int _i = 0;
        while (temp->next != NULL && _i < index) { // ulang sampai, indexnya pas dan belum null
            temp = temp->next;
            _i++;
        }
        return temp->data; // kasih nilai datanya di index temp yg udh di cek melalaui while
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    // Buat objek SinglyList
    SinglyList myList;

    // PENTING! Jangan lupa diinisialisasi
    slist_init(&myList);

    // Gunakan operasi linked list
    slist_pushBack(&myList, 1);
    slist_pushBack(&myList, 2);
    slist_pushBack(&myList, 3);
    slist_pushBack(&myList, 4);

    slist_pushFront(&myList, 10);
    slist_pushFront(&myList, 9);
    slist_pushFront(&myList, 8);
    slist_pushFront(&myList, 7);

    slist_popBack(&myList);
    slist_popFront(&myList);

    // Isi List => [8, 9, 10, 1, 2, 3]

    slist_removeAt(&myList, 3);

    slist_insertAt(&myList, 1, 13);
    slist_pushBack(&myList, 1);
    slist_remove(&myList, 1);
    
    // Isi List => [8, 13, 9, 10, 2, 3]
    // printlist reversed
    while (myList._head != NULL) {
        printf("%d ", slist_back(&myList));
        slist_popBack(&myList);
    }
    puts("");
    return 0;
}