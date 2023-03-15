#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n) {
	int i;
    // Bilangan 1 dan bilangan negatif bukan bilangan prima
    if (n <= 1) {
        return false;
    }
    for ( i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void print_primes(int start, int end) {
	int i,j;
    printf("Bilangan prima antara %d dan %d adalah: ", start, end);
    for ( i = start; i <= end; i++) {
        bool is_prime_number = true;
        if ( i == 0 || i == 1){
        is_prime_number = false;	
		}
        for ( j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                is_prime_number = false;
                break;
            }
        }
        if (is_prime_number) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int start, end;

    printf("Masukkan range bilangan: ");
    scanf("%d %d", &start, &end);

    print_primes(start, end);

    return 0;
}
