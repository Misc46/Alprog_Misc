#include <stdio.h>

int main() {
   int hitungan = 0;
   for (int j = 1; j <= 50; j++) {
       if(j % 5 == 0 && j % 3 == 0 && hitungan > 5) {
       printf("%d ", j);
       }
   }
   printf(" \n");
   return 0;
}