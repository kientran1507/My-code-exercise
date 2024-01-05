#include <stdio.h>
#include <stdlib.h>

#define MAX 100001

int n;
int b;
int arr[MAX];

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void input() {
    scanf("%d %d", &n, &b);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), compare);
}

int findPairs() {
    int count = 0;
    int left = 0;
    int right = n - 1;

    while (left < right) {
        if (arr[left] + arr[right] == b) {
            count++;
            left++;
            right--;
        } else if (arr[left] + arr[right] < b) {
            left++;
        } else {
            right--;
        }
    }

    return count;
}

int main() {
    input();

    int count = findPairs();

    printf("%d\n", count);

    return 0;
}
