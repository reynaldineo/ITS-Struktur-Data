#include <stdio.h>

int factorial(int _angka) {
    int i, hasil = 1;
    for (i = 1; i <= _angka; i++) {
        hasil *= i;
    }
    return hasil;
}

int main() {
    int angka;
    printf("Masukkan bilangan bulat positif: ");
    scanf("%d", &angka);

    int hasil = factorial(angka);

    printf("hasil dari %d faktorial (%d!) adalah %d\n", angka, angka, hasil);
    return 0;
}
