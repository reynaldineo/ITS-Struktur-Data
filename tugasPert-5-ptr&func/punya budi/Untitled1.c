/*#include <stdio.h>
#define ll long long

int main() {
    int n, i;
    ll faktorial = 1;
    
    printf("Masukkan bilangan bulat positif: ");
    scanf("%d", &n);
    
    // cek apakah bilangan n valid
    if (n < 0) {
        printf("Error: Bilangan negatif tidak memiliki faktorial.\n");
        return 1;
    }
    
    for (i = 1; i <= n; i++) {
        faktorial = faktorial * i;
    }
    
    printf("%d! = %lld\n", n, faktorial);
    
    return 0;
}
*/
#include <stdio.h>

int faktorial(int n) {
    int i, hasil = 1;
    for(i=1; i<=n; i++) {
        hasil = hasil * i;
    }
    return hasil;
}

int main() {
    int n;
    printf("Masukkan bilangan bulat positif: ");
    scanf("%d", &n);
    printf("Faktorial dari %d adalah %d\n", n, faktorial(n));
    return 0;
}


