#include <stdio.h>

// Function to find the median of two sorted arrays without sorting
double findMedian(int arr1[], int n1, int arr2[], int n2) {
    int mergedSize = n1 + n2;
    int merged[mergedSize];
    int i = 0, j = 0, k = 0;

    // Merge the two sorted arrays
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }

    while (i < n1) {
        merged[k++] = arr1[i++];
    }

    while (j < n2) {
        merged[k++] = arr2[j++];
    }

    // Find the median
    if (mergedSize % 2 == 0) {
        // If the merged size is even, return the average of the middle elements
        int mid1 = merged[mergedSize / 2 - 1];
        int mid2 = merged[mergedSize / 2];
        return (double)(mid1 + mid2) / 2.0;
    } else {
        // If the merged size is odd, return the middle element
        return (double)merged[mergedSize / 2];
    }
}

int main() {
    int n1, n2;

    scanf("%d %d", &n1, &n2);

    int arr1[n1];
    for (int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    int arr2[n2];
    for (int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    double median = findMedian(arr1, n1, arr2, n2);

    printf("%lf\n", median);

    return 0;
}
