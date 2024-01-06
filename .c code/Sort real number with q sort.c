#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    double x = *(const double *)a;
    double y = *(const double *)b;
    return (y > x) - (y < x);
}

int main() {
    int n, i;

    scanf("%d", &n);

    double *numbers = malloc(n * sizeof(double));
    if (!numbers) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        scanf("%lf", &numbers[i]);
    }

    qsort(numbers, n, sizeof(double), compare);

    for (i = 0; i < n; i++) {
        printf("%.2f\n", numbers[i]);
    }

    free(numbers);

    return 0;
}
