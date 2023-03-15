#include <stdio.h>
#include <stdbool.h>

int fungsiFactorial(int _angka) {
    int i, hasil = 1;
    for (i = 1; i <= _angka; i++) {
        hasil *= i;
    }
    return hasil;
}

int faktorial () {
    int angka;
    printf("Masukkan bilangan bulat positif: ");
    scanf("%d", &angka);
    int hasil = fungsiFactorial(angka);
    printf("hasil dari %d faktorial (%d!) adalah %d\n", angka, angka, hasil);
    return 0;
}

float fungsiPangkat(float _basis, int _pangkat) {
    float hasil = 1;
    if (_pangkat >= 0) {
        for (int i = 0; i < _pangkat; i++) {
            hasil *= _basis;
        }
    } else {
        for (int i = 0; i > _pangkat; i--) {
            hasil /= _basis;
        }
    }
    return hasil;
}

int pangkat() {
    float basis;
    int pangkat;
    printf("Masukkan basis: ");
    scanf("%f", &basis);
    printf("Masukkan pangkat: ");
    scanf("%d", &pangkat);
    float hasil = fungsiPangkat(basis, pangkat);
    printf("%.2f^%d = %.2f\n", basis, pangkat, hasil);
    printf("Hasil dari %.2f pangkat %d adalah %.2f", basis, pangkat, hasil);
    return 0;
}

bool isPrime(int angka) {
    if (angka <= 1) return false;
    for (int i = 2; i < angka; i++) {
        if (angka % i == 0) {
            return false;
        }
    }
    return true;
}

void printPrimesInRange(int start, int end) {
    printf("Bilangan prima dalam rentang %d hingga %d adalah: ", start, end);
    for (int i = start; i <= end; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int prima() {
    int awal, akhir;
    printf("Masukkan rentang bilangan yang ingin diperiksa:\n");
    printf("Mulai dari: ");
    scanf("%d", &awal);
    printf("Sampai dengan: ");
    scanf("%d", &akhir);
    printPrimesInRange(awal, akhir);
    return 0;
}

int main () {
    printf("Silahkan milih menu program\n");
    printf("1. faktorial\n");
    printf("2. pangkat\n");
    printf("3. prima\n");

    int menu;
    printf("Ketik menu yang diinginkan ");
    scanf("%d", &menu);

    if (menu == 1) {
        int menu1 = faktorial();
    } else if (menu == 2) {
        int menu2 = pangkat();
    } else if (menu == 3) {
        int menu3 = prima();
    } else printf("input menu anda salah");

    return 0;
}