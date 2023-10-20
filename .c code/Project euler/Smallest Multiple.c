#include <stdio.h>

// Function to calculate the greatest common divisor (GCD) of two numbers
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to calculate the least common multiple (LCM) of two numbers
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int result = 1;

    // Calculate the LCM iteratively for numbers 1 to 20
    for (int i = 1; i <= 20; i++) {
        result = lcm(result, i);
        printf("%d\n", result);
    }

    printf("The smallest positive number evenly divisible by all numbers from 1 to 20 is: %d\n", result);

    return 0;
}
