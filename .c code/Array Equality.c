#include <stdio.h>

int main() {
    int T; // Number of tests
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int n, m;
        scanf("%d %d", &n, &m);

        int a[1000], b[1000];

        for (int j = 0; j < n; j++) {
            scanf("%d", &a[j]);
        }

        for (int k = 0; k < m; k++) {
            scanf("%d", &b[k]);
        }

        if (n != m) {
            printf("0\n"); // If the sizes of the arrays are different, they can't be equal
        } else {
            int equal = 1; // Initialize with 1, assuming they are equal

            for (int l = 0; l < m; l++) {
                if (a[l] != b[l]) {
                    equal = 0; // If any element is not equal, set equal to 0
                    break;
                }
            }

            if (equal) {
                printf("1\n");
            } else {
                printf("0\n");
            }
        }
    }

    return 0;
}
