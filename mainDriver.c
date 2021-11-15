#include "config/config.h"
#include "lib/commandParser/commandParser.h"

int time;
int balance;
Stack tas;
Matrix map;
Matrix adjacency;
Bangunan currentPosition;
Bangunan HQ;
char command[20];
int commandLen;
ListDin buildings;
PrioQueue antrianPesanan;
int jumlahHeavyDiTas;
boolean saatnyaTambahWaktu;
boolean isSpeedBoostActive;
int sisaLokasi;
ListLinked inProgress;
List boughtGadget;
ListLinked antrian;

int main() {
    config("game1.txt");
    printf("MENU UTAMA\n");
    printf("Tentukan aksi yang mau dilakukan!\n");
    printf("- NEW GAME\n");
    printf("- LOAD GAME\n");
    printf("- EXIT\n");
    printf("Masukkan pilihan aksi: ");
    getCommand();
    if (isCommandEqual("NEW GAME")) {
        printf("NEW GAME\n");
        //displayMatrix(adjacency);
        // printf("\n");
        // displayMatrix(map);
        while(true){
            printf("Waktu: %d\n", time);
            printf("ENTER COMMAND: ");
            getCommand();
            if(isCommandEqual("MOVE")){
                move();
            }else if(isCommandEqual("PICK_UP")){
                pickup();
            }else if(isCommandEqual("DROP_OFF")){
                // drop_off();
            }else if(isCommandEqual("MAP")){
                displayMap();
            }else if(isCommandEqual("TO_DO")){
                displayList();
            }else if(isCommandEqual("IN_PROGRESS")){

            }else if(isCommandEqual("BUY")){
                buy();
            }else if(isCommandEqual("INVENTORY")){
                
            }else if(isCommandEqual("HELP")){
                
            }else if(isCommandEqual("SAVE_GAME")){
                
            }else if(isCommandEqual("RETURN")){
                
            }
        }
    } else if (isCommandEqual("LOAD GAME")) {
        printf("LOAD GAME\n");
    } else if (isCommandEqual("EXIT")) {
        printf("EXIT\n");
    }
    return 0;
}