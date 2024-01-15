#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

int partition(char **arr, int low, int high) {
    char *pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (strcmp(arr[j], pivot) <= 0) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort(char **arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    int n;

    scanf("%d", &n);

    getchar();

    char **lines = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        lines[i] = (char *)malloc(100 * sizeof(char));

        fgets(lines[i], 100, stdin);

        lines[i][strcspn(lines[i], "\n")] = '\0';
    }

    quicksort(lines, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%s\n", lines[i]);
        free(lines[i]);
    }

    free(lines);

    return 0;
}
