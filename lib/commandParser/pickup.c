#include <stdio.h>
#include "../../ADT/bangunan.h"
#include "../../ADT/queue.h"
#include "../../ADT/barang.h"
#include "../../ADT/stack.h"

void pickup(){
    Barang temp;
    if(isEmpty(ANTREAN(currentPosition))){
        printf("Pesanan tidak ditemukan!\n");
    }else{
        dequeue(&ANTREAN(currentPosition),&temp);
        push(&tas,temp);
        if(TYPE(temp)=='p'){
            printf("Pesanan berupa Perishable Item berhasil diambil!");
        }else if(TYPE(temp)=='n'){
            printf("Pesanan berupa Normal Item berhasil diambil!");
        } else {
            printf("Pesanan berupa Heavy Item berhasil diambil!");
            sedangMembawaHeavy=true;
        }
        printf("Tujuan Pesanan: %c", DROPOFF_LOC(temp));
    }
}