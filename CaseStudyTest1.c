#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int num1, num2, cfg, res;
    printf("========== Selamat Datang di Kalkulator! ==========\nSilahkan memberikan Input \nAngka 1: ");
    scanf("%d", &num1);
    printf("Angka 2: ");
    scanf("%d", &num2);
    while (1)
    {
        printf("Operasi apa yang akan anda lakukan kepada %d dan %d?\n", num1, num2);
        printf("1. Penjumlahan \n2. Pengurangan\n3. Perkalian\n4. Pembagian\n5. Modulo\n6. Pangkat\nOperasi: ");
        scanf("%d", &cfg);
        if (cfg <= 6 && cfg >= 1)
        {
            if (cfg == 1)
            {
                res = num1 + num2;
                printf("Hasilnya: %d", res);
            }
            else if (cfg == 2)
            {
                res = num1 - num2;
                printf("Hasilnya: %d", res);
            }
            else if (cfg == 3)
            {
                res = num1 * num2;
                printf("Hasilnya: %d", res);
            }
            else if (cfg == 4)
            {
                res = num1 / num2;
                printf("Hasilnya: %d", res);
            }
            else if (cfg == 5)
            {
                res = num1 % num2;
                printf("Hasilnya: %d", res);
            }
            else if (cfg == 6)
            {
                int i;
                for (i = 0; i < num2; i++)
                {
                    res = num1 * num1;
                }
                printf("Hasilnya: %d", res);
            }
            break;
        }
        else
        {
            printf("Pilihan tidak valid. Silahka coba lagi\n");
        }
    }

    if (res >= 1)
    {
        while (1)
        {
            printf("\nApakah anda ingin mencetak gambar piramid? \n1. Yes \n2. No \nPilih: ");
            scanf("%d", &cfg);
            if (cfg <= 2 && cfg > 0)
            {
                if (cfg == 1)
                {
                    // Tree function

                    int i, j;
                    for (i = 0; i <= res; i++)
                    {
                        if (i == res - 1)
                        {
                            for (j = 0; j < i; j++)
                            {
                                printf("*");
                            }
                        }
                        else
                        {
                            printf("*\n");
                        }
                    }
                    printf("========== Terimakasih Telah Menggunakan Kalkulator ==========");
                    break;
                }
                else if (cfg == 2)
                {
                    printf("========== Terimakasih Telah Menggunakan Kalkulator ==========");
                    return 0;
                    exit(0);
                }
                break;
            }
            else
            {
                printf("Pilihan tidak valid. Silahka coba lagi");
            }
        }
    }
    else
    {
        printf("========== Terimakasih Telah Menggunakan Kalkulator ==========");
        return 0;
        exit(0);
    }
}
