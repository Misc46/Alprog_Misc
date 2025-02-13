#include <stdio.h>
#include <math.h>

int main()
{
    int num1, num2, opt, res;
    printf("========== Selamat Datang di Kalkulator! ========== \n");

    while (1)
    {
        printf("Pilih Operasi Yang Ingin Anda Lakukan:\n1. Penjumlahan\n2. Pengurangan\n3. Perkalian\n4. Pembagian\n5. Pangkat\n6. Keluar\nKetik 1-6 untuk pilih: ");
        scanf("%d", &opt);
        if (opt <= 6 && opt >= 1)
        {
            if (opt == 6)
            {
                printf("\n========== TERIMAKASIH TELAH MENGGUNAKAN KALKULATOR ==========");
                exit(0);
            }

            break;
        }
        else
        {
            printf("Input Tidak Valid. Silahkan Coba Lagi\n");
        }
    }
    printf("Ketik Angka Pertama: \n");
    scanf("%d", &num1);
    printf("Ketik Angka Kedua: \n");
    scanf("%d", &num2);
    if (opt == 1)
    {
        res = num1 + num2;
        printf("Hasil Dari Penjumlahan %d dan %d adalah %d", num1, num2, res);
    }
    else if (opt == 2)
    {
        res = num1 - num2;
        printf("Hasil Dari Pengurangan %d dan %d adalah %d", num1, num2, res);
    }
    else if (opt == 3)
    {
        res = num1 * num2;
        printf("Hasil Dari Perkalian %d dan %d adalah %d", num1, num2, res);
    }
    else if (opt == 4)
    {
        res = num1 / num2;
        printf("Hasil Dari Pembagian %d dan %d adalah %d", num1, num2, res);
    }
    else if (opt == 5)
    {
        for (int i = 0; i < num2; i++)
        {
            res = pow(num1, num2);
        }
        printf("Hasil Dari %d pangkat %d adalah %d", num1, num2, res);
    }
    if (res >= 1)
    {
        while (1)
        {
            printf("\nApakah anda ingin membuat gambar dari output? \n1. Yes \n2. No \n");
            scanf("%d", &opt);
            if (opt <= 2 && opt >= 1)
            { // Gambar

                int i, j;
                res = res + 2;
                for (i = 0; i < res; i++)
                {
                    if (i == 0 || i == res - 1)
                    {
                        for (j = 0; j <= res - 3; j++)
                        {
                            printf("*");
                        }
                        printf("\n");
                    }
                    else
                    {
                        printf("*\n");
                    }
                }
                break;
            }
            else
            {
                printf("Input Tidak Valid. Silahkan Coba Lagi\n");
            }
        }
    }
    else
    {
        printf("\n========== TERIMAKASIH TELAH MENGGUNAKAN KALKULATOR ==========");
        exit(0);
    }
}