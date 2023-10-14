# -----------------------------------------------------------------------------------------------------------------
# -----------------------------------------------------------------------------------------------------------------
# -----------------------------------------SIMPLE TIC TAC TOE GAME-------------------------------------------------
# -----------------------------------------------------------------------------------------------------------------
# -----------------------------------------------------------------------------------------------------------------



# -----------------------------------------------------------------------------------------------------------------
# -------Print out a 3 by 3 board as a list, where each index 1-9 corresponds with a number on a number pad.-------
# -----------------------------------------------------------------------------------------------------------------
from IPython.display import clear_output

def display_board(board):
    print(f'{board[1]}','|',f'{board[2]}','|',f'{board[3]}')
    print('-','-','-','-','-',)
    print(f'{board[4]}','|',f'{board[5]}','|',f'{board[6]}')
    print('-','-','-','-','-',)
    print(f'{board[7]}','|',f'{board[8]}','|',f'{board[9]}')
# -----------------------------------------------------------------------------------------------------------------
# -----------------------------------------------------------------------------------------------------------------



# -----------------------------------------------------------------------------------------------------------------
# -------------------------Take in a player input and assign their marker as 'X' or 'O'.---------------------------
# -----------------------------------------------------------------------------------------------------------------
def player_input():
    
    # This original choice value can be anything that isn't an integer
    player_choice = 'wrong'

    # While the choice is not X or O, keep asking for input
    while player_choice not in ['X','O']:
        
        # We shouldn't convert here, otherwise we get an error on a wrong input
        player_choice = input('Player 1 choose X or O: ')
        
        if player_choice not in ['X','O']:
            
            # THIS CLEARS THE CURRENT OUTPUT BELOW THE CELL
            clear_output()

            print('Please choose again')
    return player_choice
# -----------------------------------------------------------------------------------------------------------------
# -----------------------------------------------------------------------------------------------------------------



# -----------------------------------------------------------------------------------------------------------------
# ----------Takes in the board list object, a marker, and a desired position and assigns it to the board.----------
# -----------------------------------------------------------------------------------------------------------------
def place_marker(board, marker, position):
    board[position]=marker
# -----------------------------------------------------------------------------------------------------------------
# -----------------------------------------------------------------------------------------------------------------



# -----------------------------------------------------------------------------------------------------------------
#---------------Takes in a board and a mark (X or O) and then checks to see if that mark has won.------------------
# -----------------------------------------------------------------------------------------------------------------
def win_check(board, mark):
    # This is every possible way to win
    if board[1]==board[2]==board[3]==mark:
        return True
    elif board[1]==board[5]==board[9]==mark:
        return True
    elif board[1]==board[4]==board[7]==mark:
        return True
    elif board[2]==board[5]==board[8]==mark:
        return True
    elif board[3]==board[6]==board[9]==mark:
        return True
    elif board[4]==board[5]==board[6]==mark:
        return True
    elif board[7]==board[8]==board[9]==mark:
        return True
    elif board[3]==board[5]==board[7]==mark:
        return True
    else:
        return False
# -----------------------------------------------------------------------------------------------------------------
# -----------------------------------------------------------------------------------------------------------------



# -----------------------------------------------------------------------------------------------------------------
# -------------------------------------Randomly decide which player goes first-------------------------------------
# -----------------------------------------------------------------------------------------------------------------
import random
def choose_first():
    print(f'You are player {random.randint(1,2)}!')
# -----------------------------------------------------------------------------------------------------------------
# -----------------------------------------------------------------------------------------------------------------



# -----------------------------------------------------------------------------------------------------------------
# ---------------Returns a boolean indicating whether a space on the board is freely available.--------------------
# -----------------------------------------------------------------------------------------------------------------
def space_check(board, position):
    return board[position]==' '
# -----------------------------------------------------------------------------------------------------------------
# -----------------------------------------------------------------------------------------------------------------



# -----------------------------------------------------------------------------------------------------------------
# ----------Checks if the board is full and returns a boolean value. True if full, False otherwise.----------------
# -----------------------------------------------------------------------------------------------------------------
def full_board_check(board):
    full = 0
    for i in range(1,10):
        if board[i] != ' ':
            full +=1
    if full == 9:
        return True
    else: 
        return False
