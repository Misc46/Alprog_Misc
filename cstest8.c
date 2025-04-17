#include <stdio.h>
#include <string.h>

#define MAX 1000

typedef struct
{
    char jenis[10];
    int nilai;
} Kartu;

// Custom priority
const char *urutanJenis[] = {"Spade", "Heart", "Club", "Diamond"};
const int jumlahJenis = 4;

// Custom index finder
int getJenisIndex(const char *jenis)
{
    for (int i = 0; i < jumlahJenis; i++)
    {
        if (strcmp(jenis, urutanJenis[i]) == 0)
            return i;
    }
    return jumlahJenis; // no match? -> paling akhir
}

// Bubble sort jenis -> nilai
void sortByJenis(Kartu kartu[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            int a = getJenisIndex(kartu[j].jenis);
            int b = getJenisIndex(kartu[j + 1].jenis);

            if (a > b || (a == b && kartu[j].nilai < kartu[j + 1].nilai))
            {
                Kartu temp = kartu[j];
                kartu[j] = kartu[j + 1];
                kartu[j + 1] = temp;
            }
        }
    }
}

// Bubble nilai -> jenis
void sortByNilai(Kartu kartu[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (kartu[j].nilai < kartu[j + 1].nilai ||
                (kartu[j].nilai == kartu[j + 1].nilai &&
                 getJenisIndex(kartu[j].jenis) > getJenisIndex(kartu[j + 1].jenis)))
            {
                Kartu temp = kartu[j];
                kartu[j] = kartu[j + 1];
                kartu[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n, pilihan;
    Kartu kartu[MAX];

    printf("Jumlah Kartu: ");
    scanf("%d", &n);
    getchar(); // Clean buffer

    printf("Urutkan berdasarkan: 1. Jenis 2. Nilai\n");
    scanf("%d", &pilihan);

    for (int i = 0; i < n; i++)
    {
        scanf("%s %d", kartu[i].jenis, &kartu[i].nilai);
    }

    if (pilihan == 1)
        sortByJenis(kartu, n);
    else
        sortByNilai(kartu, n);

    for (int i = 0; i < n; i++)
    {
        printf("%s %d\n", kartu[i].jenis, kartu[i].nilai);
    }

    return 0;
}