#include <stdio.h>
#include "../../config/initconfig.h"

void inventory() {
  int i, pilihan;
  
  // Menampilkan isi inventory
  for (i = 0; i < LISTCAPACITY; i++) {
    printf("%d. ", i + 1);
    if (isEmptyLS(boughtGadget)) { // Jika boughtGadget kosong, artinya kelima slot inventory kosong
      printf("-");
    } else { // boughtGadget tidak kosong, maka tampilkan isi list 
      switch (ELMTLS(boughtGadget, i)) {
        case 1:
          printf("Kain Pembungkus Waktu");
          break;
        case 2:
          printf("Senter Pembesar");
          break;
        case 3:
          printf("Pintu Kemana Saja");
          break;
        case 4:
          printf("Mesin Waktu");
          break;
        default:
          break;
      }
    }
    printf("\n");
  }

  // Input dari user mengenai gadget yang ingin digunakan
  printf("Gadget mana yang ingin digunakan? (ketik 0 jika ingin kembali)\n");
  printf("ENTER COMMAND: "); scanf("%d", &pilihan);

  // Menampilkan pesan mengenai gadget yang digunakan
  if (isEmptyLS(boughtGadget)) { // Kasus boughtGadget kosong
    printf("Inventory kosong. Tidak ada gadget yang dapat digunakan.");
  } else {
      switch (pilihan) {
        case 1:
          printf("Kain Pembungkus Waktu");
          break;
        case 2:
          printf("Senter Pembesar");
          break;
        case 3:
          printf("Pintu Kemana Saja");
          break;
        case 4:
          printf("Mesin Waktu");
          break;
        default:
          break;
      }
    printf(" berhasil digunakan!\n");
  }
}