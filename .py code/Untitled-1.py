def is_safe(board, row, col, N):
    for i, j in [(row - 1, col - 2), (row - 2, col - 1), (row - 2, col + 1), (row - 1, col + 2),
                 (row + 1, col - 2), (row + 2, col - 1), (row + 2, col + 1), (row + 1, col + 2)]:
        if 0 <= i < N and 0 <= j < N and board[i][j] == 1:
            return False
    return True

def solve_knights_util(board, M, row, col, N, x_moves, y_moves, solutions):
    if M == 0:
        solutions.append([row[:] for row in board])
        return

    if row == N:
        return

    next_row, next_col = (row, col + 1) if col < N - 1 else (row + 1, 0)

    # Try placing a knight at the current position
    if is_safe(board, row, col, N):
        board[row][col] = 1
        solve_knights_util(board, M - 1, next_row, next_col, N, x_moves, y_moves, solutions)
        board[row][col] = 0

    # Try not placing a knight at the current position
    solve_knights_util(board, M, next_row, next_col, N, x_moves, y_moves, solutions)

def solve_knights(M, N):
    board = [[0 for _ in range(N)] for _ in range(N)]
    solutions = []

    # Knight's possible moves
    x_moves = [2, 1, -1, -2, -2, -1, 1, 2]
    y_moves = [1, 2, 2, 1, -1, -2, -2, -1]

    solve_knights_util(board, M, 0, 0, N, x_moves, y_moves, solutions)
    
    return solutions

M = int(input("Enter the number of knights (M): "))
N = int(input("Enter the size of the board (NxN): "))

solutions = solve_knights(M, N)

if not solutions:
    print("No solutions found.")
else:
    print("All solutions:")
    for idx, solution in enumerate(solutions):
        print(f"Solution {idx + 1}:")
        for row in solution:
            print(" ".join(map(str, row)))
        print()
