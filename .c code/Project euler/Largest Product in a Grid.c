#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int grid[20][20];
    printf("Enter the 20x20 grid values (one row at a time):\n");
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    int maxProduct = 0;
    for (int row = 0; row < 20; row++) {
        for (int col = 0; col < 20; col++) {
            // Check right
            if (col + 3 < 20) {
                maxProduct = max(maxProduct, grid[row][col] * grid[row][col + 1] * grid[row][col + 2] * grid[row][col + 3]);
            }
            // Check down
            if (row + 3 < 20) {
                maxProduct = max(maxProduct, grid[row][col] * grid[row + 1][col] * grid[row + 2][col] * grid[row + 3][col]);
            }
            // Check diagonally right-down
            if (row + 3 < 20 && col + 3 < 20) {
                maxProduct = max(maxProduct, grid[row][col] * grid[row + 1][col + 1] * grid[row + 2][col + 2] * grid[row + 3][col + 3]);
            }
            // Check diagonally left-down
            if (row + 3 < 20 && col - 3 >= 0) {
                maxProduct = max(maxProduct, grid[row][col] * grid[row + 1][col - 1] * grid[row + 2][col - 2] * grid[row + 3][col - 3]);
            }
        }
    }

    printf("The greatest product of four adjacent numbers in the grid is: %d\n", maxProduct);

    return 0;
}
