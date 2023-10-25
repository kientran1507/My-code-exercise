#include <stdio.h>
#include <math.h>
#define MAX_N 10

int n;
int m[MAX_N];
int x[MAX_N];

int is_valid(int arr[], int n) {
    // Kiểm tra xem dãy số có thỏa mãn điều kiện không
    for (int i = 1; i < n; i++) {
        if (abs(arr[i] - arr[i + 1]) % 2 == 0) {
            return 0;
        }
    }
    return 1;
}

void printSolution() {
    // In ra đáp án
    for (int i = 1; i <= n; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
}

void Try(int i) {
    // Quay lui
    for (int v = 1; v <= n; v++) {
        if (!m[v]) {
            x[i] = v;
            m[v] = 1;
            if (i == n && is_valid(x, n)) {
                // Kiểm tra điều kiện 
                printSolution();
                    // In đáp án
            } else {
                Try(i + 1);
            }
            m[v] = 0;
        }
    }
}

int main() {
    n = 6; 
    for (int v = 1; v <= n; v++) {
        m[v] = 0;
    }
    Try(1);
    return 0;
}
