// Mengimpor library yang diperlukan
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Mendefinisikan struct Pasien
struct Pasien {
char nama[100];
int umur;
int skala;
};

// Fungsi utama program
int main() {
    // Mendeklarasikan variabel N dan M
    int N, M;
    // Meminta input N dan M dari user
    scanf("%d %d", &N, &M);

    // Membuat array pasienList dengan ukuran N
    struct Pasien pasienList[N];
    // Meminta input nama, umur, dan skala dari setiap pasien dan menyimpannya dalam pasienList
    int i;
    for (i = 0; i < N; i++) {
        scanf("%s %d %d", pasienList[i].nama, &pasienList[i].umur, &pasienList[i].skala);
    }

    // Mengurutkan pasienList berdasarkan skala dan umur menggunakan bubble sort
    int j;
    int k;
    for (j = 0; j < N; j++) {
        for (k = 0; k < N - j - 1; j++) {
            if (pasienList[k].skala > pasienList[k + 1].skala) {
                struct Pasien temp = pasienList[k];
                pasienList[k] = pasienList[k + 1];
                pasienList[k + 1] = temp;
            } else if (pasienList[k].skala == pasienList[k + 1].skala && pasienList[k].umur < pasienList[k + 1].umur) {
                struct Pasien temp = pasienList[k];
                pasienList[k] = pasienList[k + 1];
                pasienList[k + 1] = temp;
            }
        }
    }

    // Mencari pasangan pasien dengan skala dan umur yang sama
    int found = 0;
    int l;
    int m;
    for (l = 0; l < N; l++) {
        for (m = l + 1; m < N; m++) {
            if (pasienList[l].skala == pasienList[m].skala && pasienList[l].umur == pasienList[m].umur) {
                found = 1;
                printf("Kamu jodoh ya %s - %d && %s - %d\n", pasienList[l].nama, pasienList[l].skala, pasienList[m].nama, pasienList[m].skala);
                break;
            }
        }
        if (found) break;
    }

    // Jika tidak ditemukan pasangan dengan skala dan umur yang sama
    if (N >= 3 && !found) {
        // Menampilkan pasien selanjutnya dengan skala tertinggi ketiga
        printf("Pasien selanjutnya %s - %d\n", pasienList[4].nama, pasienList[4].skala);
    } else if (N < 3 && !found) {
        // Jika jumlah pasien kurang dari tiga, menampilkan pesan "Full senyum deck"
        printf("Full senyum deck\n");
    }

    // Menutup program
    return 0;
}
