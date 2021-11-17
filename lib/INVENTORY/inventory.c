#include <stdio.h>
#include "../../config/initconfig.h"

void inventory() {
  int i,input, checkJenis;
  boolean valid;
  
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
        case -999:
          printf("-");
          break;
        default:
          break;
      }
    }
    printf("\n");
  }

  // Input dari user mengenai gadget yang ingin digunakan
  printf("Gadget mana yang ingin digunakan? (ketik 0 jika ingin kembali)\n");
  do {
      printf("ENTER COMMAND: ");
      getCommand();
      input = command[0] - '0';
      valid = ((0 <= input) && (input <= 5));
      if (!valid)
      {
          printf("Input tidak valid !\n");
      }
  } while (!valid);

  if (input!=0){
    if (isEmptyLS(boughtGadget)) { // Kasus boughtGadget kosong
      printf("Inventory kosong. Tidak ada gadget yang dapat digunakan.\n");
    } else {
        checkJenis = ELMTLS(boughtGadget,(input-1));
        switch (checkJenis) {
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
      deleteElmt(&boughtGadget, (input-1));
      printf(" berhasil digunakan!\n");
    }
  }

  // Menampilkan pesan mengenai gadget yang digunakan
  
}