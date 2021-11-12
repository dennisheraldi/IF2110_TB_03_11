#include <stdio.h>
#include "../../config/initconfig.h"
#include "../commandParser/commandParser.h"

void tambahWaktu(){
    if(jumlahHeavyDiTas>0){
        time+=(1+jumlahHeavyDiTas);
    } else if(isSpeedBoostActive){
        if(saatnyaTambahWaktu){
            time++;
            sisaLokasi--;
            saatnyaTambahWaktu=false;
        }else{
            saatnyaTambahWaktu=true;
            sisaLokasi--;
        }
        if(sisaLokasi==0){
            isSpeedBoostActive=false;
        }
    }else{
        time++;
    }
    //cek apakah ada perishable items yang hangus
}

void move(){
    //KAMUS
    int i,nomor,j,counter,input;
    boolean found, valid;
    Bangunan reachable[100];
    //ALGORITMA
    //cetak posisi yang dapat dicapai
    printf("Posisi yang dapat dicapai:\n");
    //mendapatkan nomor baris di adjacency matrix
    if(EQ(LOCATION(HQ),LOCATION(currentPosition))){
        nomor=0;
    } else {
        i=0;
        found=false;
        while(!found && isIdxValidLD(buildings,i)){
            if(EQ(LOCATION(currentPosition),LOCATION(ELMTLD(buildings,i)))){
                found=true;
                nomor=i+1;
            } else {
                i++;
            }
        }
    }
    //cek adjacency matrix lalu cetak bila dapat diakses
    j=0;
    counter=1;
    for(i=0;isIdxEffM(adjacency,nomor,j);j++){
        if(ELMT(adjacency,nomor,j)==1){
            printf("%d. %s ", counter, NAME(ELMTLD(buildings,i)));
            TulisPOINT(LOCATION(ELMTLD(buildings,i)));
            printf("\n");
            counter++;
            reachable[counter-1]=ELMTLD(buildings,i);
        }
    }
    //meminta input lokasi mana yang ingin dikunjungi
    printf("Posisi yang dipilih? (ketik 0 jika ingin kembali)\n");
    do{
        printf("ENTER COMMAND: ");
        getCommand();
        input=command[0]-'0';
        valid= ((input<=counter) && (0<input));
        if(!valid){
            printf("Input tidak valid !\n");
        }
    } while(!valid);
    currentPosition = reachable[input-1];
    tambahWaktu();
    printf("Mobita sekarang berada di titik %s ", NAME(currentPosition));
    TulisPOINT(LOCATION(currentPosition));
    printf("!\n");
}