//
// Created by Efrain on 4/5/2025.
//
#include <stdio.h>

// Board array
char board[3][3];

// Initialize the board
void initializeBoard() {
    char num = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = num++;
        }
    }
}

// Display the board
void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i != 2) printf("\n---|---|---\n");
    }
    printf("\n");
}

// Check for a winner
char checkWinner() {
    // Rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]))
            return board[i][0];
        if ((board[0][i] == board[1][i] && board[1][i] == board[2][i]))
            return board[0][i];
    }

    // Diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]))
        return board[0][0];
    if ((board[0][2] == board[1][1] && board[1][1] == board[2][0]))
        return board[0][2];

    return ' ';
}

// Check if the board is full (draw)
int isDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return 0;
    return 1;
}

// Main game loop
int main() {
    char player = 'X';
    int move;
    int row, col;
    char winner = ' ';

    initializeBoard();

    while (1) {
        printBoard();
        printf("Player %c, enter your move (1-9): ", player);
        scanf("%d", &move);

        if (move < 1 || move > 9) {
            printf("Invalid move! Try again.\n");
            continue;
        }

        row = (move - 1) / 3;
        col = (move - 1) % 3;

        if (board[row][col] == 'X' || board[row][col] == 'O') {
            printf("Cell already taken! Try again.\n");
            continue;
        }

        board[row][col] = player;
        winner = checkWinner();

        if (winner != ' ') {
            printBoard();
            printf("Player %c wins!\n", winner);
            break;
        }

        if (isDraw()) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}