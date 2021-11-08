#include "config/config.c"
#include "lib/commandParser/commandParser.c"

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
    } else if (isCommandEqual("LOAD GAME")) {
        printf("LOAD GAME\n");
    } else if (isCommandEqual("EXIT")) {
        printf("EXIT\n");
    }
    return 0;
}