#include <stdio.h>

#define MAX_N 10

int n = 5;
int k = 3;
int x[MAX_N];

void printSolution() {
    for (int i = 1; i <= k; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
}

void Try(int i) {
    for (int v = x[i-1] + 1 ; v <= n - k + i; v++) {
        x[i] = v;
        if (i == k) printSolution();
        else Try(i+1);
    }
}

int main() {
    x[0] = 0;
    Try(1);
    return 0;
}
