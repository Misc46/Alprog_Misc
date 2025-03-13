#include <stdio.h>
#include <string.h>

typedef struct
{
    char nama[50];
    char jabatan[50];
    float gaji;
    float imunitas;
    char status[20];
} Karyawan;

void updateImunitas(Karyawan *p)
{
    if (p->imunitas > 90)
    {
        strcpy(p->status, "Sehat");
    }
    else if (p->imunitas > 70)
    {
        strcpy(p->status, "Batuk-Batuk");
    }
    else if (p->imunitas > 50)
    {
        strcpy(p->status, "Tepar");
    }
    else if (p->imunitas > 20)
    {
        strcpy(p->status, "Sekarat");
    }
    else
    {
        strcpy(p->status, "Wassalam");
        strcpy(p->jabatan, "Tiada");
        p->gaji = 0;
        p->imunitas = 0;
    }
}

void hitungImunitas(Karyawan *karyawan, int n, int *week) // Pass week as a pointer
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(karyawan[i].status, "Wassalam") != 0)
        {
            karyawan[i].imunitas *= (karyawan[i].imunitas / 100);
            updateImunitas(&karyawan[i]);
        }
    }
    (*week)++; // Increment the original week
}

void tampilkanDatabase(Karyawan *karyawan, int n)
{
    printf("\nDatabase Karyawan\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("Karyawan %d\n", i + 1);
        printf("Nama - Jabatan : %s - %s\n", karyawan[i].nama, karyawan[i].jabatan);
        printf("Gaji : Rp%.0f\n", karyawan[i].gaji);
        printf("Imunitas : %.2f%%\n", karyawan[i].imunitas);
        printf("Status : %s\n\n", karyawan[i].status);
    }
}

int main()
{
    int jumlah;
    printf("Jumlah Karyawan: ");
    scanf("%d", &jumlah);
    getchar(); // Membersihkan newline setelah scanf || CRS Karena ini

    Karyawan karyawan[jumlah];

    for (int i = 0; i < jumlah; i++)
    {
        printf("\nNama Karyawan %d: ", i + 1);
        fgets(karyawan[i].nama, sizeof(karyawan[i].nama), stdin);
        karyawan[i].nama[strcspn(karyawan[i].nama, "\n")] = '\0';

        printf("Jabatan Karyawan %d: ", i + 1);
        fgets(karyawan[i].jabatan, sizeof(karyawan[i].jabatan), stdin);
        karyawan[i].jabatan[strcspn(karyawan[i].jabatan, "\n")] = '\0';

        printf("Gaji Karyawan %d: ", i + 1);
        scanf("%f", &karyawan[i].gaji);
        getchar(); // Membersihkan newline setelah scanf

        printf("Imunitas Karyawan %d: ", i + 1);
        scanf("%f", &karyawan[i].imunitas);
        getchar(); // Membersihkan newline setelah scanf

        updateImunitas(&karyawan[i]);
    }
    int week = 0;
    while (1)
    {
        
        tampilkanDatabase(karyawan, jumlah);
        printf("\nEnd of week %d\n", week + 1);

        printf("a. Skip 1 Minggu\nb. Exit Program\n\nPilihan: ");
        char pilihan;
        scanf(" %c", &pilihan);

        if (pilihan == 'a')
        {
            hitungImunitas(karyawan, jumlah, &week);
        }
        else if (pilihan == 'b')
        {
            printf("\nProgram Selesai!\n");
            break;
        }
        else
        {
            printf("\nInput tidak valid, coba lagi.\n");
        }
    }

    return 0;
}
