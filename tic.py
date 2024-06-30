import os
import time

def clear_screen():
    os.system("cls" if os.name == "nt" else "clear")

def display_board(board):
    clear_screen()
    print("\n")
    for row in board:
        print(" ".join(row))
    print("\n")

def get_player_move():
    try:
        move = int(input("Choose a position (1-9): ")) - 1
        return move
    except ValueError:
        print("Invalid input. Please enter a number between 1 and 9.")
        return get_player_move()

def make_move(board, player, move):
    row, col = divmod(move, 3)
    if board[row][col] == " ":
        board[row][col] = player
        return True
    else:
        print("Position already taken. Try again.")
        return False

def check_winner(board, player):
    for i in range(3):
        if all(board[i][j] == player for j in range(3)) or all(board[j][i] == player for j in range(3)):
            return True
    return board[0][0] == board[1][1] == board[2][2] == player or board[0][2] == board[1][1] == board[2][0] == player

def play_tic_tac_toe():
    board = [[" " for _ in range(3)] for _ in range(3)]
    current_player = "X"

    while True:
        display_board(board)
        print(f"Player {current_player}'s turn.")
        move = get_player_move()

        if make_move(board, current_player, move):
            if check_winner(board, current_player):
                display_board(board)
                print(f"Player {current_player} wins!")
                break
            elif all(all(cell != " " for cell in row) for row in board):
                display_board(board)
                print("It's a tie!")
                break
            else:
                current_player = "O" if current_player == "X" else "X"
                time.sleep(0.5)  # Add a delay for smoother transitions

if __name__ == "__main__":
    play_tic_tac_toe()
