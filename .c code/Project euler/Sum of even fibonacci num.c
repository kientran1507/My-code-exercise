#include <stdio.h>

int n = 4000000;
int a[100]; // Specify the array size as needed

int main() {
    int sum = 2; //a[1] = 2

    a[0] = 1; // Initialize the first two Fibonacci numbers
    a[1] = 2;

    for (int i = 2; a[i - 1] <= n; i++) {
        a[i] = a[i - 1] + a[i - 2];
        if (a[i] % 2 == 0 && a[i] <= n) {
            sum += a[i];
        }
    }

    printf("%d", sum);

    return 0;
}
