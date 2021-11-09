#include "../../ADT/stack.c"
#include "../../config/initconfig.h"
#include <stdio.h>

int main(){
    // COMMAND: DROP_OFF
    Barang temp;
    int paid;
    
    // Syarat pengantaran barang adalah barang harus diantar pada lokasi yang sesuai
    if (DROPOFF_LOC(TOP(tas)) == NAME(currentPosition)){ 
        switch(TYPE(temp)){
            pop(&tas, &temp); 
            case 1:
                printf("Pesanan Normal Item berhasil diantarkan\n");
                paid = 200;
                break;
            case 2:
                printf("Pesanan Heavy Item berhasil diantarkan\n");
                paid = 400; 
                // ability: speed boost
                isSpeedBoostActive = true;
                saatnyaTambahWaktu = false;
                sisaLokasi = 10;
                break;
            case 3:
                printf("Pesanan Perishable Item berhasil diantarkan\n");
                paid = 400;
                // ability: increase capacity
                EFF(tas)+=1;
                break;
            default:
                break;
        }
        balance += paid;
        printf("Uang yang didapatkan: %d Yen", paid); // tambah balance
        
    } else {
        printf("Tidak ada pesanan yang dapat diantarkan!\n");
    }

    return 0;
}
