#include <stdio.h>
#include "../../ADT/list.h"
#include "../../ADT/boolean.h"
#include "../../ADT/matrix.h"

void tambahWaktu(){
    if(sedangMembawaHeavy){

    } else if(speedboost){

    }else{
        time++;
    }
}

void move(){
    //KAMUS
    int i,nomor,j,counter,input;
    boolean found, valid;
    Bangunan reachable[100];
    //ALGORITMA
    //cetak posisi yang dapat dicapai
    printf("Posisi yang dapat dicapai:\n")
    //mendapatkan nomor baris di adjacency matrix
    if(EQ(HQ,currentPosition)){
        nomor=0;
    } else {
        i=0;
        found=false;
        while(!found && isIdxValidLS(listBangunan,i)){
            if(EQ(currentPosition,LOKASI(listBangunan[i]))){
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
            printf("%d. %s ", counter, NAMA(listBangunan[j]));
            TulisPOINT(LOKASI(listBangunan[j]));
            printf("\n");
            counter++;
            reachable[counter-1]=listBangunan[j];
        }
    }
    //meminta input lokasi mana yang ingin dikunjungi
    printf("Posisi yang dipilih? (ketik 0 jika ingin kembali)");
    do{
        printf("ENTER COMMAND: ")
        getCommand();
        input=command[0]-'0';
        valid= ((input<counter) && (0<input));
        if(!valid){
            printf("Input tidak valid !\n");
        }
    } while(!valid);
    currentPosition = reachable[input-1];
    tambahWaktu();
    printf("Mobita sekarang berada di titik %s ", NAMA(currentPosition));
    TulisPOINT(LOKASI(currentPosition));
    printf("!\n");
}