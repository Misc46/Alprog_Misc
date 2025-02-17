#include <stdio.h>
#include <stdlib.h>

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

void multiplyMatrix(int r1, int c1, int r2, int c2, int a[r1][c1], int b[r2][c2], int result[r1][c2])
{
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++)
            {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main()
{
    int r1, c1, r2, c2;

    printf("Masukkan ukuran matriks pertama (baris kolom): ");
    scanf("%d %d", &r1, &c1);
    printf("Masukkan ukuran matriks kedua (baris kolom): ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2)
    {
        printf("Matriks tidak dapat dikalikan! Jumlah kolom matriks pertama harus sama dengan jumlah baris matriks kedua.\n");
        return 1;
    }

    int matrix1[r1][c1], matrix2[r2][c2], result[r1][c2];

    printf("Input matriks pertama:\n");
    inputMatrix(r1, c1, matrix1);

    printf("Input matriks kedua:\n");
    inputMatrix(r2, c2, matrix2);

    multiplyMatrix(r1, c1, r2, c2, matrix1, matrix2, result);

    printf("Hasil perkalian:\n");
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
