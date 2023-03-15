#include <stdio.h>

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

int main() {
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
