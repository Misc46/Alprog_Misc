// PUNYA MISC JANGAN DI KOPAS - GUNAKAN SEBAGAI REFERENSI SAJA
// Shifting Encryption
#include <stdio.h>
#include <string.h>

void shiftEncrypt(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = str[i] + 1;
    }
}

int main()
{
    char hero[5][10] = {"gusion", "fanny", "yin", "johnson", "nana"};
    for (int i = 0; i < 5; i++)
    {
        shiftEncrypt(hero[i]);
        printf("Hero %d: %s\n", i + 1, hero[i]);
    }
    return 0;
}