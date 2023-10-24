#include <stdio.h>
#include <stdbool.h>

#define N 2000000

bool isComposite[N]; // An array to mark non-prime numbers as composite.

int main() {
    long long sum = 0; // Initialize the sum as a long long to accommodate large values.

    // Initialize the isComposite array.
    for (int i = 2; i < N; i++) {
        isComposite[i] = false;
    }

    // Perform the Sieve of Eratosthenes algorithm to find primes and mark composites.
    for (int i = 2; i < N; i++) {
        if (!isComposite[i]) {
            // i is a prime number, so add it to the sum.
            sum += i;
            // Mark all multiples of i as composite.
            for (int j = i * 2; j < N; j += i) {
                isComposite[j] = true;
            }
        }
    }

    printf("The sum of all prime numbers below two million is %lld\n", sum);

    return 0;
}
