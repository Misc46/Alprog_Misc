#include <stdio.h>
#include <string.h>

typedef struct
{
    char jenis[20];
    char nilai[10];
} Kartu;

// Set up custom priority
const char *prioJenis[] = {"Sekop", "Hati", "Keriting", "Wajik"};
const char *prioVal[] = {"As", "King", "Queen", "Jack", "10", "9", "8", "7", "6", "5", "4", "3", "2"};
const int nJenis = 4;
const int nVal = 13;

// Find Prio Indexing
int indexVal(const char *nilai)
{
    for (int i = 0; i < nVal; i++)
    {
        if (strcmp(nilai, prioVal[i]) == 0)
        {
            return i;
        }
    }
    return nVal;
}

int indexType(const char *jenis)
{
    for (int i = 0; i < nJenis; i++)
    {
        if (strcmp(jenis, prioJenis[i]) == 0)
        {
            return i;
        }
    }
    return nJenis;
}

// Custom Indexed Prio sort (bubble)
void sortByType(Kartu kartu[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            int a = indexType(kartu[j].jenis);
            int b = indexType(kartu[j + 1].jenis);
            if (a > b || (a == b && indexVal(kartu[j].nilai) > indexVal(kartu[j + 1].nilai)))
            {
                Kartu temp = kartu[j];
                kartu[j] = kartu[j + 1];
                kartu[j + 1] = temp;
            }
        }
    }
}

void sortByVal(Kartu kartu[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            int a = indexVal(kartu[j].jenis);
            int b = indexVal(kartu[j + 1].jenis);
            if (a > b || (a == b && indexType(kartu[j].nilai) > indexType(kartu[j + 1].nilai)))
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
    int n, opt;
    Kartu kartu[1000];

    printf("Jumlah kartu: ");
    scanf("%d", &n);
    getchar();

    printf("Sort by: 1. Type 2. Value\n");
    scanf("%d", &opt);
    getchar();

    for (int i = 0; i < n; i++)
    {
        printf("Input kartu: (Type) (value)\n");
        scanf("%s %s", kartu[i].jenis, kartu[i].nilai);
    }
    if (opt == 1)
    {
        sortByType(kartu, n);
    }
    else
    {
        sortByVal(kartu, n);
    }

    printf("\nHasil Setelah di Sortir adalah:\n\n");

    for (int i = 0; i < n; i++)
    {
        printf("%s %s\n", kartu[i].jenis, kartu[i].nilai);
    }
}