# -----------------------------------------------------------------------------------------------------------------
# -----------------------------------------------------------------------------------------------------------------



# -----------------------------------------------------------------------------------------------------------------
# ---------------------------Asks for a player's next position (as a number 1-9)-----------------------------------
# ---------------------------Then uses the function to check if it's a free position-------------------------------
# ---------------------------If it is, then return the position for later use--------------------------------------
# -----------------------------------------------------------------------------------------------------------------
def player_choice(board):

    # This original choice value can be anything that isn't an integer
    choice = 'wrong'

    # This is used to check if choice is within range
    within_range = False
    
    # While the choice is not a digit or not in range, keep asking for input
    while choice.isdigit() == False or within_range == False:

        # We shouldn't convert here, otherwise we get an error on a wrong input
        choice = input("Choose the position you want (1-9): ")

        if choice.isdigit() == False:

            # THIS CLEARS THE CURRENT OUTPUT BELOW THE CELL
            clear_output()

            print("Sorry, but you did not chose a digit")

        if choice.isdigit() == True:

            # This check range of input
            if int(choice) in range(1,10):

                if space_check(board,int(choice)) == False:
                   
                    # THIS CLEARS THE CURRENT OUTPUT BELOW THE CELL
                    clear_output()

                    print("Sorry, but your position is not available")
                else: 
                    within_range = True

            
            if within_range == False:
                
                # THIS CLEARS THE CURRENT OUTPUT BELOW THE CELL
                clear_output()

                print("Sorry, but you did not chose a value in the correct range (1-9)")


    return int(choice)
# -----------------------------------------------------------------------------------------------------------------
# -----------------------------------------------------------------------------------------------------------------



# -----------------------------------------------------------------------------------------------------------------
# -------Asks the player if they want to play again and returns a boolean True if they do want to play again-------
# -----------------------------------------------------------------------------------------------------------------
def replay():
    # This original choice value can be anything that isn't Y or N
    choice = 'wrong'

    # While the choice is not a digit, keep asking for input.
    while choice not in ['Y','N']:

        # We shouldn't convert here, otherwise we get an error on a wrong input
        choice = input('Do you want to play again?(Y/N): ')

        if choice not in ['Y','N']:

            # THIS CLEARS THE CURRENT OUTPUT BELOW THE CELL
            clear_output()

            print('Sorry, I do not understand. Please choose Y or N')

        if choice=='Y':
            # Game is still on
            return True
        else:
            # Game is over
            return False
# -----------------------------------------------------------------------------------------------------------------
# -----------------------------------------------------------------------------------------------------------------



# -----------------------------------------------------------------------------------------------------------------
# --------------------------------------------------Run the game---------------------------------------------------
# -----------------------------------------------------------------------------------------------------------------
print('Welcome to Tic Tac Toe!')
# Start the game
play = True

while play:
    
    # Initial board
    board=['#',' ',' ',' ',' ',' ',' ',' ',' ',' ']

    # Display the initial board
    display_board(board)

    # Decide who gets to choose first
    choose_first()

    # A is player 1 input and B is player 2 input 
    A = player_input()
    C = ['X','O']
    C.remove(A)
    B = C[0]
    
    # Variable to keep game playing
    game_on = True 

    while game_on:

    #Player 1 Turn

        # Clear any historical output
        print('It\'s player 1 turn')
        
        # Display the board for player 1
        display_board(board)

        # Mark the player's choice on the board
        place_marker(board,A,player_choice(board))

        # Check if player have won or not
        if win_check(board,A):
            print('You win!')

            # Game over
            game_on = False
            break
        # Check if the board is full or not
        if full_board_check(board):
            print('It\'s a draw!')

            # Game over
            game_on = False
            break

    # Player2's turn

        # Clear any historical output
        print('It\'s player 2 turn')

        # Display the board for player 2
        display_board(board)

        # Mark the player's choice on the board
        place_marker(board,B,player_choice(board))

        # Check if player have won or not
        if win_check(board,B):
            print('You win!')

            # Game over
            game_on = False
            break

    if not replay():
        # Clear any historical output and end the game
        clear_output()
        break
# -----------------------------------------------------------------------------------------------------------------
# -----------------------------------------------------THE END-----------------------------------------------------
# -----------------------------------------------------------------------------------------------------------------