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
    switch (TYPE(INFO(p))) {
      case 'N':
        printf("Normal Item ");
        break;
      case 'H':
        printf("Heavy Item ");
        break;
      case 'P':
        printf("Perishable Item ");
        break;
      case 'V':
        printf("VIP Item ");
        break;
      default:
        break;
    }

    // Menampilkan drop-off location
    printf("(Tujuan: %c)", DROPOFF_LOC(INFO(p)));
    printf("\n");

    p = NEXT(p);
    count++;
  }
}