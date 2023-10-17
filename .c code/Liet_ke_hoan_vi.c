#include <stdio.h>

#define MAX_N 10

int n;
int m[MAX_N];
int x[MAX_N];

void printSolution() {
    for (int i = 1; i <= n; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
}

void Try(int i) {
    for (int v = 1; v <= n; v++) {
        if (!m[v]) {
            x[i] = v;
            m[v] = 1;
            if (i == n) {
                printSolution();
            } else {
                Try(i + 1);
            }
            m[v] = 0;
        }
    }
}

int main() {
    n = 5; 
    for (int v = 1; v <= n; v++) {
        m[v] = 0;
    }
    Try(1);
    return 0;
}
