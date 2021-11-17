#include <stdio.h>
#include "../../config/initconfig.h"

void inventory() {
  int i, input, checkJenis, kapasitasTas;
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
        case 5:
          printf("Senter Pengecil");
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
      if (!valid) {
          printf("Input tidak valid !\n");
      }
  } while (!valid);

  // Menampilkan pesan mengenai gadget yang digunakan
  if (input != 0) {
    if (isEmptyLS(boughtGadget)) { // Kasus boughtGadget kosong
      printf("Inventory kosong. Tidak ada gadget yang dapat digunakan!\n");
    } else {
        checkJenis = ELMTLS(boughtGadget,(input-1));
        switch (checkJenis) {
          case 1:
            if (TYPE(TOP(tas)) == 'P') {
              printf("Kain Pembungkus Waktu berhasil digunakan!\n");
              PICKUP_TIME(TOP(tas)) = time;
              deleteElmt(&boughtGadget, (input-1));
            } else {
              printf("Kain Pembungkus Waktu tidak dapat digunakan!\n");
            }
            break;
          case 2:
            kapasitasTas = NEFFQ(tas);
            
            if ((2 * kapasitasTas) <= STACKCAPACITY) {
              NEFFQ(tas) = 2 * kapasitasTas;
              printf("Senter Pembesar berhasil digunakan!\n");
            } else {
              NEFFQ(tas) = STACKCAPACITY;
            }
            deleteElmt(&boughtGadget, (input - 1));
            printf("Kapasitas tas sebelum: %d\n", kapasitasTas);
            printf("Kapasitas tas sesudah: %d\n", NEFFQ(tas));
            break;
          case 3:
            pintuKemanaSaja = true;
            printf("Pintu Kemana Saja berhasil digunakan!\n");
            deleteElmt(&boughtGadget, (input - 1));
            break;
          case 4:
            if (time2 > 50) {
              time2 = time2 - 50;
            } else {
              time2 = 0;
            }
            printf("Mesin Waktu berhasil digunakan!\n");
            deleteElmt(&boughtGadget, (input - 1));
            break;
          case 5:
            if (TYPE(TOP(tas)) == 'H') {
              senterPengecil = true;
              printf("Senter Pembesar berhasil digunakan!\n");
              deleteElmt(&boughtGadget, (input - 1));
            } else {
              printf("Senter Pembesar tidak dapat digunakan!\n");
            }
            break;
          case -999:
            printf("Tidak ada gadget yang dapat digunakan pada slot ini!\n");
          default:
            break;
        }
    }
  }
}