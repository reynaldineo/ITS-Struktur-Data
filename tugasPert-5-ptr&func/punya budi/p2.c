#include <stdio.h>

double pangkat(double x, int y) {
    double result = 1.0;
    int i = 1;
    while(i <= y) {
        result *= x;
        i++;
    }
    return result;
}

int main() {
    double x, result;
    int y;

    printf("Masukkan nilai x: ");
    scanf("%lf", &x);

    printf("Masukkan nilai y: ");
    scanf("%d", &y);

    result = pangkat(x, y);

    printf("%.2lf pangkat %d adalah %.2lf\n", x, y, result);

    return 0;
}
