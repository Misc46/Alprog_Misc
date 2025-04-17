---
title: Pembahasan CS7 Selasa

---

---

title: Pembahasan CS7 Alprog Selasa

---

# Pembahasan CS7 Alprog Selasa
> Author: Misc/Dwi  
> Waktu pengerjaan ~30 menit

## Pendekatan:
Di CS7 ini, kita diminta membuat program untuk mengurutkan kartu dengan format `[Jenis] [Nilai]` berdasarkan kriteria pilihan user, yakni **berdasarkan jenis** atau **berdasarkan nilai**. Kita juga diminta menerapkan sistem prioritas custom untuk jenis kartu (Spade, Heart, Club, Diamond).

Program ini cocok ditangani dengan pendekatan struct untuk menyimpan data kartu, dan bubble sort untuk sorting sederhana berdasarkan dua kriteria tersebut.

---

## Struktur Data

Struktur data yang digunakan sangat sederhana:
```c
typedef struct {
    char jenis[10];
    int nilai;
} Kartu;
```
Struct `Kartu` menyimpan dua field: jenis (nama suit/kartu) dan nilai (angka kartu). Misal: `Spade 11`.

---

## Fungsi getJenisIndex

Fungsi ini penting karena kita menggunakan **urutan prioritas custom** untuk jenis kartu:
```c
const char *urutanJenis[] = {"Spade", "Heart", "Club", "Diamond"};
```

Fungsi `getJenisIndex()` mengembalikan indeks jenis yang cocok dengan array urutan tersebut. Jika tidak cocok, akan dikembalikan nilai terbesar (`jumlahJenis`) agar ditempatkan paling akhir.
```c
int getJenisIndex(const char *jenis) {
    for (int i = 0; i < jumlahJenis; i++) {
        if (strcmp(jenis, urutanJenis[i]) == 0)
            return i;
    }
    return jumlahJenis;
}
```

---

## Fungsi Sort

### Sort Berdasarkan Jenis
Urutkan terlebih dahulu berdasarkan jenis menggunakan `getJenisIndex()`. Jika jenis sama, urutkan berdasarkan **nilai menurun**.
```c
void sortByJenis(Kartu kartu[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            int a = getJenisIndex(kartu[j].jenis);
            int b = getJenisIndex(kartu[j + 1].jenis);

            if (a > b || (a == b && kartu[j].nilai < kartu[j + 1].nilai)) {
                Kartu temp = kartu[j];
                kartu[j] = kartu[j + 1];
                kartu[j + 1] = temp;
            }
        }
    }
}
```

### Sort Berdasarkan Nilai
Jika user memilih sorting berdasarkan nilai, maka nilai lebih tinggi didahulukan. Jika nilai sama, urutkan jenis menggunakan indeks prioritas.
```c
void sortByNilai(Kartu kartu[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (kartu[j].nilai < kartu[j + 1].nilai ||
                (kartu[j].nilai == kartu[j + 1].nilai &&
                 getJenisIndex(kartu[j].jenis) > getJenisIndex(kartu[j + 1].jenis))) {
                Kartu temp = kartu[j];
                kartu[j] = kartu[j + 1];
                kartu[j + 1] = temp;
            }
        }
    }
}
```

---

## Fungsi Main

Di sini, kita membaca jumlah kartu, pilihan pengurutan, dan data setiap kartu. Setelah itu, kita panggil fungsi sort sesuai pilihan.
```c
int main() {
    int n, pilihan;
    Kartu kartu[MAX];

    printf("Jumlah Kartu: ");
    scanf("%d", &n);
    getchar(); // Membersihkan buffer

    printf("Urutkan berdasarkan: 1. Jenis 2. Nilai\n");
    scanf("%d", &pilihan);

    for (int i = 0; i < n; i++) {
        scanf("%s %d", kartu[i].jenis, &kartu[i].nilai);
    }

    if (pilihan == 1)
        sortByJenis(kartu, n);
    else
        sortByNilai(kartu, n);

    for (int i = 0; i < n; i++) {
        printf("%s %d\n", kartu[i].jenis, kartu[i].nilai);
    }

    return 0;
}
```

---

## Full Code:
```c
#include <stdio.h>
#include <string.h>

#define MAX 1000

typedef struct {
    char jenis[10];
    int nilai;
} Kartu;

const char *urutanJenis[] = {"Spade", "Heart", "Club", "Diamond"};
const int jumlahJenis = 4;

int getJenisIndex(const char *jenis) {
    for (int i = 0; i < jumlahJenis; i++) {
        if (strcmp(jenis, urutanJenis[i]) == 0)
            return i;
    }
    return jumlahJenis;
}

void sortByJenis(Kartu kartu[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            int a = getJenisIndex(kartu[j].jenis);
            int b = getJenisIndex(kartu[j + 1].jenis);
            if (a > b || (a == b && kartu[j].nilai < kartu[j + 1].nilai)) {
                Kartu temp = kartu[j];
                kartu[j] = kartu[j + 1];
                kartu[j + 1] = temp;
            }
        }
    }
}

void sortByNilai(Kartu kartu[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (kartu[j].nilai < kartu[j + 1].nilai ||
                (kartu[j].nilai == kartu[j + 1].nilai &&
                 getJenisIndex(kartu[j].jenis) > getJenisIndex(kartu[j + 1].jenis))) {
                Kartu temp = kartu[j];
                kartu[j] = kartu[j + 1];
                kartu[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, pilihan;
    Kartu kartu[MAX];

    printf("Jumlah Kartu: ");
    scanf("%d", &n);
    getchar();

    printf("Urutkan berdasarkan: 1. Jenis 2. Nilai\n");
    scanf("%d", &pilihan);

    for (int i = 0; i < n; i++) {
        scanf("%s %d", kartu[i].jenis, &kartu[i].nilai);
    }

    if (pilihan == 1)
        sortByJenis(kartu, n);
    else
        sortByNilai(kartu, n);

    for (int i = 0; i < n; i++) {
        printf("%s %d\n", kartu[i].jenis, kartu[i].nilai);
    }

    return 0;
}
```

---

## Terima Kasih!
Semoga membantu dan selamat mengerjakan CS7! 🎴🃏