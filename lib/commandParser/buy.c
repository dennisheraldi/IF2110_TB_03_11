#include <stdio.h>
#include "../../ADT/listdin.c"
#include "../../config/initconfig.h"

void buy(){

    CreateListLS(&boughtGadget); // Inisialisasi inventory
    int pilihan;

    // Menampilkan list gadget yang dapat dibeli
    printf("Uang Anda sekarang: %d Yen\n", balance);
    printf("Gadget yang tersedia:\n");
    printf("1. Kain Pembungkus Waktu (800 Yen)\n");
    printf("2. Senter Pembesar (1200 Yen)\n");
    printf("3. Pintu Kemana Saja (1500 Yen)\n");
    printf("4. Mesin Waktu (3000 Yen)\n");
    printf("Gadget mana yang ingin kau beli? (ketik 0 jika ingin kembali)\n");
    printf("ENTER COMMAND: "); scanf("%d", &pilihan);
    
    if (isFullLS(boughtGadget)){
        printf("Inventory penuh, tidak dapat membeli gadget.\n");
    } else {
        if (pilihan == 0){
            // keluar
        } else if ((pilihan == 1 && balance >= 800) || (pilihan == 2 && balance >= 1200) ||
        (pilihan == 3 && balance >= 1500) || (pilihan == 4 && balance >= 3000)) {
                ELMTLS(boughtGadget, (indexOfLS(boughtGadget, -999))) = pilihan;
                switch (pilihan) {
                    case 1: 
                        printf("Kain Pembungkus Waktu berhasil dibeli!\n");
                        balance -= 800;
                        printf("Uang anda sekarang: %d", balance);
                        break;
                    case 2:
                        printf("Senter Pembesar berhasil dibeli!\n");
                        balance -= 1200;
                        printf("Uang anda sekarang: %d", balance);
                        break;
                    case 3:
                        printf("Pintu Kemana Saja berhasil dibeli!\n");
                        balance -= 1500;
                        printf("Uang anda sekarang: %d", balance);
                        break;
                    case 4: 
                        printf("Mesin Waktu berhasil dibeli!\n");
                        balance -= 3000;
                        printf("Uang anda sekarang: %d", balance);
                        break;
                    default:
                        break;
                }
                
        } else {
            printf("Uang tidak cukup untuk membeli gadget!\n");
        }
 
    }
}