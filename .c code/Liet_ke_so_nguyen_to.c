#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(int n, int divisor) {
    if (n <= 1) {
        return false;
    }
    if (divisor == 1) {
        return true;
    }
    if (n % divisor == 0) {
        return false;
    }
    return isPrime(n, divisor - 1);
}

void listPrimes(int n) {
    if (n >= 2) {
        listPrimes(n - 1);
        if (isPrime(n, sqrt(n))) {
            printf("%d ", n);
        }
    }
}

int main() {
    int limit = 100; // Thay đổi giới hạn tùy ý
    printf("Cac so nguyen to nho hon hoac bang %d la: \n", limit);
    listPrimes(limit);
    printf("\n");

    return 0;
}
