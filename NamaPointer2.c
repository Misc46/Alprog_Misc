#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hitungASCII(char *nama, int *hasil) {
    *hasil = 0;
    for (int i = 0; nama[i] != '\0'; i++) {
        *hasil += (int)nama[i];
    }
}

void gantiNama(char **nama) {
    printf("\nMasukkan nama baru:\n\n");
    scanf("%s", *nama);
    
    *nama = (char *)realloc(*nama, (strlen(*nama) + 1) * sizeof(char));
    if (*nama == NULL) {
        printf("Gagal mengalokasikan memori!\n");
        exit(1);
    }
}

int main() {
    char *nama = (char *)malloc(100 * sizeof(char));
    if (nama == NULL) {
        printf("Gagal mengalokasikan memori!\n");
        return 1;
    }

    printf("Masukkan nama Anda:\n\n");
    scanf("%s", nama);

    char pilihan;
    while (1) {
        printf("\nOpsi (Nama: %s):\n", nama);
        printf("a. Value ASCII Nama\nb. Ganti Nama\nc. Exit\n\n");
        scanf(" %c", &pilihan);

        switch (pilihan) {
            case 'a': {
                int nilaiASCII;
                hitungASCII(nama, &nilaiASCII);
                printf("\nValue nama Anda adalah %d\n", nilaiASCII);
                break;
            }
            case 'b':
                gantiNama(&nama);
                break;
            case 'c':
                printf("\nProgram Selesai!\n");
                free(nama);
                return 0;
            default:
                printf("\nPilihan tidak valid!\n");
        }
    }
}