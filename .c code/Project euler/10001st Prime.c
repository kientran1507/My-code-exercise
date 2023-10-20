#include <stdio.h>
#include <stdbool.h>

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
    int count = 0;
    long long int i = 2;

    while (count < 10001) {
        if (isPrime(i)) {
            count++;
            if (count == 10001) {
                printf("%lld", i);
                break; // Exit the loop once the 10,001st prime is found
            }
        }
        i++;
    }

    return 0;
}
