#include <stdio.h>
#include <string.h>
#define MAX_PINJOL 100

typedef struct
{
    char nama[50];
    char alamat[100];
    char telp[20];
    float pinjaman;
    float bunga;
    float tagihan;
} Pinjol;

void tambahTagihan(Pinjol *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        p[i].tagihan += 500000;
    }
}

void kurangTagihan(Pinjol *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        p[i].tagihan -= 500000;
    }
}