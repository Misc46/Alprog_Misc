#include <stdio.h>

void switchOdd(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (i % 2 == 1)
        {
            char temp = str[i - 1];
            str[i - 1] = str[i];
            str[i] = temp;
        }
    }
}

int main()
{
    char test[100];
    printf("Halo Upin & Ipin (dah besar)!\n");
    printf("Masukkan String: ");
    scanf("%[^\n]s", test);
    printf("\n---\n \n");
    switchOdd(test);
    printf("String Terbalik: %s", test);
}