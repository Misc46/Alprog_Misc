#include <stdio.h>
int main() {
    int i = 1, iterasi = 0;                     //inisialisasi 2 variabel
    while (i <= 50) {                           //sampe kurang dari 50 inklusif
        if (i % 3 == 0 && i % 5 == 0) {         //logika pake dan
            if (iterasi >= 5) {                 //cuma di print kalo iterasi 5 keatas aja
                printf("%d ", i);   
            }
            iterasi++;                          //iterasi ditambah cuma ketika ketemu angkanya
        }
        i++;                                    // i ditambah ketika loopnya jalan
    }
    printf("\n");               //gak ada outputnya soalnya di bawah 50 cuma ada 15 30 45, di skip semua
    return 0;
}