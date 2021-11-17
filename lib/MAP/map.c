//#include <stdio.h>
//#include "../../ADT/pcolor.h"
#include "../../config/initconfig.h"

boolean searchPickUp(char name) {
    boolean found;
    int i, len;
    len = length(antrian);
    found = false;
    i = 0;
    while (!found && i < len) {
        if (PICKUP_LOC(getElmt(antrian, i)) == name) {
            found = true;
        }
        i++;
    }
    return found;
}

boolean isAdjacent(char name) {
    boolean found, adjacent;
    int i, len, idxCurPOs, idxChar;
    len = lengthLD(buildings);
    found = false;
    i = 0;
    while (!found && i < len) {
        if (NAME(ELMTLD(buildings, i)) == NAME(currentPosition)) {
            found = true;
        }
        i++;
    }
    idxCurPOs = i - 1;
    found = false;
    i = 0;
     while (!found && i < len) {
        if (NAME(ELMTLD(buildings, i)) == name) {
            found = true;
        }
        i++;
    }
    idxChar = i - 1;
    return (ELMT(adjacency, idxCurPOs, idxChar) == 1);
}

void displayMap()
{  
    int i, j;
    for (j = 0; j < COLS(map) + 2; j++) {
        printf("*");
        if (j != COLS(map) + 1) {
            printf(" ");
        }
    }
    printf("\n");
    for (i = 0; i < ROWS(map); i++) {
        printf("* ");
        for (j = 0; j < COLS(map); j++) {
            if (ELMT(map, i, j) == 8) {
                if (NAME(currentPosition) == '8') {
                    print_yellow('8');
                } else if (!isEmptyS(tas) && DROPOFF_LOC(TOP(tas)) == '8'){
                    print_blue('8');
                } else if (!isEmpty(antrian) && searchPickUp('8')) {
                    print_red('8');
                } 
                else if (!isEmptyLD(buildings) && isAdjacent('8')) {
                    print_green('8');
                } 
                else {
                    printf("%d", 8);
                }
            } else if (ELMT(map, i, j) > 8) {
                if (NAME(currentPosition) == ELMT(map, i, j)) {
                    print_yellow(NAME(currentPosition));
                } else if (!isEmptyS(tas) && DROPOFF_LOC(TOP(tas)) == (char)ELMT(map, i, j)){
                    print_blue(DROPOFF_LOC(TOP(tas)));
                } else if (!isEmpty(antrian) && searchPickUp((char)ELMT(map, i, j))) {
                    print_red((char)ELMT(map, i, j));
                } 
                else if (!isEmptyLD(buildings) && isAdjacent((char)ELMT(map, i, j))) {
                    print_green((char)ELMT(map, i, j));
                } 
                else {
                    printf("%c", ELMT(map, i, j));
                }
            } else {
                printf(" ");
            }
            printf(" ");
        }
        printf("*\n");
    }
    for (j = 0; j < COLS(map) + 2; j++) {
        printf("*");
        if (j != COLS(map) + 1) {
            printf(" ");
        }
    }
    printf("\n");
}

