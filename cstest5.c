#include <stdio.h>

#define MAX_PEMINJAM 100

typedef struct
{
    char nama[50];
    char alamat[100];
    char telp[20];
    float pinjaman;
    float rate_bunga;
    float tagihan;
    char status[10];
} Peminjam;

void hitungTagihan(Peminjam *p)
{
    p->tagihan = p->tagihan * (1 + p->rate_bunga);

    if (p->tagihan < 2000000)
        sprintf(p->status, "Tunggu");
    else if (p->tagihan < 4000000)
        sprintf(p->status, "Telpon");
    else if (p->tagihan < 6000000)
        sprintf(p->status, "Buru");
    else
        sprintf(p->status, "Eksekusi");
}

void tampilkanDatabase(Peminjam peminjam[], int jumlah)
{
    printf("\nDatabase Pinjol\n\n");
    for (int i = 0; i < jumlah; i++)
    {
        printf("Peminjam %d\n", i + 1);
        printf("Nama - Alamat : %s - %s\n", peminjam[i].nama, peminjam[i].alamat);
        printf("Telp: %s\n", peminjam[i].telp);
        printf("Pinjaman - Rate Bunga : Rp%.0f - %.0f%%\n", peminjam[i].pinjaman, peminjam[i].rate_bunga * 100);
        printf("Tagihan Bulan Ini : Rp%.0f\n", peminjam[i].tagihan);
        printf("Status : %s\n\n", peminjam[i].status);
    }
}

int main()
{
    int n;
    char pilihan;

    printf("Jumlah Peminjam : ");
    scanf("%d", &n);
    getchar();

    Peminjam peminjam[MAX_PEMINJAM];

    for (int i = 0; i < n; i++)
    {
        printf("\nNama Peminjam %d : ", i + 1);
        fgets(peminjam[i].nama, 50, stdin);
        peminjam[i].nama[strcspn(peminjam[i].nama, "\n")] = 0;

        printf("Alamat Peminjam %d : ", i + 1);
        fgets(peminjam[i].alamat, 100, stdin);
        peminjam[i].alamat[strcspn(peminjam[i].alamat, "\n")] = 0;

        printf("No Telp Peminjam %d : ", i + 1);
        fgets(peminjam[i].telp, 20, stdin);
        peminjam[i].telp[strcspn(peminjam[i].telp, "\n")] = 0;

        printf("Pinjaman Peminjam %d : ", i + 1);
        scanf("%f", &peminjam[i].pinjaman);

        printf("Rate Bunga Peminjam %d : ", i + 1);
        scanf("%f", &peminjam[i].rate_bunga);
        getchar();

        peminjam[i].tagihan = peminjam[i].pinjaman;
        hitungTagihan(&peminjam[i]);
    }

    printf("\n---\n");

    while (1)
    {
        tampilkanDatabase(peminjam, n);
        printf("a. Skip 1 Bulan\nb. Exit Program\n\n");
        scanf(" %c", &pilihan);
        getchar();

        if (pilihan == 'b')
        {
            printf("\nProgram Selesai!\n");
            break;
        }

        for (int i = 0; i < n; i++)
        {
            hitungTagihan(&peminjam[i]);
        }
    }

    return 0;
}
