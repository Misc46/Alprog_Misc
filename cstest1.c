#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

char board[SIZE][SIZE];

void initializeBoard()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void printBoard()
{
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

int checkVictory()
{
    for (int i = 0; i < SIZE; i++)
    {
        // Check rows
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
        {
            printf("\nCongratulations, %c Won the game!\n", board[i][0]);
            return 1;
        }
        // Check columns
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
        {
            printf("\nCongratulations, %c Won the game!\n", board[0][i]);
            return 1;
        }
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
    {
        printf("\nCongratulations, %c Won the game!\n", board[0][0]);
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
    {
        printf("\nCongratulations, %c Won the game!\n", board[0][2]);
        return 1;
    }
    return 0;
}

int main()
{
    initializeBoard();
    for (int i = 0; i < 9; i++)
    {
        int coordinatesRow, coordinatesCol;
        char currentPlayer = (i % 2 == 0) ? 'O' : 'X';

        printBoard();
        printf("\n%c to move, pick coordinates on board (row col): ", currentPlayer);
        scanf("%d %d", &coordinatesRow, &coordinatesCol);

        // Validate input
        if (coordinatesRow < 1 || coordinatesRow > 3 || coordinatesCol < 1 || coordinatesCol > 3 || board[coordinatesRow - 1][coordinatesCol - 1] != ' ')
        {
            printf("Invalid move! Try again.\n");
            i--; // Retry this move
            continue;
        }

        board[coordinatesRow - 1][coordinatesCol - 1] = currentPlayer;

        if (checkVictory())
        {
            printBoard();
            return 0;
        }
    }

    printBoard();
    printf("\nIt's a draw!\n");
    return 0;
}
