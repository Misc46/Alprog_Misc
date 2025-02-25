#include <stdio.h>
#include <stdlib.h>

void topTriangleAddition(int r, int c, float matrix[r][c])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (j > i)
            {
                matrix[i][j] += 0.3;
            }
        }
    }
}

void botTriangleSubtraction(int r, int c, float matrix[r][c])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i > j)
            {
                matrix[i][j] -= 0.2;
            }
        }
    }
}

void diaMultiply(int r, int c, float matrix[r][c])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i == j)
            {
                matrix[i][j] = matrix[i][j] * 2;
            }
        }
    }
}

void transMatrix(int r, int c, float matrix[r][c])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = i + 1; j < c; j++)
        {
            float temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

void inputMatrix(int r, int c, float matrix[r][c])
{
    for (int i = 0; i < r; i++)
    {
        printf("Masukkan elemen untuk baris %d (pisahkan dengan spasi): ", i + 1);
        for (int j = 0; j < c; j++)
        {
            scanf("%f", &matrix[i][j]);
        }
    }
}

void printMatrix(int r, int c, float matrix[r][c])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int size;
    printf("Tolong input ukuran matriks persegi yang di inginkan: ");
    scanf("%d", &size);
    int r = size;
    int c = size;
    float matrix[r][c];
    inputMatrix(r, c, matrix);
    topTriangleAddition(r, c, matrix);
    botTriangleSubtraction(r, c, matrix);
    diaMultiply(r, c, matrix);
    transMatrix(r, c, matrix);
    printMatrix(r, c, matrix);

    return 0;
}