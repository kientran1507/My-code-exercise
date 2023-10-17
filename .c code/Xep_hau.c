#include <stdio.h>

#define MAX_N 10

int n = 5;
int x[MAX_N];

void printSolution() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i] == j) {
                printf("X ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int check(int v, int k) {
    for (int i = 1; i < k; i++) {
        if (x[i] == v || x[i] + i == v + k || x[i] - i == v - k) {
            return 0;
        }
    }
    return 1;
}

void Try(int k) {
    for (int v = 1; v <= n; v++) {
        if (check(v, k)) {
            x[k] = v;
            if (k == n) {
                printSolution();
            } else {
                Try(k + 1);
            }
        }
    }
}

int main() {
    Try(1);
    return 0;
}
