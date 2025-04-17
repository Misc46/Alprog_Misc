#include <stdio.h>
#include <string.h>

//DI SOAL GAK SPECIFY HARUS CASE INSENSITIVE mmf yah

struct Kontak {
    char nama[100];
    char nomorTelepon[15];
};

void cariKontak(struct Kontak kontak[], int jumlah, char *kataKunci){
    int ditemukan = 0;
    for (int i = 0; i < jumlah; i++) {
        if (strstr(kontak[i].nama, kataKunci) || strstr(kontak[i].nomorTelepon, kataKunci)) {
            printf("%d, Nama: %s, Nomor Telepon: %s\n", ditemukan + 1, kontak[i].nama, kontak[i].nomorTelepon);
            ditemukan = 1;
        }
    }

    if (ditemukan == 0){
        printf("Tidak ada kontak yang ditemukan dengan kata kunci %s", kataKunci);
    }
}

int main() {
    struct Kontak kontak[10];
    int n;
    char key[100];

    printf("Masukkan jumlah kontak: ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        printf("Masukkan nama kontak %d: ", i+1);
        fgets(kontak[i].nama, sizeof(kontak[i].nama), stdin);
        strtok(kontak[i].nama, "\n");

        printf("Masukkan nomor telepon kontak %d: ", i+1);
        fgets(kontak[i].nomorTelepon, sizeof(kontak[i].nomorTelepon), stdin);
        strtok(kontak[i].nomorTelepon, "\n");
    }

    printf("\nMasukkan kata Kunci: ");
    fgets(key, sizeof(key), stdin);
    strtok(key, "\n");

    printf("\nKontak found: \n");
    cariKontak(kontak, n, key);

    return 0;
}