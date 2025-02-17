// PUNYA MISC JANGAN DI KOPAS
// Perkalian Matriks (Alternate)
#include <stdio.h>

void inputMatrix(int row, int col, int matrix[row][col])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void multiplyMatrix(int a[2][2], int b[2][2], int result[2][2])
{
    result[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
    result[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1];
    result[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0];
    result[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1];
}

int main()
{
    int matrix1[2][2], matrix2[2][2], result[2][2];
    printf("Input matrix 1:\n");
    inputMatrix(2, 2, matrix1);
    printf("Input matrix 2:\n");
    inputMatrix(2, 2, matrix2);
    multiplyMatrix(matrix1, matrix2, result);
    printf("Hasil perkalian:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}