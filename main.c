#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3];


void initBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}


void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}


char checkWinner() {
    for (int i = 0; i < 3; i++) {

        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return board[i][0];

        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return board[0][i];
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return board[0][2];

    return ' ';
}

int isBoardFull() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return 0;
    return 1;
}


void playerMove() {
    int row, col;
    do {
        printf("Your turn (Row and Column between 1-3) : ");
        scanf("%d%d", &row, &col);
        row--; col--;
    } while (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ');
    board[row][col] = 'X';
}


void computerMove() {
    int row, col;
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] != ' ');
    board[row][col] = 'O';
}


int main() {
    char winner = ' ';
    srand(time(NULL));
    initBoard();
    printf("=== Tic-Tac-Toe Game ===\n");
    printBoard();

    while (winner == ' ' && !isBoardFull()) {
        playerMove();
        printBoard();
        winner = checkWinner();
        if (winner != ' ' || isBoardFull())
            break;

        printf("Machine_Thinking...\n");
        computerMove();
        printBoard();
        winner = checkWinner();
    }

    if (winner == 'X')
        printf("Congrats ! You've won !\n");
    else if (winner == 'O')
        printf("Owww...Sorry ! The machine has won.\n");
    else
        printf("Draw !!!\n");

    return 0;
}
