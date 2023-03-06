/**
 * Implementasi ADT Dynamic Array
 * Dokumentasi
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

// Struktur ADT DynamicArray
    // berisi array (variabel _arr), kemudian informasi ukuran (_size) dan kapasitas array (_capacity)

typedef struct dynamicarr_t {
    int *_arr;
    unsigned _size, _capacity;
} DynamicArray;

// Prototipe fungsi
    // darray = nama variabel untuk di fungsinya
void dArray_init(DynamicArray *darray);
bool dArray_isEmpty(DynamicArray *darray);
void dArray_pushBack(DynamicArray *darray, int value);
void dArray_popBack(DynamicArray *darray);
int  dArray_back(DynamicArray *darray);
int  dArray_front(DynamicArray *darray);
void dArray_setAt(DynamicArray *darray, unsigned index, int value);
int  dArray_getAt(DynamicArray *darray, unsigned index);

// Definisi fungsi

// initial/inisialisasi awal
void dArray_init(DynamicArray *darray)
{
    darray->_capacity = 2u;
    darray->_size = 0u;
    darray->_arr = (int*) malloc(sizeof(int) * 2);
}

// memeriksa apakah array kosong atau tidak
bool dArray_isEmpty(DynamicArray *darray) {
    return (darray->_size == 0); // ngecek kalau ukurannya 0, ya artinya kosong
}

// menambahkan data baru dari belakang.
void dArray_pushBack(DynamicArray *darray, int value) // int value = data angka yg ingin di masukan
{
    // Kalau ukuran + 1 > kapasitas, artinya udh ga muat (kapasitasnya kurang)
    if (darray->_size + 1 > darray->_capacity) {
        unsigned it;
        darray->_capacity *= 2; // kapasitasnya di kali 2 (sesuai dgn materi/definisi) 
        int *newArr = (int*) malloc(sizeof(int) * darray->_capacity); // membuat array baru newArr (temp)
        for (it=0; it < darray->_size; ++it)    // salin isi array lama ke baru newArr (temp)
            newArr[it] = darray->_arr[it];
        
        int *oldArray = darray->_arr;
        darray->_arr = newArr;  // masukin array baru yg temp ke Dynamic array / sejenis rename
        free(oldArray); // hapus array lama
    }
    darray->_arr[darray->_size++] = value;  // masukin angka yg mau di masukan ke darray, sesuai kebutuhan
}

// menghapus data terakhir/paling belakang.
void dArray_popBack(DynamicArray *darray) { 
    // Pastikan saat melakukan popBack, array tidak kosong, dicek dengan !isEmpty
    if (!dArray_isEmpty(darray)) darray->_size--; // kalau mau hapus, yaudah tinggal di --
    else return; // kalau kosong/ga ada isi, ya return mau ngapain lagi wkwkwk
}

// mendapatkan data terakhir/paling belakang.
int dArray_back(DynamicArray *darray) {
    if (!dArray_isEmpty(darray)) // kalau datanya tidak kosong
        return darray->_arr[darray->_size-1]; // kembalikan nilai arr terakhir (max size-1)
    else return 0; // kalau datanya kosong, ya mau ngapain coba jadinya return 0 deh wkwkw
}

// mendapatkan data terdepan/data pertama.
int dArray_front(DynamicArray *darray) {
    if (!dArray_isEmpty(darray)) // kalau datanya tidak kosong
        return darray->_arr[0]; // kembalikan nilai arr paling awal yaa yg indeks 0 lah
    else return 0; // kalau datanya kosong, ya mau ngapain coba jadinya return 0 deh wkwkw
}

// mengubah data pada indeks ke-i dengan nilai baru.
void dArray_setAt(
    DynamicArray *darray, unsigned index, int value)
{
    if (!dArray_isEmpty(darray)) {
        if (index >= darray->_size) // kalau index yg di input lebih besar dari sizenya (index arrnya),
            darray->_arr[darray->_size-1] = value; // masukin datanya ke arr paling terakhir 
        else
            darray->_arr[index] = value; // kalau engga, ya langsung timpa nilainya aja
    }
}

// mendapatkan data pada indeks ke-i dilakukan secara konstan O(  )).
int dArray_getAt(DynamicArray *darray, unsigned index)
{
    if (!dArray_isEmpty(darray)) {
        if (index >= darray->_size) // kalau inputan index lebih besar dari index asli,
            return darray->_arr[darray->_size-1]; // yaa ngambil datanya berarti data index terakhir
        else
            return darray->_arr[index]; // kalau engga, ya langsung akses/ambil data pada indexnya
    }
}

/* Gunakan ini untuk mempersingkat penulisan kode */

#define d_init dArray_init
#define d_isEmpty dArray_isEmpty
#define d_pushBack dArray_pushBack
#define d_popBack dArray_popBack
#define d_back dArray_back
#define d_front dArray_front
#define d_setAt dArray_setAt
#define d_getAt dArray_getAt

/* */

#include <stdio.h>

int main(int argc, char const *argv[])
{
    // Buat objek DynamicArray
    DynamicArray myArray;

    // PENTING! Jangan lupa diinisialisasi
    dArray_init(&myArray);

    // Operasi-operasi
    // myArray => [11, 14, 17, 23]
    dArray_pushBack(&myArray, 11);
    dArray_pushBack(&myArray, 14);
    dArray_pushBack(&myArray, 17);
    dArray_pushBack(&myArray, 23);

    // isi myArray => [11, 14, 17]
    dArray_popBack(&myArray);

    int i = 0;
    for (; i < myArray._size; ++i) {
        printf("%d ", dArray_getAt(&myArray, i));
    }

    printf("\n");
    while (!dArray_isEmpty(&myArray)) {
        printf("%d ", dArray_back(&myArray));
        dArray_popBack(&myArray);
    }
    printf("\n");
    
    return 0;
}