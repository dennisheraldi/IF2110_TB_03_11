#include "inventory.h"

void inventory() {
    int i;
    for (i = 0; i < 5; i++) {
        printf("%d. ", i + 1);
        if (i < lengthLS(boughtGadget)) {
            switch (ELMTLS(boughtGadget, i)) {
                case 1:
                    printf("Kain Pembungkus Waktu\n");
                    break;
                case 2:
                    printf("Senter Pembesar\n");
                    break;
                case 3:
                    printf("Pintu Kemana Saja\n");
                    break;
                case 4:
                    printf("Kain Pembungkus Waktu\n");
                    break;
                case 5:
                    printf("Mesin Waktu");
                    break;
                default:
                    break;
            }
        } else {
            printf("-\n");
        }
    }
    printf("Gadget mana yang ingin digunakan? (ketik 0 jika ingin kembali)\n\n");
    printf("ENTER COMMAND: ");
    getCommand();
    
}