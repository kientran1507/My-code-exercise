def is_safe(board, row, col, N):
    for i, j in [(row - 1, col - 2), (row - 2, col - 1), (row - 2, col + 1), (row - 1, col + 2),
                 (row + 1, col - 2), (row + 2, col - 1), (row + 2, col + 1), (row + 1, col + 2)]:
        if 0 <= i < N and 0 <= j < N and board[i][j] == 1:
            return False
    return True

def solve_knights_util(board, M, row, col, N, x_moves, y_moves, solutions, output_file):
    if M == 0:
        solutions.append([row[:] for row in board])
        if output_file:
            output_file.write("Solution:\n")
            for row in board:
                output_file.write(" ".join(map(str, row)) + "\n")
            output_file.write("\n")
        return

    if row == N:
        return

    next_row, next_col = (row, col + 1) if col < N - 1 else (row + 1, 0)

    # Try placing a knight at the current position
    if is_safe(board, row, col, N):
        board[row][col] = 1
        solve_knights_util(board, M - 1, next_row, next_col, N, x_moves, y_moves, solutions, output_file)
        board[row][col] = 0

    # Try not placing a knight at the current position
    solve_knights_util(board, M, next_row, next_col, N, x_moves, y_moves, solutions, output_file)

def solve_knights(M, N, output_file=None):
    board = [[0 for _ in range(N)] for _ in range(N)]
    solutions = []

    # Knight's possible moves
    x_moves = [2, 1, -1, -2, -2, -1, 1, 2]
    y_moves = [1, 2, 2, 1, -1, -2, -2, -1]

    solve_knights_util(board, M, 0, 0, N, x_moves, y_moves, solutions, output_file)
    
    return solutions

M = int(input("Enter the number of knights (M): "))
N = int(input("Enter the size of the board (NxN): "))

output_file_name = input("Enter the output file name (leave blank to print to console): ")

output_file = None
if output_file_name:
    output_file = open(output_file_name, "w")

solutions = solve_knights(M, N, output_file)

if not solutions:
    print("No solutions found.")
else:
    print("All solutions found.")
    if output_file:
        print(f"Solutions written to {output_file_name}")
        output_file.close()
    else:
        for idx, solution in enumerate(solutions):
            print(f"Solution {idx + 1}:")
            for row in solution:
                print(" ".join(map(str, row)))
