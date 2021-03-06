#include "config/config.h"
#include "config/config_save.h"
#include "config/config_load.h"
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
int counterPesanan;

int main() {
    boolean end, finish, exit;
    finish = false;
    end = false;
    exit = false;
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
        while (!validateFileNameNew()) {
            printStringRed("\nNama file tidak valid! (Tidak ada di dalam folder penyimpanan). Masukkan ulang nama file!\n");
            printf("Masukkan nama file: ");
            getCommand();
        }
        printf("\n");
        printStringGreen("Loading game...\n");
        config();
        printStringGreen("Game Started\n\n");
        while(!end){
            printf("\n");
            printStringYellow("Posisi");printf(": %c ", NAME(currentPosition));
            TulisPOINT(LOCATION(currentPosition));
            printf(" | ");printStringGreen("Uang"); printf(": %d\n", balance);
            printStringCyan("Waktu");printf(": %d | ", time2);
            printStringRed("Pesanan");printf(": %d | ", length(antrian));
            printStringBlue("Tas"); printf(": %d\n", length(inProgress));
            printf("ENTER COMMAND: ");
            getCommand();
            printf("\n");
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
                printf("Masukkan nama file: ");
                getCommand();
                while (!cekEktensiTXT()) {
                    printStringRed("\nNama file tidak valid! Nama file harus valid dengan ekstensi '.txt'.\n");
                    printf("Masukkan nama file: ");
                    getCommand();
                }
                config_save();
                printStringGreen("\nFile tersimpan!\n\n");
            }else if(isCommandEqual("RETURN")){
                return_to_sender();
            }else if(isCommandEqual("EXIT")){
                exit = true;
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
        printf("Masukkan nama file: ");
        getCommand();
        while (!validateFileNameLoad()) {
            printStringRed("\nNama file tidak valid! (Tidak ada di dalam folder penyimpanan). Masukkan ulang nama file!\n");
            printf("Masukkan nama file: ");
            getCommand();
        }
        printf("\n");
        printStringGreen("Loading game...\n");
        config_load();
        printStringGreen("Game Started\n\n");
        while(!end){
            printf("\n");
            printStringYellow("Posisi");printf(": %c ", NAME(currentPosition));
            TulisPOINT(LOCATION(currentPosition));
            printf(" | ");printStringGreen("Uang"); printf(": %d\n", balance);
            printStringCyan("Waktu");printf(": %d | ", time2);
            printStringRed("Pesanan");printf(": %d | ", length(antrian));
            printStringBlue("Tas"); printf(": %d\n", length(inProgress));
            printf("ENTER COMMAND: ");
            getCommand();
            printf("\n");
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
                printf("Masukkan nama file: ");
                getCommand();
                while (!cekEktensiTXT()) {
                    printStringRed("\nNama file tidak valid! Nama file harus valid dengan ekstensi '.txt'.\n");
                    printf("Masukkan nama file: ");
                    getCommand();
                }
                config_save();
                printStringGreen("\nFile tersimpan!\n\n");
            }else if(isCommandEqual("RETURN")){
                return_to_sender();
            }else if(isCommandEqual("EXIT")){
                exit = true;
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
    } else if (isCommandEqual("EXIT")) {
        printf("EXIT\n");
    }
    return 0;
}