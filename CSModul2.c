#include <stdio.h>

float finalDet;

void det(float matrix[3][3])
{
  /*float det1 = matrix[0][0] * matrix[1][1] * matrix[2][2];
    float det2 = matrix[0][1] * matrix[1][2] * matrix[2][0];
    float det3 = matrix[0][2] * matrix[1][0] * matrix[2][1];
    float det4 = matrix[2][0] * matrix[1][1] * matrix[0][2];
    float det5 = matrix[2][1] * matrix[1][2] * matrix[0][0];
    float det6 = matrix[2][2] * matrix[1][0] * matrix[0][1];
    finalDet = det1 + det2 + det3 - det4 - det5 - det6; */ 

  //Made redundant by code below:

    float sum1 = 0;
    float sum2 = 0;
    for(int i = 0; i < 3; i++){
        sum1 += matrix[0][i] * matrix[1][(i+1)%3] * matrix[2][(i+2)%3];
        sum2 += matrix[2][i] * matrix[1][(i+1)%3] * matrix[0][(i+2)%3];
    }
    finalDet = sum1 - sum2;

    printf("Determinan matrixnya adalah: %.2f\n", finalDet);
}

void transpose(float matrix[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            float temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

void print(float matrix[3][3]){
    printf("Matrixmu setelah ditranspose adalah: \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%.1f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void operasi(float matrix[3][3], float finalDet){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            float temp = matrix[i][j] / finalDet;
            matrix[i][j] = temp;
        }
    }
}

int main()
{
    float matrix[3][3] = {
        {2, 1, 1},
        {3, 2, 1},
        {1, 1, 2}};
    transpose(matrix);
    det(matrix);
    operasi(matrix, finalDet);
    print(matrix);
}