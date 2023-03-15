#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    
    int i;
    for (i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    
    return true;
}

void printPrimesInRange(int start, int end) {
    int i;
    printf("Bilangan prima dalam rentang %d hingga %d adalah: ", start, end);
    for (i = start; i <= end; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int awal, akhir;

    printf("Masukkan rentang bilangan yang ingin diperiksa:\n");
    printf("Mulai dari: ");
    scanf("%d", &awal);
    printf("Sampai dengan: ");
    scanf("%d", &akhir);
    
    printPrimesInRange(awal, akhir);
    
    return 0;
}
