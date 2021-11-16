#include <stdio.h>
#include "../../config/initconfig.h"

void displayInProgress() {
  Address p;
  int count;
  
  // Inisialisasi
  p = FIRST(inProgress);
  count = 1;

  // Menampilkan isi list inProgress
  while (p != NULL) {
    printf("%d. ", count);
    // Mengecek tipe barang
    if (TYPE(INFO(p)) == 'N') {
      printf("Normal Item ");
    } else if (TYPE(INFO(p)) == 'H') {
      printf("Heavy Item ");
    } else if (TYPE(INFO(p)) == 'P') {
      printf("Perishable Item ");
    }

    // Menampilkan drop-off location
    printf("(Tujuan: %c)", DROPOFF_LOC(INFO(p)));
    printf("\n");

    p = NEXT(p);
    count++;
  }
}