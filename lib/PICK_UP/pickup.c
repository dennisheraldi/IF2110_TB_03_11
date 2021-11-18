#include <stdio.h>
#include "../../config/initconfig.h"

void hapusDariAntrian(Barang b){
    Barang temp;
    int i=0;
    int panjang=length(antrian);
    boolean found=false;
    while((i<panjang) && (!found)){
        if(EQBarang(getElmt(antrian,i),b)){
            found=true;
            deleteAt(&antrian,i,&temp);
        }else{
            i++;
        }
    }
}

void pickup(){
    Barang temp;
    int indeks;
    //printf("isi tas %d %d", length(inProgress),NEFFQ(tas));
    if (simpingTime > 0) {
        if(length(inProgress)<NEFFQ(tas)){
            if(isEmptyQ(ANTREAN(currentPosition))){
                printf("Pesanan tidak ditemukan!\n");
            }else{
                indeks=indexOfLD(buildings,NAME(currentPosition));
                if(indeks!=IDX_UNDEF){
                    if (TYPE(HEAD(ANTREAN(ELMTLD(buildings,indeks)))) == 'V') {
                        dequeue(&ANTREAN(ELMTLD(buildings,indeks)),&temp);
                        PICKUP_TIME(temp)=time;
                        push(&tas,temp);
                        insertFirst(&inProgress,temp);
                        printf("Pesanan berupa VIP Item berhasil diambil!\n");
                        printf("Tujuan Pesanan: %c\n", DROPOFF_LOC(temp));
                        hapusDariAntrian(temp);
                    } else {
                        printf("\nMaaf, sebagai simp yang baik kamu harus segera mengantarkan item Shizuka ke rumahnya.\n\n");

                    }
                }
            }
        } else {
            printf("Tas penuh !\n");
        }
    } else {
        if(length(inProgress)<NEFFQ(tas)){
            if(isEmptyQ(ANTREAN(currentPosition))){
                printf("Pesanan tidak ditemukan!\n");
            }else{
                indeks=indexOfLD(buildings,NAME(currentPosition));
                if(indeks!=IDX_UNDEF){
                    dequeue(&ANTREAN(ELMTLD(buildings,indeks)),&temp);
                    PICKUP_TIME(temp)=time;
                    push(&tas,temp);
                    insertFirst(&inProgress,temp);
                    if(TYPE(temp)=='P'){
                        printf("Pesanan berupa Perishable Item berhasil diambil!\n");
                    }else if(TYPE(temp)=='N'){
                        printf("Pesanan berupa Normal Item berhasil diambil!\n");
                    } else if(TYPE(temp)=='H'){
                        printf("Pesanan berupa Heavy Item berhasil diambil!\n");
                        jumlahHeavyDiTas++;
                        isSpeedBoostActive=false; //Ability speed boost hilang
                        sisaLokasi=0;
                        saatnyaTambahWaktu=false;
                    }
                    printf("Tujuan Pesanan: %c\n", DROPOFF_LOC(temp));
                    hapusDariAntrian(temp);
                }
            }
        }else{
            printf("Tas penuh !\n");
        }
    }
}