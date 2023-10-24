#include <stdio.h>
#include <stdbool.h>

#define N 4  // Kích thước bàn cờ NxN
#define M 3  // Số hậu cần xếp

int board[N][N];

void print_solution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool is_safe(int row, int col) {
    // Kiểm tra cột cùng hàng
    for (int i = 0; i < col; i++) {
        if (board[row][i]) {
            return false;
        }
    }

    // Kiểm tra đường chéo trên bên trái
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    // Kiểm tra đường chéo dưới bên trái
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

bool solve_n_queens(int col) {
    if (col >= M) {
        print_solution();
        return true;
    }

    bool result = false;
    for (int i = 0; i < N; i++) {
        if (is_safe(i, col)) {
            board[i][col] = 1;
            result = solve_n_queens(col + 1) || result;
            board[i][col] = 0;  // Quay lui
        }
    }
    return result;
}

int main() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }

    if (!solve_n_queens(0)) {
        printf("Không có giải pháp\n");
    }

    return 0;
}
