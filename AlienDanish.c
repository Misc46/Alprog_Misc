#include <stdio.h>
int main()
{
    int input, i, j;
    printf("Type an integer: ");
    scanf("%d", &input);
    for (i = 0; i <= 2 * input - 1; i++)
    { // vertikal
        // horizontal
        if (input != 1 && i == 0 || i == 2 * input - 1)
        { // untuk bagian paling atas & bawah
            for (j = 0; j < input - 1; j++)
            {
                printf(" ");
            }
            printf("*\n");
        }
        if (i > 1 && i <= input)
        { // atas s.d. tengah
            for (j = i; j < input; j++)
            {
                printf(" ");
            }
            printf("*");
            for (j = 0; j < i - 1; j++)
            {
                printf(" ");
            }
            printf("*\n");
        }
        if (i > input && i < 2 * input - 1)
        { // tengah s.d. bawah
            for (j = 0; j < i - input; j++)
            {
                printf(" ");
            }
            printf("*");
            for (j = i; j < 2 * input - 1; j++)
            {
                printf(" ");
            }
            printf("*\n");
        }
    }
}