/**
 * SOAL : 
 * Buatlah implementasi fungsi dArray_insertAt dan dArray_removeAt yang berguna untuk memasukkan elemen baru pada posisi yang diinginkan dan menghapus elemen pada posisi yang diinginkan. 
 * 
 * Prototipe fungsinya seperti berikut.
 * void dArray_insertAt(DynamicArray *darray, unsigned index, int value);
 * void dArray_removeAt(Dynamic *darray, unsigned index);
 * 
 * index merupakan posisi/indeks yang diinginkan.
 * value adalah nilai baru yang akan dimasukkan.
*/

#include <stdio.h>
#include <stdbool.h>

typedef struct dynamicarr_t {
    int *_arr;
    unsigned _size, _capacity; 
    // berisi array (variabel _arr), kemudian informasi ukuran (_size) dan kapasitas array (_capacity)
} DynamicArray;

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

// menghapus data terdepan/paling depan
// void dArray_popFront (DynamicArray *darray) {
//     if (!dArray_isEmpty(darray)) { 
//         DynamicArray *temp = 
//     }
// }

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

/**
 * Mulai
*/ 

void dArray_insertAt(DynamicArray *darray, unsigned index)
{
    if(!dArray_isEmpty(darray)) {
        // kasus apabila posisi melebihi batas
        if (index >= darray->_size) {
            
        }
        


    }
}

void dArray_removeAt(DynamicArray *darray, unsigned index)
{
    if (!dArray_isEmpty(darray)) {
        // kasus apabila posisinya melebihi batas / palingakhir
        if (index >= darray->_size) {
            dArray_popBack(darray); // tinggal pop back
            return;
        }
        // kasus apabila posisi di depan
        else if (index == 0 || index < 0) {
            
        }



    }
}

int main () {
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
}