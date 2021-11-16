//#include "../../ADT/stack.c"
#include "../../config/initconfig.h"
//#include <stdio.h>

int drop_off(){
    // COMMAND: DROP_OFF
    Barang temp;
    int paid;
    
    // Syarat pengantaran barang adalah barang harus diantar pada lokasi yang sesuai
    if (DROPOFF_LOC(TOP(tas)) == NAME(currentPosition)){ 
        pop(&tas, &temp); 
        //printf("%c",TYPE(temp));
        switch(TYPE(temp)){
            case 'N':
                printf("Pesanan Normal Item berhasil diantarkan\n");
                paid = 200;
                break;
            case 'H':
                printf("Pesanan Heavy Item berhasil diantarkan\n");
                paid = 400; 
                jumlahHeavyDiTas--;
                // ability: speed boost
                isSpeedBoostActive = true;
                saatnyaTambahWaktu = false;
                sisaLokasi = 10;
                break;
            case 'P':
                printf("Pesanan Perishable Item berhasil diantarkan\n");
                paid = 400;
                // ability: increase capacity
                NEFFQ(tas)+=1;
                break;
            default:
                break;
        }
        deleteFirst(&inProgress,&temp);
        balance += paid;
        printf("Uang yang didapatkan: %d Yen\n", paid); // tambah balance
        
    } else {
        printf("Tidak ada pesanan yang dapat diantarkan!\n");
    }

    return 0;
}
