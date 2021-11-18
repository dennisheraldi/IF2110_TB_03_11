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
                printf("Reward ability Speed Boost berhasil didapatkan dan diaktifkan\n");
                printf("Waktu hanya bertambah 1 unit ketika kamu berpindah 2 lokasi \n");
                jumlahHeavyDiTas--;
                if (senterPengecil) {
                    senterPengecil = false;
                }
                // ability: speed boost
                isSpeedBoostActive = true;
                saatnyaTambahWaktu = false;
                sisaLokasi = 10;
                break;
            case 'P':
                printf("Pesanan Perishable Item berhasil diantarkan\n");
                paid = 400;
                // ability: increase capacity
                printf("Reward ability Increase Capacity berhasil didapatkan dan diaktifkan\n");
                printf("Kapasitas tas bertambah 1\n");
                printf("Kapasitas tas sebelum: %d\n", NEFFQ(tas));
                NEFFQ(tas)+=1;
                printf("Kapasitas tas sesudah: %d\n", NEFFQ(tas));
                break;
            case 'V':
                printf("Pesanan Shizuka berhasil diantar <3\n");
                printf("Reward ability Return to Sender berhasil didapatkan\n");
                paid = 600;
                simpingTime--;
                returnCounter++;
            default:
                break;
        }
        pesananSelesai++;
        deleteFirst(&inProgress,&temp);
        balance += paid;
        printf("Uang yang didapatkan: %d Yen\n", paid); // tambah balance
        
    } else {
        printf("Tidak ada pesanan yang dapat diantarkan!\n");
    }

    return 0;
}
