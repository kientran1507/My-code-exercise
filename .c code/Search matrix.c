#include <stdio.h>
#include <stdlib.h>

// Function to perform binary search in a row of the matrix
int binarySearch(int row[], int target, int start, int end) {
    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (row[mid] == target) {
            return mid; // Return the index where target is found
        } else if (row[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return -1; // Target not found in this row
}

// Function to search for a number in the matrix
int searchMatrix(int** matrix, int rows, int cols, int target, int* row, int* col) {
    for (int i = 0; i < rows; i++) {
        if (target >= matrix[i][0] && target <= matrix[i][cols - 1]) {
            // The target is possibly in this row
            int index = binarySearch(matrix[i], target, 0, cols - 1);
            if (index != -1) {
                *row = i;
                *col = index;
                return 1; // Found the target in the matrix
            }
        }
    }

    return 0; // Target not found in the matrix
}

int main() {
    int rows, cols;

    scanf("%d %d", &rows, &cols);

    // Dynamically allocate memory for the matrix
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }

    // Input matrix elements
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int target, row, col;

    scanf("%d", &target);

    if (searchMatrix(matrix, rows, cols, target, &row, &col)) {
        printf("Number %d is in the matrix at location (%d, %d).\n", target, row, col);
    } else {
        printf("Number %d is not in the matrix.\n", target);
    }

    // Free dynamically allocated memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
