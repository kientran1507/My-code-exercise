#include <stdio.h>
#include <stdbool.h>

int x[9][9]; // Initialize the sudoku grid

bool check(int v, int r, int c) {
    for (int i = 0; i <= r - 1; i++) {
        if (x[i][c] == v) return false;
    }
    for (int j = 0; j <= c - 1; j++) {
        if (x[r][j] == v) return false;
    }
    int I = r / 3;
    int J = c / 3;
    int i = r - 3 * I;
    int j = c - 3 * J;
    for (int i1 = 0; i1 <= i - 1; i1++) {
        for (int j1 = 0; j1 <= 2; j1++) {
            if (x[3 * I + i1][3 * J + j1] == v) return false;
        }
    }
    for (int j1 = 0; j1 <= j - 1; j1++) {
        if (x[3 * I + i][3 * J + j1] == v) return false;
    }
    return true;
}

void printSolution() {
    // Print the Sudoku grid (x[][])
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", x[i][j]);
        }
        printf("\n");
    }
}

bool TRY(int r, int c) {
    if (r == 9) {
        r = 0;
        if (++c == 9) {
            return true; // Solved the puzzle
        }
    }

    if (x[r][c] != 0) {
        return TRY(r + 1, c);
    }

    for (int v = 1; v <= 9; v++) {
        if (check(v, r, c)) {
            x[r][c] = v;
            if (TRY(r + 1, c)) {
                return true; // Solved the puzzle
            }
            x[r][c] = 0; // Backtrack
        }
    }
    return false;
}

int main() {
    // Initialize the Sudoku grid (x[][])
    // Assign your Sudoku puzzle here
    // 0 represents an empty cell
    int sudoku[9][9] = {
        {1, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 5, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    
    // Copy the puzzle to x[][]
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            x[i][j] = sudoku[i][j];
        }
    }

    // Start solving the puzzle
    if (TRY(0, 0)) {
        printSolution();
    } else {
        printf("No solution found.\n");
    }

    return 0;
}
