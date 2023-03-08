// buatlah function untuk menghitung x pangkat y
#include <stdio.h>

int main () {
  int angka, pangkat, hasil;
  scanf("%d %d", &angka, &pangkat);
  hasil = angka;

  for (int i = 0; i < pangkat-1; i++) {
    hasil = hasil * angka;
  }
  printf("%d", hasil);

  return 0;
}