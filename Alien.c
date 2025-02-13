#include <stdio.h>
int main() {
    int t, k, r;
    printf("Seberapa panjang gambar alien anda: ");
    scanf("%d", &t);
    for (int row = 0; row < 2 * t - 1; row++) {                     //loop pertama
        int mid = (row < t) ? t - row - 1 : row - t + 1;            //cek udah lewat tengah apa belom 
        k = mid;                                                    //kalo udah simpen di k
        r = t - k - 1;
        for (int s = 0; s < k; s++) {
            printf(" ");
        }
        printf("*");
        for (int s = 0; s < r; s++) {
            printf(" ");
        }
        if (row > 0 && row < 2 * t - 2) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}