#include <stdio.h>
#include <math.h>

int countDivisors(long long n) {
    int count = 0;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            count += 2; // Count both divisors (i and n/i)
        }
    }
    return count;
}

int main() {
    long long triangleNumber = 0;
    int i = 1;

    while (1) {
        triangleNumber += i;

        if (countDivisors(triangleNumber) >= 500) {
            break;
        }

        i++;
    }

    printf("%lld\n", triangleNumber);
    return 0;
}
