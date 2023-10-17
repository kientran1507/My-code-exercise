#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(int n, int *primes) {
    if (n <= 1) {
        return false;
    }
    if (primes[n] != -1) {
        return primes[n]; // Sử dụng memoization
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            primes[n] = false;
            return false;
        }
    }
    primes[n] = true;
    return true;
}

void listPrimes(int n) {
    int primes[n + 1];
    for (int i = 0; i <= n; i++) {
        primes[i] = -1; // Khởi tạo mảng memoization
    }

    for (int i = 2; i <= n; i++) {
        if (isPrime(i, primes)) {
            printf("%d ", i);
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
