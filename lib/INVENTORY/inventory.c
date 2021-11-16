#include "../../config/initconfig.h"

void inventory() {
  int i, pilihan;
  
  // Menampilkan isi inventory
  for (i = 0; i < LISTCAPACITY; i++) {
    printf("%d. ", i + 1);
    if (isEmptyLS(boughtGadget)) { // Jika boughtGadget kosong, artinya kelima slot inventory kosong
      printf("-");
    } else { // boughtGadget tidak kosong, maka tampilkan isi list 
      if (ELMTLS(boughtGadget, i) == 1) {
        printf("Kain Pembungkus Waktu");
      } else if (ELMTLS(boughtGadget, i) == 2) {
        printf("Senter Pembesar");
      } else if (ELMTLS(boughtGadget, i) == 3) {
        printf("Pintu Kemana Saja");
      } else { // ELMTLS(boughtGadget, i) == 4
        printf("Mesin Waktu");
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
    if (pilihan == 1) {
      printf("Kain Pembungkus Waktu");
    } else if (pilihan == 2) {
      printf("Senter Pembesar");
    } else if (pilihan == 3) {
      printf("Pintu Kemana Saja");
    } else { // pilihan == 4
      printf("Mesin Waktu");
    }
    printf(" berhasil digunakan!\n");
  }
}