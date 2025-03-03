#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void fungsi1(int x, int y, int z, int *A)
{
    *A = (x * x * x) + (8 * y * y) - (z * z) + 10;
}

void fungsi2(int x, int y, int z, int *B)
{
    *B = round(0.5 * x * y * z);
}

void fungsi3(int x, int y, int z, int *C)
{
    *C = round(sqrt((x * x) + (y * y) + (z * z)));
}

int main()
{
    int x, y, z, A, B, C;
    printf("PR Machine\n");
    printf("Halo Upin & Ipin (dah besar)!\n");
    printf("Masukkan X: ");
    scanf("%d", &x);
    printf("Masukkan Y: ");
    scanf("%d", &y);
    printf("Masukkan Z: ");
    scanf("%d", &z);

    fungsi1(x, y, z, &A);
    fungsi2(x, y, z, &B);
    fungsi3(x, y, z, &C);

    printf("\nA: %d + %d - %d + 10 = %d\n", x * x * x, 8 * y * y, z * z, A);
    printf("B: 1/2 x %d x %d x %d = %d", x, y, z, B);
    if (B < 0)
    {
        printf(" (Tidak memungkinkan!)\n");
    }
    else
    {
        printf("\n");
    }
    printf("C: SQRT(%d + %d + %d) = %d\n", x * x, y * y, z * z, C);
    return 0;
}
