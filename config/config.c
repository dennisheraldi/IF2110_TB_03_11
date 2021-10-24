#include <stdio.h>
#include "initconfig.h"
#include "../ADT/tokenmachine.c"
#include "../ADT/point.c"

void config() {
    int row, col, i, j, counter, val;
    time = 0;
    startToken();
    row = currentToken.val;
    advToken();
    col = currentToken.val;
    CreateMatrix(row, col, &map);
    i = j = 0;
    while (isIdxEffM(map, i, j)) {
        while (isIdxEffM(map, i, j)) {
            ELMT(map, i, j) = 0;
            j++;
        }
        j = 0;
        i++;
    }
    advToken();
    row = currentToken.val;
    advToken();
    col = currentToken.val;
    currentPosition =  MakePOINT(row, col);
    ELMT(map, row - 1, col - 1) = 8;
    advToken();
    counter = currentToken.val;
    for (i = 0; i < counter; i++) {
        advToken();
        val = currentToken.tkn;
        advToken();
        row = currentToken.val;
        advToken();
        col = currentToken.val;
        ELMT(map, row - 1, col - 1) = val;
    }
    CreateMatrix(counter + 1, counter + 1, &adjacency);
    i = j = 0;
    while (isIdxEffM(adjacency, i, j)) {
        while (isIdxEffM(adjacency, i, j)) {
            advToken();
            ELMT(adjacency, i, j) = currentToken.val;
            j++;
        }
        j = 0;
        i++;
    }
}

void displayMap() {
    int i, j;
    for (j = 0; j < COLS(map) + 2; j++) {
        printf("* ");
    }
    printf("\n");
    for (i = 0; i < ROWS(map); i++) {
        printf("* ");
        for (j = 0; j < COLS(map); j++) {
            if (ELMT(map, i, j) > 8) {
                printf("%c", ELMT(map, i, j));
            } else if (ELMT(map, i, j) == 8) {
                printf("%d", ELMT(map, i, j));
            } else {
                printf(" ");
            }
            if(j != COLS(map) - 1) {
                printf(" ");
            }
        }
        printf(" *");
        printf("\n");

    }
    for (j = 0; j < COLS(map) + 2; j++) {
        printf("* ");
    }
}