#include "config/config.h"
#include "config/config_save.h"
#include "config/initconfig.h"

int time;
int time2;
int balance;
int pesananSelesai;
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
boolean pintuKemanaSaja;
boolean senterPengecil;
int sisaLokasi;
ListLinked inProgress;
List boughtGadget;
ListLinked antrian;
ListLinked savedBarang;
int simpingTime;
int returnCounter;

int main() {
    boolean end, finish;
    finish = false;
    end = false;
    printf("MENU UTAMA\n");
    printf("Tentukan aksi yang mau dilakukan!\n");
    printf("- NEW GAME\n");
    printf("- LOAD GAME\n");
    printf("- EXIT\n");
    printf("Masukkan pilihan aksi: ");
    getCommand();
    if (isCommandEqual("NEW GAME")) {
        printf("Masukkan nama file: ");
        getCommand();
        while (!validateFileName()) {
            printStringRed("\nNama file tidak valid! (Tidak ada di dalam folder penyimpanan). Masukkan ulang nama file!\n");
            printf("Masukkan nama file: ");
            getCommand();
        }
        printf("\n");
        printStringGreen("Loading game...\n");
        config();
        config_save();
        printStringGreen("Game Started\n\n");
        while(!end){
            printf("Waktu: %d\n", time2);
            printf("Uang: %d Yen\n", balance);
            printf("ENTER COMMAND: ");
            getCommand();
            if(isCommandEqual("MOVE")){
                move();
            }else if(isCommandEqual("PICK_UP")){
                pickup();
            }else if(isCommandEqual("DROP_OFF")){
                drop_off();
            }else if(isCommandEqual("MAP")){
                displayMap();
            }else if(isCommandEqual("TO_DO")){
                displayList();
            }else if(isCommandEqual("IN_PROGRESS")){
                displayInProgress();
            }else if(isCommandEqual("BUY")){
                buy();
            }else if(isCommandEqual("INVENTORY")){
                inventory();
            }else if(isCommandEqual("HELP")){
                help();
            }else if(isCommandEqual("SAVE_GAME")){
                
            }else if(isCommandEqual("RETURN")){
                return_to_sender();
            }else if(isCommandEqual("EXIT")){
                break;
            }
            if (!finish && isEmptyPrio(antrianPesanan) && isEmptyS(tas) && isEmpty(antrian)) {
                printf("\nSelamat, Anda telah berhasil menyelesaikan game! Silakan kembali ke Headquarrters untuk melihat skor Anda.\n\n"); 
                finish = true;   
            }
            if (finish && NAME(currentPosition) == '8') {
                end = true;
            } 
        }
        if (end && finish) {
            printf("\nSelamat, Anda berhasil mengantar semua barang!\nTotal Barang yang Anda antar\t: %d\nWaktu yang Anda butuhkan\t: %d\n\n", pesananSelesai, time2);
        }
    } else if (isCommandEqual("LOAD GAME")) {
        printf("LOAD GAME\n");
    } else if (isCommandEqual("EXIT")) {
        printf("EXIT\n");
    }
    return 0;
}