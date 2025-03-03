#include <stdio.h>
#include <stdlib.h>

void shiftCipher(char *str, int shift)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        char ch = str[i];
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
        {
            char shifted = ch + shift;
            if (!((shifted >= 'A' && shifted <= 'Z') || (shifted >= 'a' && shifted <= 'z')))
            {
                printf("Out of bounds!\n");
                exit(0);
            }
            str[i] = shifted;
        }
    }
}

void encrypt(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == 'A' || str[i] == 'a')
            str[i] = '4';
        else if (str[i] == 'E' || str[i] == 'e')
            str[i] = '3';
        else if (str[i] == 'I' || str[i] == 'i')
            str[i] = '1';
        else if (str[i] == 'O' || str[i] == 'o')
            str[i] = '0';
        else if (str[i] == 'U' || str[i] == 'u')
            str[i] = 'V';
    }
}

int main()
{
    char str[100];
    int shift;
    printf("Masukkan String: ");
    scanf("%99[^\n]", str);
    printf("Masukkan Jarak Geser: ");
    scanf("%d", &shift);
    shiftCipher(str, shift);
    encrypt(str);
    printf("String Cipher: %s\n", str);
}