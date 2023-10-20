#include <stdio.h>
#include <math.h>
#include <stdbool.h>

long long int n = 600851475143;
long long int largestPrimeFactor = 0;

bool isPrime(long long int num) {
    if (num <= 1) {
        return false;
    }
    for (long long int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    for (long long int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            if (isPrime(i)) {
                largestPrimeFactor = i;
            }
        }
    }

    if (n > 1 && isPrime(n)) {
        largestPrimeFactor = n;
    }

    printf("%lld\n", largestPrimeFactor);

    return 0;
}
