#include <stdio.h>
#include "config/initconfig.h"
#include "config/config.c"
#include "ADT/matrix.c"
#include "ADT/point.h"
#include "lib/commandParser/commandParser.c"

int time;
Matrix map;
Matrix adjacency;
POINT currentPosition;
char command[50];
int commandLen;

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