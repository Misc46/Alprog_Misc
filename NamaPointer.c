#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hitungASCII(char *nama, int *hasil)
{
    *hasil = 0;
    for (int i = 0; nama[i] != '\0'; i++)
    {
        *hasil += (int)nama[i];
    }
}

void gantiNama(char **nama)
{
    char temp[100];
    printf("\nMasukkan nama baru:\n\n");
    scanf("%99s", temp);

    *nama = (char *)realloc(*nama, (strlen(temp) + 1) * sizeof(char));
    if (*nama == NULL)
    {
        printf("Gagal mengalokasikan memori!\n");
        exit(1);
    }
    strcpy(*nama, temp);
}

int main()
{
    char *nama = (char *)malloc(100 * sizeof(char));
    if (nama == NULL)
    {
        printf("Gagal mengalokasikan memori!\n");
        return 1;
    }

    printf("Masukkan nama Anda:\n\n");
    scanf("%99s", nama);

    char pilihan;
    do
    {
        printf("\nOpsi (Nama: %s):\n", nama);
        printf("a. Value ASCII Nama\nb. Ganti Nama\nc. Exit\n\n");
        scanf(" %c", &pilihan);

        if (pilihan == 'a')
        {
            int nilaiASCII;
            hitungASCII(nama, &nilaiASCII);
            printf("\nValue nama Anda adalah %d\n", nilaiASCII);
        }
        else if (pilihan == 'b')
        {
            gantiNama(&nama);
        }
    } while (pilihan != 'c');

    printf("\nProgram Selesai!\n");
    free(nama);
    return 0;
}
