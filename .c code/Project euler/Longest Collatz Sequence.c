#include <stdio.h>

long long int maxChain = 0;

long long int max(long long int a, long long int b) {
    return (a > b) ? a : b;
}

int collatz_length(long long int n) {
    long long int count = 0;
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
        count += 1;
    }
    return count;
}

int main() {
    long long int maxNumber = 0;
    for (long long int n = 1; n <= 1000000; n++) {
        long long int chainLength = collatz_length(n);
        if (chainLength > maxChain) {
            maxChain = chainLength;
            maxNumber = n;
        }
    }

    printf("Number with the longest Collatz sequence: %lld (Chain length: %lld)\n", maxNumber, maxChain);
    return 0;
}
