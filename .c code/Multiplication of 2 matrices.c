#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int A[101][101];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    int k2, m;
    scanf("%d %d", &k2, &m);

    int B[101][101];
    for (int i = 0; i < k2; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    int C[101][101] = {0}; // Initialize the result matrix with zeros

    // Perform matrix multiplication
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int x = 0; x < k; x++) {
                C[i][j] += A[i][x] * B[x][j];
            }
        }
    }

    // Print the result matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", C[i][j]);
            if (j < m - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
