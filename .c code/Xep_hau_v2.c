#include <stdio.h>

#define MAX_N 1000

int n, row, col;
int x[MAX_N];
int solution_found = 0;

void input(){
    scanf("%d %d %d", &n, &row, &col);
}

void printSolution() {
    if (x[col] == row) {
        for (int i = 1; i <= n; i++) {
            printf("%d ", x[i]);
        }
        printf("\n");
        solution_found = 1;
    }
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
    input();
    Try(1);
    
    if (!solution_found) {
        printf("None\n");
    }
    
    return 0;
}
