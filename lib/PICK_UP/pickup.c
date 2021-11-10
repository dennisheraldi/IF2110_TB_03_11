#include <stdio.h>
#include "../../config/initconfig.h"

void pickup(){
    Barang temp;
    if(length(inProgress)<NEFFQ(tas)){
        if(isEmptyQ(ANTREAN(currentPosition))){
            printf("Pesanan tidak ditemukan!\n");
        }else{
            dequeue(&ANTREAN(currentPosition),&temp);
            PICKUP_TIME(temp)=time;
            push(&tas,temp);
            insertLast(&inProgress,temp);
            if(TYPE(temp)=='p'){
                printf("Pesanan berupa Perishable Item berhasil diambil!\n");
            }else if(TYPE(temp)=='n'){
                printf("Pesanan berupa Normal Item berhasil diambil!\n");
            } else {
                printf("Pesanan berupa Heavy Item berhasil diambil!\n");
                jumlahHeavyDiTas++;
                isSpeedBoostActive=false; //Ability speed boost hilang
                sisaLokasi=0;
                saatnyaTambahWaktu=false;
            }
            printf("Tujuan Pesanan: %c\n", DROPOFF_LOC(temp));
        }
    }else{
        printf("Tas penuh !\n");
    }
}