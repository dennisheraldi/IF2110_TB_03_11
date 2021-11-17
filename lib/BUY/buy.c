#include <stdio.h>
#include "../../config/initconfig.h"

void buy(){

    int input;
    boolean valid;
    if (NAME(currentPosition) == '8') {
            // Menampilkan list gadget yang dapat dibeli
        printf("Uang Anda sekarang: %d Yen\n", balance);
        printf("Gadget yang tersedia:\n");
        printf("1. Kain Pembungkus Waktu (800 Yen)\n");
        printf("2. Senter Pembesar (1200 Yen)\n");
        printf("3. Pintu Kemana Saja (1500 Yen)\n");
        printf("4. Mesin Waktu (3000 Yen)\n");
        printf("5. Senter Pengecil (800 Yen)\n");
        printf("Gadget mana yang ingin kau beli? (ketik 0 jika ingin kembali)\n");
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
        if (input != 0) {
            if (isFullLS(boughtGadget)){
            printf("Inventory penuh, tidak dapat membeli gadget.\n");
            } else {
                if (input == 0){
                    // keluar
                } else if ((input == 1 && balance >= 800) || (input == 2 && balance >= 1200) 
                || (input == 3 && balance >= 1500) || (input == 4 && balance >= 3000) 
                || (input == 5 && balance >= 800)) {
                        insertElmt(&boughtGadget, input);
                        switch (input) {
                            case 1: 
                                printf("Kain Pembungkus Waktu berhasil dibeli!\n");
                                balance -= 800;
                                printf("Uang anda sekarang: %d\n", balance);
                                break;
                            case 2:
                                printf("Senter Pembesar berhasil dibeli!\n");
                                balance -= 1200;
                                printf("Uang anda sekarang: %d\n", balance);
                                break;
                            case 3:
                                printf("Pintu Kemana Saja berhasil dibeli!\n");
                                balance -= 1500;
                                printf("Uang anda sekarang: %d\n", balance);
                                break;
                            case 4: 
                                printf("Mesin Waktu berhasil dibeli!\n");
                                balance -= 3000;
                                printf("Uang anda sekarang: %d\n", balance);
                                break;
                            case 5:
                                printf("Senter Pengecil berhasil dibeli!\n");
                                balance -= 800;
                                printf("Uang anda sekarang: %d\n", balance);
                                break;
                            default:
                                break;
                        }
                        
                } else {
                    printf("Uang tidak cukup untuk membeli gadget!\n");
                }
            }
        }
    } else {
        printf("Command BUY hanya dapat dipanggil di Headquaters!\n");
    }

    
    
}